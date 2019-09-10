#pragma once
#include "Object.h"
#include <string>

class Shield : public Object {

	private:
		unsigned short defence;
		std::string name;

	public:
		Shield();
		~Shield();
};

