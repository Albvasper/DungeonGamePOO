#include "pch.h"
#include "Door.h"

Door::Door() {
}

Door::Door(bool _open, unsigned short _roomIDx, unsigned short _roomIDy) {
	open = _open;
	roomIDx = _roomIDx;
	roomIDy = _roomIDy;
}

bool Door::GetOpen() {
	return open;
}

void Door::SetDoorState(bool _open) {
	open = _open;
}

unsigned short Door::GetPairedRoomIDx() {
	return roomIDx;
}

unsigned short Door::GetPairedRoomIDy() {
	return roomIDy;
}

Door::~Door() {
}
