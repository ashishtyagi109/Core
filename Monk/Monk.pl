use v6;

role ExpressionVisitor[::Result] {
    method visitInteger (Int ) returns Result { ... }
    method visitReal    (Real) returns Result { ... }
    method visitString  (Str ) returns Result { ... }
    method visitSymbol  (Str ) returns Result { ... }
    method visitKeyword (Str ) returns Result { ... }
    method visitList    (@   ) returns Result { ... }
}

role Expression {
    method visit(ExpressionVisitor) { ... }
}

class Integer does Expression {
    has Int $.value;
    method visit(ExpressionVisitor $visitor) {
	$visitor.visitInteger($.value);
    }
}

class Real does Expression {
    has Real $.value;
    method visit(ExpressionVisitor $visitor) {
	$visitor.visitReal($.value);
    }
}

class String does Expression {
    has Str $.value;
    method visit(ExpressionVisitor $visitor) {
	$visitor.visitString($.value);
    }
}

class Symbol does Expression {
    has Str $.value;
    method visit(ExpressionVisitor $visitor) {
	$visitor.visitSymbol($.value);
    }
}

class Keyword does Expression {
    has Str $.value;
    method visit(ExpressionVisitor $visitor) {
	$visitor.visitKeyword($.value);
    }
}

class List does Expression {
    has @.list;
    method visit(ExpressionVisitor $visitor) {
	$visitor.visitList(@.list);
    }
}

grammar SExp {
    token quote   { '"'                             }
    token integer { <[ 0 .. 9 ]>+                   }
    token real    { <[ 0 .. 9 ]>* \. <[ 0 .. 9] >+  }
    token string  { <quote> <-[<quote>]>* <quote>   }
    token symbol  { <[ a .. z A .. Z ]>+ <-[ \w ]>* }
    token keyword { <symbol>\:                      }
    rule  list    { '(' <TOP>* ')' }
    rule  TOP     {
	<integer> | <real> | <string> | <symbol> | <keyword> | <list>
    }
}

class SExpActions {
    method integer ($/) { $/}
}
