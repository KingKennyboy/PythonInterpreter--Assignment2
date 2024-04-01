#pragma once

#include <vector>
#include <string>
#include "visitor.h"
#include "token.h"


class Expr {
public:
	virtual ~Expr() {}
	virtual void accept(Visitor* v) {};
};

class Assign : public Expr {
public:
	Token name;
	Expr value;

	Assign(Token name, Expr value) {
		this->name = name;
		this->value = value;
	}

	void accept(Visitor* v) override {
		v->visitAssignExpr(this);
	}
};

class Binary : public Expr {
public:
	Expr left;
	Token op;
	Expr right;

	Binary(Expr left, Token op, Expr right) {
		this->left = left;
		this->op = op;
		this->right = right;
	}

	void accept(Visitor* v) override {
		v->visitBinaryExpr(this);
	}
};

class Call : public Expr {
public:
	Expr callee;
	Token paren;
	std::vector<Expr> args;

	Call(Expr callee, Token paren, std::vector<Expr> args) {
		this->callee = callee;
		this->paren = paren;
		this->args = args;
	}

	void accept(Visitor* v) override {
		v->visitCallExpr(this);
	}
};

class Grouping : public Expr {
public:
	Expr expression;

	Grouping(Expr expression) {
		this->expression = expression;
	}

	void accept(Visitor* v) override {
		v->visitGroupingExpr(this);
	}
};

class Literal : public Expr {
public:
	Token type;
	std::string value;

	Literal(Token type, std::string value) {
		this->type = type;
		this->value = value;
	}

	void accept(Visitor* v) override {
		v->visitLiteralExpr(this);
	}
};

class Logical : public Expr {
public:
	Expr left;
	Token op;
	Expr right;

	Logical(Expr left, Token op, Expr right) {
		this->left = left;
		this->op = op;
		this->right = right;
	}

	void accept(Visitor* v) override {
		v->visitLogicalExpr(this);
	}
};

class Unary : public Expr {
public:
	Token op;
	Expr right;

	Unary(Token op, Expr right) {
		this->op = op;
		this->right = right;
	}

	void accept(Visitor* v) override {
		v->visitUnaryExpr(this);
	}
};

class Variable : public Expr {
public:
	Token name;

	Variable(Token name) {
		this->name = name;
	}

	void accept(Visitor* v) override{
		v->visitVariableExpr(this);
	}
};
