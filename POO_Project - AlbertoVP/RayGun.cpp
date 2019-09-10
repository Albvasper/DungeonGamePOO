#include "pch.h"
#include "RayGun.h"

RayGun::RayGun() {
}

unsigned short RayGun::GetPower() {
	return power;
}

void RayGun::SetPower(unsigned short _power) {
	power = _power;
}

RayGun::~RayGun() {
}
