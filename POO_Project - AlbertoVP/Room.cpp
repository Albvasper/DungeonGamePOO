#include "pch.h"
#include "Room.h"

//Room::Room(nhab,strng desc,apuntador a una lista de ap, ap de lista de enemigos) {
//}

Room::Room() {
}

Room::Room(unsigned short _roomIDx, unsigned short _roomIDy, std::string _info) {
	roomIDx = _roomIDx; 
	roomIDy = _roomIDy;
	info = _info;
}

unsigned short Room::GetDoorN() {
	return doorMap.size();
}

unsigned short Room::GetEnemyN() {
	return enemyMap.size();
}

unsigned short Room::GetObjN() {
	return objectMap.size();
}

unsigned short Room::GetRoomIDx() {
	return roomIDx;
}

unsigned short Room::GetRoomIDy() {
	return roomIDy;
}

std::string Room::DisplayInfo() {
	return info;
}

Room::~Room() {
}
	