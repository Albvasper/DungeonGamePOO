#pragma once
#include <string>
#include <map>
#include "Door.h"
#include "Enemy.h"
#include "Object.h"

class Room {

	private:
		int *D;				// Door pointer
		int *O;				// Object pointer
		int *E;				// Enemy pointer
		unsigned short roomIDx;
		unsigned short roomIDy;
		std::string info;

	public:
		std::map<unsigned short, Door> doorMap;
		std::map<unsigned short, Enemy> enemyMap;
		std::map<unsigned short, Object> objectMap;
		Room();
		Room(unsigned short _roomIDx, unsigned short _roomIDy, std::string _info);
		unsigned short GetDoorN();
		unsigned short GetEnemyN();
		unsigned short GetObjN();
		unsigned short GetRoomIDx();
		unsigned short GetRoomIDy();
		std::string DisplayInfo();
		~Room();
};

