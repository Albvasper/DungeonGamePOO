#include "pch.h"
#include "Object.h"

Object::Object() {
}

Object::Object(unsigned short _id, std::string _name, std::string _text) {
	id = _id;
	name = _name;
	text = _text;
}

std::string Object::GetObjName() {
	return std::string(name);
}

Object::~Object() {
}
