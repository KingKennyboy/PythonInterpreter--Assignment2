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

class Interpreter: public Visitor<Object*> {
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

    Object* evaluate(Statement* stmt) {
        return stmt->accept(this);
    }

    Object* evaluate(Expr* expr) {
        return expr->accept(this);
    }

    Object* visitVarStatement(Var* stmt) {
        env->set(stmt->name.value, stmt->initial->accept(this));
        return nullptr;
    };
    
    Object* visitBlockStmt(Block* stmt) {
        for (auto s : stmt->statements) {
            s->accept(this);
        }
        return nullptr;
    };
    
    Object* visitExpressionStmt(Expression* stmt) {
        stmt->accept(this);
        return nullptr;
    };
    
    Object* visitFunctionStmt(Function* stmt) {
        env->set(stmt->name.value, stmt);
        return nullptr;
    };

    Object* visitIfStmt(If* stmt) {
        Object* conditional_obj = evaluate(stmt->condition);
        Boolean* conditional = dynamic_cast<Boolean*>(conditional_obj);
        if (conditional == nullptr) {
            error();
        }

        if (conditional != nullptr && conditional->value) {
            evaluate(stmt->thenBranch);
        }
        else if (stmt->elseBranch != nullptr) {
            evaluate(stmt->elseBranch);
        }

        return nullptr;
    };
    Object* visitPrintStatement(Print* stmt) {
        for (size_t i = 0; i < stmt->exprs.size(); i++) {
            if (i != 0) {
                std::cout << " ";
            }
            Object* v = evaluate(stmt->exprs[i]);
            std::cout << v->toString();
        }
        std::cout << "\n";
        return nullptr;
    };
    Object* visitReturnStmt(Return* stmt) {
        return nullptr;
    };
    Object* visitAssignExpr(Assign* expr) {
        return nullptr;
    };
    Object* visitBinaryExpr(Binary* expr) {
        Object* rhs_obj = evaluate(expr->right);
        Object* lhs_obj = evaluate(expr->left);
        Integer* lhs_int = dynamic_cast<Integer*>(lhs_obj);
        Integer* rhs_int = dynamic_cast<Integer*>(rhs_obj);
        Boolean* lhs_bool = dynamic_cast<Boolean*>(lhs_obj);
        Boolean* rhs_bool = dynamic_cast<Boolean*>(rhs_obj);

        Boolean* res = nullptr;;
        switch (expr->op.type) {
        case EQUAL_TO:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Boolean(lhs_int->value == rhs_int->value);
            }
            else if (lhs_bool != nullptr && rhs_bool != nullptr) {
                return new Boolean(lhs_bool->value == rhs_bool->value);
            }
        case NOT_EQUAL_TO:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Boolean(lhs_int->value != rhs_int->value);
            }
            else if (lhs_bool != nullptr && rhs_bool != nullptr) {
                return new Boolean(lhs_bool->value != rhs_bool->value);
            }
        case GREATER_THAN:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Boolean(lhs_int->value > rhs_int->value);
            }
        case LESS_THAN:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Boolean(lhs_int->value < rhs_int->value);
            }
        case GREATER_THAN_EQUAL_TO:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Boolean(lhs_int->value >= rhs_int->value);
            }
        case LESS_THAN_EQUAL_TO:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Boolean(lhs_int->value <= rhs_int->value);
            }
        case MINUS:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Integer(lhs_int->value - rhs_int->value);
            }
        case PLUS:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Integer(lhs_int->value + rhs_int->value);
            }
        case DIVIDE:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Integer((int)(lhs_int->value / rhs_int->value));
            }
        case MULTIPLY:
            if (lhs_int != nullptr && rhs_int != nullptr) {
                return new Integer((int)(lhs_int->value * rhs_int->value));
            }
        }
        error();
        return nullptr;
    };
    Object* visitCallExpr(Call* expr) {
        //data_function[expr->callee]
        return nullptr;
    };
    Object* visitGroupingExpr(Grouping* expr) {
        return evaluate(expr->expression);
    };
    Object* visitLiteralExpr(Literal* expr) {
        switch (expr->token.type) {
        case TRUE:
            return new Boolean(true);
        case FALSE:
            return new Boolean(false);
        case NONE:
            return new None();
        case IDENTIFIER:
            return env->get(expr->token.value);
        case NUMBER:
            return new Integer(std::stoi(expr->token.value));
        case STRING:
            return new String(expr->token.value);
        }
        error();
        return nullptr;
    };
    Object* visitLogicalExpr(Logical* expr) {
        Object* rhs_obj = evaluate(expr->right);
        Object* lhs_obj = evaluate(expr->left);
        Boolean* lhs_bool = dynamic_cast<Boolean*>(lhs_obj);
        Boolean* rhs_bool = dynamic_cast<Boolean*>(rhs_obj);

        if (lhs_bool != nullptr && rhs_bool != nullptr) {
            switch (expr->op.type) {
            case AND:
                return new Boolean(lhs_bool->value && rhs_bool->value);
            case OR:
                return new Boolean(lhs_bool->value || rhs_bool->value);
            }
        }
        error();
        return nullptr;
    };
    Object* visitUnaryExpr(Unary* expr) {
        Object* rhs_obj = evaluate(expr->right);
        Integer* rhs_int = dynamic_cast<Integer*>(rhs_obj);
        Boolean* rhs_bool = dynamic_cast<Boolean*>(rhs_obj);

        switch (expr->op.type) {
        case MINUS:
            if (rhs_int == nullptr) { error(); return nullptr; }
            else {
                return new Integer(-rhs_int->value);
            }
        case NOT:
            if (rhs_bool == nullptr) { error(); return nullptr; }
            else if (rhs_bool != nullptr && rhs_bool->value) { return new Boolean(false); }
            else {
                return new Boolean(true);
            }
        }

        error();
        return nullptr;
    };
    Object* visitVariableExpr(Variable* expr) {
        return nullptr;
    };

private:
    Environment* env;
    std::stack<int> tempInteger;

    void error() {
        throw std::runtime_error("Error interpreter");
    }
};
