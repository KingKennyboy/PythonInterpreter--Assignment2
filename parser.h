#pragma once

#include <string>
#include <vector>
#include "token.h"
#include "node.h"

/*
<file>         => <lines>
<lines>        => <line> NEWLINE <lines> | END
<line>         => DEF <function> | IDENTIFIER EQUAL <expression> | IDENTIFIER LPAREN <arguments> RPAREN | IF <control> | <expression> | EPSILON
<function>     => IDENTIFIER RPAREN <arguments> LPAREN COLON NEWLINE <block>
<control>      => <boolean>: \n <block> | <boolean>: \n <block> ELSE: \n <block>

<arguments>    => <expression> COMMA <arguments> | <expression>
<block>        => INDENT <lines> DEDENT

<expression>   => <equality>
<equality>     => <conditional> AND <equality> | <conditional> OR <equality> | <conditional>
<conditional>  => NOT <conditional> | <comparison>
<comparison>   => <term> == <comparison> | <term> != <comparison> | <term> <= <comparison> | <term> >= <comparison> |
		  <term> >  <comparison> | <term>  < <comparison> | <term>
<term>	       => <factor> - <term> | <factor> + <term> | <factor>
<factor>       => <unary> / <factor> | <unary> * <factor> | <unary>
<unary>	       => NOT <unary> | - <unary> | <primary>
<primary>      => NUMBER | STRING | TRUE | FALSE | NONE | IDENTIFIER(<arguments>)

*/


class Parser {

public:
	Parser(std::vector<Token> tokens) {
		this->tokens = tokens;
		parse();
	}

private:
	std::vector<Token> tokens;
	int current = 0;

	Node* root;

	std::vector<Node> parse() {
	}

	Node* file() {
		
	}
	Node* lines() {}
	Node* line() {}
	Node* function() {}
	Node* control() {}
	
	Node* arguments() {}
	Node* block() {}

	Node* expression() {}
	Node* equality() {}
	Node* conditional() {}
	Node* comparison() {}
	Node* term() {}
	Node* factor() {}
	Node* unary() {}
	Node* primary() {}

	bool isAtEnd() {
		return (current >= tokens.size());
	}

};