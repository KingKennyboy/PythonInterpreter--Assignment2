//#pragma once
//
//#include <string>
//#include <vector>
//#include <iostream>
//#include "token.h"
//#include "node.h"
//
///*
//<file>         => <lines>
//<lines>        => <line> NEWLINE <lines> | END
//<line>         => DEF <function> | IDENTIFIER EQUAL <expression> | IDENTIFIER LPAREN <arguments> RPAREN | IF <control> | <expression> | EPSILON
//<function>     => IDENTIFIER RPAREN <arguments> LPAREN COLON NEWLINE <block>
//<control>      => <boolean>: \n <block> | <boolean>: \n <block> ELSE: \n <block>
//
//<arguments>    => <expression> COMMA <arguments> | <expression>
//<block>        => INDENT <lines> DEDENT
//
//<expression>   => <equality>
//<equality>     => <conditional> AND <equality> | <conditional> OR <equality> | <conditional>
//<conditional>  => NOT <conditional> | <comparison>
//<comparison>   => <term> == <comparison> | <term> != <comparison> | <term> <= <comparison> | <term> >= <comparison> |
//		  <term> >  <comparison> | <term>  < <comparison> | <term>
//<term>	       => <factor> - <term> | <factor> + <term> | <factor>
//<factor>       => <unary> / <factor> | <unary> * <factor> | <unary>
//<unary>	       => NOT <unary> | - <unary> | <primary>
//<primary>      => NUMBER | STRING | TRUE | FALSE | NONE | IDENTIFIER(<arguments>)
//
//*/
//
//
//typedef std::vector<TokenType> TokenTypes;
//
//class Parser {
//
//public:
//	Parser(std::vector<Token> tokens) {
//		this->tokens = tokens;
//		parse();
//	}
//
//	Node* getRootNode() {
//		return root;
//	}
//
//	void printNodes() {
//		printNodeHelper(root);
//	}
//
//
//private:
//	std::vector<Token> tokens;
//	int current = 0;
//	std::vector<
//
//	Node* root;
//
//	void printNodeHelper(Node* curr) {
//		std::cout << "Operation: " << tokenNames[curr->type];
//		std::cout << ",Children: ";
//		for (Node* node : curr->children) {
//			std::cout << "\n";
//			printNodeHelper(node);
//		}
//		std::cout << "\n";
//	}
//
//	void parse() {
//		while (!isAtEnd()) {
//
//		}
//	}
//
//	void error() {
//		std::runtime_error("Error matching Token: " + tokenNames[peek().type]);
//	}
//
//	bool match(std::vector<TokenType> types) {
//		for (TokenType t : types) {
//			if (check(t)) {
//				advance();
//				return true;
//			}
//		}
//		return false;
//	}
//	bool match(TokenType type) {
//		if (check(type)) {
//			advance();
//			return true;
//		}
//		return false;
//	}
//	bool check(TokenType t) {
//		if (isAtEnd()) return false;
//		return peek().type == t;
//	}
//	Token advance() {
//		if (!isAtEnd()) current++;
//		return previous();
//	}
//	Token peek() {
//		return tokens.at(current);
//	}
//	Token peekNext() {
//		if (!(current + 1 >= tokens.size())) current++;
//		return tokens.at(current + 1);
//	}
//	Token previous() {
//		return tokens.at(current - 1);
//	}
//	bool isAtEnd() {
//		return (current >= tokens.size());
//	}
//
//};