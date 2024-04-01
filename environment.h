#pragma once

#include <string>
#include <map>
#include <algorithm>

#include "object.h"

class Environment {
public:
	std::map<std::string, Object*> data;

	Environment() {
		data = {};
	}

	Object* get(std::string identifier) {
		return data[identifier];
	}

	void set(std::string identifier, Object* value) {
		data[identifier] = value;
	}
};