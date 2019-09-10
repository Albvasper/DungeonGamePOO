#pragma once
#include <map>

class Door {
	private:
		bool open;
		unsigned short roomIDx;
		unsigned short roomIDy;

	public:
		Door();
		Door(bool open, unsigned short _roomIDx, unsigned short _roomIDy);
		bool GetOpen();
		void SetDoorState(bool _open);
		unsigned short GetPairedRoomIDx();
		unsigned short GetPairedRoomIDy();
		~Door();
};

