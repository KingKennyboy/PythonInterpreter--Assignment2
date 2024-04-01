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

template <class T>
class Visitor {
public:
    virtual T visitVarStatement(Var* stmt) {};
    virtual T visitBlockStmt(Block* stmt) {};
    virtual T visitExpressionStmt(Expression* stmt) {};
    virtual T visitFunctionStmt(Function* stmt) {};
    virtual T visitIfStmt(If* stmt) {};
    virtual T visitPrintStatement(Print* stmt) {};
    virtual T visitReturnStmt(Return* stmt) {};

    virtual T visitAssignExpr(Assign* expr) {};
    virtual T visitBinaryExpr(Binary* expr) {};
    virtual T visitCallExpr(Call* expr) {};
    virtual T visitGroupingExpr(Grouping* expr) {};
    virtual T visitLiteralExpr(Literal* expr) {};
    virtual T visitLogicalExpr(Logical* expr) {};
    virtual T visitUnaryExpr(Unary* expr) {};
    virtual T visitVariableExpr(Variable* expr) {};
};

