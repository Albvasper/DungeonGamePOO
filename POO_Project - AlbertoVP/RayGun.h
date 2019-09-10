#pragma once
#include "Object.h"

class RayGun : public Object {

	private:
		unsigned short power = 30;

	public:
		RayGun();
		unsigned short GetPower();
		void SetPower(unsigned short _power);
		~RayGun();
};

