(module functional
    (concat-left
     concat-right
     fold-left
     fold-right
     head
     map
     map-concat-left
     map-concat-right
     tail)

  (define (concat-left list fn)
    (fold-left (tail list) (head list) fn))

  (define (concat-right list fn)
    (fold-right (tail list) (head list) fn))

  (define (fold-left list seed fn)
    (if (null? list)
	seed
	(fold-left (fn seed (head list))
		   (tail list))))
  
  (define (fold-right list seed fn)
    (if (null? list)
	seed
	(fn (fold-right seed (tail list))
	    (head list))))

  (define (head list)
    (car list))

  (define (map list map-fn)
    (if (null? list)
	'()
	(cons (map-fn (head list))
	      (tail list))))

  (define (map-concat-left list concat-fn map-fn)
    (concat-left (map list map-fn) concat-fn))

  (define (map-concat-right list concat-fn map-fn)
    (concat-right (map list map-fn) concat-fn))

  (define (tail list)
    (cdr list)))

(module binary-tree
    (make-binary-tree
     binary-tree-value
     binary-tree-child-one
     binary-tree-child-two
     )
  (import scheme)
  (import functional)
  (use srfi-1)
  (use srfi-2)

  (define-record binary-tree value child-one child-two)

  (define (make-leaf value)
    (make-binary-tree value '() '()))
  
  )

(module html
    (make-html-tag
     html-tag-name
     html-tag-attributes
     html-tag-children)
  (import scheme)
  (import functional)
  (use srfi-1)
  (use srfi-69)
  
  (define-record html-tag name attributes children)

  (define (html-attribute->string attribute)
    (string-append (car attribute) "=\"" (cdr attribute) "\""))

  (define (html-attributes->string attributes)
    (letrec [[html-attributes->string
	      (lambda (attributes)
		(fold (lambda (attribute memo)
			(string-append memo " "
				       (html-attribute->string attribute)))
		      "" attributes))]]
      (if (null? attributes)
	  ""
	  (string-append (html-attribute->string (car attributes))
			 (html-attributes->string (cdr attributes))))))

  (define (html-tag->string html context))
  )

(module html-tests ()
  (import scheme)
  (import html)
  )
