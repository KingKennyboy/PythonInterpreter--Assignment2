#pragma once

#include <vector>
#include "token.h"
#include "expression.h"
#include "visitor.h"

class Statement {
public:
	virtual ~Statement() {}
	virtual void accept(Visitor* v) {};
};

class Block : public Statement {
public:
	std::vector<Statement> statements;

	Block(std::vector<Statement> stmts) {
		statements = stmts;
	}

	void accept(Visitor* v) override {
		v->visitBlockStmt(this);
	}

};

class Expression : public Statement {
	Expr expr;

	Expression(Expr expr) {
		this->expr = expr;
	}

	void accept(Visitor* v) override {
		v->visitExpressionStmt(this);
	}
};

class Function : public Statement {
	Token name;
	std::vector<Token> params; 
	std::vector<Statement*> body;

	Function(Token name, std::vector<Token> params, std::vector<Statement*> body) {
		this->name = name;
		this->params = params;
		this->body = body;
	}

	void accept(Visitor* v) override {
		v->visitFunctionStmt(this);
	}
};

class If : public Statement {
	Expr condition;
	Statement thenBranch;
	Statement elseBranch;

	If(Expr condition, Statement thenBranch, Statement elseBranch) {
		this->condition = condition;
		this->thenBranch = thenBranch;
		this->elseBranch = elseBranch;
	}

	void accept(Visitor* v) override {
		v->visitIfStmt(this);
	}
};


class Print : public Statement {
public:
	Expr expr;

	Print(Expr expr) {
		this->expr = expr;
	}

	void accept(Visitor* v) override {
		v->visitPrintStatement(this);
	}
};

class Return : public Statement {
public:
	Token keyword;
	Expr value;

	Return(Token keyword, Expr value) {
		this->keyword = keyword;
		this->value = value;
	}

	void accept(Visitor* v) override {
		v->visitReturnStmt(this);
	}
};

class Var : public Statement {
public:
	Token name;
	Expr initial;

	Var(Token name, Expr initial) {
		this->name = name;
		this->initial = initial;
	}

	void accept(Visitor* v) override {
		v->visitVarStatement(this);
	}


};



