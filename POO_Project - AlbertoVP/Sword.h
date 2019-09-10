#pragma once
#include "Object.h"
#include <string>

class Sword : public Object {

	private:
		unsigned short power;
		std::string name;

	public:
		Sword();
		~Sword();
};

