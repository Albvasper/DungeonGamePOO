#include "pch.h"
#include "Player.h"
#include <iostream>

Player::Player() {
}

Player::Player(unsigned short _health, unsigned short _power, unsigned short _defense, unsigned short _positionX, unsigned short _positionY) {
	health = _health;
	power = _power;
	defence = _defense;
	playerPosX = _positionX;
	playerPosY = _positionY;
}

void Player::SetPlayerHP(unsigned short _health) {
	health = _health;
}

unsigned short Player::GetPlayerHP() {
	return health;
}

void Player::SetPlayerPosX(unsigned short _positionX) {
	playerPosX = _positionX;
}

void Player::SetPlayerPosY(unsigned short _positionY) {
	playerPosY = _positionY;
}

unsigned short Player::GetPlayerPosX() {
	return playerPosX;
}

unsigned short Player::GetPlayerPosY() {
	return playerPosY;
}

unsigned short Player::GetInventorySize() {
	return inventory.size();
}

void Player::OpenDoor() {
}

void Player::PickUpShield() {
}

void Player::PickUpSword() {
}

void Player::PickUpKey() {
}

void Player::SwitchShield() {
}

void Player::SwitchSword() {
}

void Player::SwitchKey() {
}

void Player::Attack() {
}

void Player::Defense() {
}

void Player::Inventory() {
}

void Player::DropItem() {
}

void Player::EnemyInventory() {
}

void Player::LootEnemy() {
}

void Player::Heal() {
}

void Player::Craft() {
}

void Player::OpenCraftingB() {
}

Player::~Player() {
}
