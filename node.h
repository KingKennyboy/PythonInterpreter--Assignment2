#pragma once

#include <vector>
#include "token.h"

enum NodeType {
	
};

struct Node {
	TokenType type;
	std::vector<Node*> children;
	void* data = nullptr;

	Node(TokenType t) {
		t = type;
		data = nullptr;
	}

	void addChild(Node* c) {
		children.push_back(c);
	}
};

