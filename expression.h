#pragma once

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

class Binary : public Expr {};
class Call : public Expr {};
class Get : public Expr {};
class Grouping : public Expr {};
class Literal : public Expr {};
class Logical : public Expr {};
class Set : public Expr {};
class Super : public Expr {};
class This : public Expr {};
class Unary : public Expr {};
class Variable : public Expr {};


