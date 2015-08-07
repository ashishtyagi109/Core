;;; Build System
(use srfi-1)
(use srfi-69)
(use posix)

(define-record context
  source-directory
  build-directory
  groups
  components
  compiler
  compiler-flags
  linker
  linker-flags)

(define default-compiler "clang++")
(define default-compiler-flags (list "-std=c++11" "-Wall" "-Wextra" "-Werror"
				     "-pedantic-errors"
				     (string-append "-I" (current-directory))))
(define default-linker "clang")
(define default-linker-flags "")

(define (context-list->hash config)
  (if (eq? (car config) 'package)
      (fold (lambda (key-value table)
	      (let [[key (car key-value)]
		    [value (cadr key-value)]]
		(hash-table-set! table key value)
		table))
	    (make-hash-table)
	    (cdr config))
      (raise "no `package` definition found in package.scm")))

(define (context-list->context context
			       source-directory)
  (let ((hash (context-list->hash context)))
    (make-context
     source-directory
     (hash-table-ref/default hash
			     build-directory:
			     (string-append (current-directory) "/build"))
     (hash-table-ref/default hash groups: '())
     (hash-table-ref/default hash components: '())
     (hash-table-ref/default hash compiler: default-compiler)
     (hash-table-ref/default hash compiler-flags: default-compiler-flags)
     (hash-table-ref/default hash linker: default-linker)
     (hash-table-ref/default hash linker-flags: default-linker-flags))))

(define (evaluate context)
  (let [[compiled-groups
	 (fold (lambda (group groups-report)
		 (let* [[group-directory
			 (string-append (context-source-directory context)
					"/" (symbol->string group))]
			[group-report
			 (compile group-directory)]]
		   (cons (cons group group-report)
			 groups-report)))
	       '()
	       (context-groups context))]
	[compiled-components
	 (fold (lambda (component components-report)
		 (let* [[file-path
			 (string-append (context-source-directory context)
					"/"
					(symbol->string component)
					".cc")]
			[object-path
			 (string-append (context-build-directory context)
					"/"
					(symbol->string component)
					".o")]
			[compilation-pid
			 (process-run (context-compiler context)
				      (append (context-compiler-flags context)
					      (list "-o" object-path
						    "-c" file-path)))]]
		   (begin
		     (process-wait compilation-pid)
		     (cons (cons component "success")
			   components-report))))
	       '()
	       (context-components context))]]
    (list (list groups: compiled-groups)
	  (list components: compiled-components))))

(define (compile directory)
  (let [[package-file-path (string-append directory "/package.scm")]]
    (if (file-exists? package-file-path)
	(evaluate (context-list->context
		   (call-with-input-file package-file-path read)
		   directory))
	(raise "No package.scm file found"))))

(compile (current-directory))
