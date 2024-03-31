#pragma once

class Statement;
class Expr;

// statements
class Block;
class Expression;
class Function;
class If;
class Print;
class Return;
class Var;

// expressions
class Assign;
class Binary;
class Call;
class Get;
class Grouping;
class Literal;
class Logical;
class Set;
class Super;
class This;
class Unary;
class Variable;

class Visitor {
public:
    virtual void visitVarStatement(Var* stmt) {};
    virtual void visitBlockStmt(Block* stmt) {};
    virtual void visitExpressionStmt(Expression* stmt) {};
    virtual void visitFunctionStmt(Function* stmt) {};
    virtual void visitIfStmt(If* stmt) {};
	virtual void visitPrintStatement(Print* stmt) {};
    virtual void visitReturnStmt(Return* stmt) {};
    virtual void visitVarStmt(Var* stmt) {};

    virtual void visitAssignExpr(Assign* expr) {};
    virtual void visitBinaryExpr(Binary* expr) {};
    virtual void visitCallExpr(Call* expr) {};
    virtual void visitGetExpr(Get* expr) {};
    virtual void visitGroupingExpr(Grouping* expr) {};
    virtual void visitLiteralExpr(Literal* expr) {};
    virtual void visitLogicalExpr(Logical* expr) {};
    virtual void visitSetExpr(Set* expr) {};
    virtual void visitSuperExpr(Super* expr) {};
    virtual void visitThisExpr(This* expr) {};
    virtual void visitUnaryExpr(Unary* expr) {};
    virtual void visitVariableExpr(Variable* expr) {};
};

