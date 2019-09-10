#pragma once
#include <string>

class Object {

	private:
		unsigned short id;
		std::string name;
		std::string text;

	public:
		Object();
		Object(unsigned short _id, std::string _name, std::string _text);
		std::string GetObjName();
		~Object();
};

