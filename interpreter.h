#pragma once

#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include "environment.h"
#include "visitor.h"
#include "statement.h"
#include "object.h"

class Interpreter: public Visitor<Object> {
public:
    std::vector<Statement*> stmts;

    Interpreter(std::vector<Statement*> stmts) {
        this->stmts = stmts;
        env = new Environment();
    }

    void run() {
        for (Statement* s : stmts) {
            s->accept(this);
        }
    };

    Object visitVarStatement(Var* stmt) {};
    Object visitBlockStmt(Block* stmt) {};
    Object visitExpressionStmt(Expression* stmt) {};
    Object visitFunctionStmt(Function* stmt) {};
    Object visitIfStmt(If* stmt) {};
    Object visitPrintStatement(Print* stmt) {};
    Object visitReturnStmt(Return* stmt) {};
    
    Object visitAssignExpr(Assign* expr) {};
    Object visitBinaryExpr(Binary* expr) {};
    Object visitCallExpr(Call* expr) {};
    Object visitGroupingExpr(Grouping* expr) {};
    Object visitLiteralExpr(Literal* expr) {};
    Object visitLogicalExpr(Logical* expr) {};
    Object visitUnaryExpr(Unary* expr) {};
    Object visitVariableExpr(Variable* expr) {};

private:
    Environment* env;
    std::stack<int> tempInteger;
};
