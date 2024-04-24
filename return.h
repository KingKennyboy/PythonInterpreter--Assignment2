
#include <exception>
#include "object.h"

class Return : public std::exception {
public:
	Object* return_object;

	char* what() {
		return "Custom Return Exception";
	}

	Return(Object* obj) {
		return_object = obj;
	}

	Return() {
		return_object = new None();
	}
};