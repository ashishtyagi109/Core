(use srfi-1)
(use srfi-69)

;;; HTML

;;; Documentation
(define docbook (alist->hash-table '()))

(define (document-function symbol description arguments result)
  (hash-table-set! docbook symbol
		   (alist->hash-table (list (description: . description)
					    (arguments: . arguments)
					    (result: . result)))))

;;; Set Implementation
(define (make-set elements)
  (alist->hash-table
   (fold (lambda (element alist)
	   (cons (cons element #t) alist))
	 '() elements)))

(define (set-contains? set element)
  (hash-table-exists? set element))

(define (set-union set-one set-two)
  (hash-table-merge set-one set-two))

(define (set-add set element)
  (set-union set (make-set (list element))))

;;; HTML

(define (scheme->unique-scheme context expression)
  (cond
   [(atom? expression) expression]
   [(eq (car expression) 'lambda)
    (let* [[]])]))

(define (list->cps list symbols continuation)
  (cond
   ;; Base Case: apply the continuation to our converted symbols
   [(null? list)
    (continuation (reverse symbols))]
   ;; Inductive Case: 
   [else
    (let* [[head (car list)]
	   [tail (cdr list)]]
      (scheme->cps head (lambda (symbol-value)
			  (list->cps tail (cons symbol-value symbols)
				     continuation))))]))

(define (scheme->cps expression continuation)
  (cond
   ;; Atomic expressions evaluate to themselves
   [(atom? expression)
    (continuation expression)]
   ;; Functions
   [(eq? (car expression) 'lambda)
    (let* [[arguments             (cadr  expression)]
	   [body                  (caddr expression)]
	   [continuation-argument (gensym)]
	   [cps-letrec-name       (gensym)]
	   [cps-arguments         (cons continuation-argument arguments)]
	   [cps-body              (scheme->cps
				   body
				   (lambda (body)
				     `(,continuation-argument ,body)))]]
      `(letrec [(,cps-letrec-name (lambda ,cps-arguments ,cps-body))]
	 ,(continuation cps-letrec-name)))]
   ;; Let Expressions
   ;; Applications
   [else
    (let* [[function  (car expression)]
	   [arguments (cdr expression)]
	   [return-function-name (gensym)]
	   [return-argument-name (gensym)]
	   [cps-function-name (gensym)]]
      (list->cps arguments '() (lambda (argument-names)
				 `(letrec [[,return-function-name
					    (lambda (,return-argument-name)
					      ,(continuation return-argument-name))]]
				    ,(scheme->cps function (lambda (function-name)
							     (cons function-name (cons return-function-name argument-names))))))))]))

(define (c+ c x y)
  (c (+ x y)))

(define test (scheme->cps '((lambda (x) (c+ x x)) 2)
			  identity))
(eval test)
;; (list (list eval: (eval test))
;;       (list test: test))
