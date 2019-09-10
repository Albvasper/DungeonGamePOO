#pragma once
#include <string>
#include <list>
class Enemy {

	private:
		unsigned short health;
		unsigned short damage;
		std::string name;
		std::list<std::list<std::string>> droppableObjs;

	public:
		Enemy();
		~Enemy();
};

