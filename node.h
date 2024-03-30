#pragma once

#include <vector>
#include "token.h"

enum NodeType {
	PRIMARY, UNARY, BINARY, MULTIPLE
};

struct Node {
	NodeType type;
	TokenType operation;
	std::vector<Node*> children;

	Node(NodeType t) {
		t = type;
	}

	Node(NodeType t) {

	}
};

