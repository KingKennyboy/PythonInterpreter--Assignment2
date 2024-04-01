#pragma once

#include <string>
#include <map>
#include <algorithm>

class Environment {
public:
	std::map<std::string, int> data;

	Environment() {
		data = {};
	}

	int get(std::string identifier) {
		return data[identifier];
	}

	int set(std::string identifier, int value) {
		data[identifier] = value;
	}
};