#pragma once
#include "Shield.h"
#include <vector>
#include <list>

class Player {

	private:
		unsigned short health;
		bool key;
		unsigned short power;
		unsigned short defence;
		unsigned short playerPosX;
		unsigned short playerPosY;
		std::list<Object> inventory;

	public:
		Player();
		Player(unsigned short _health, unsigned short _power, unsigned short _defense, unsigned short _positionX, unsigned short _positionY);
		void SetPlayerHP(unsigned short _health);
		unsigned short GetPlayerHP();
		void SetPlayerPosX(unsigned short _positionX);
		void SetPlayerPosY(unsigned short _positionY);
		unsigned short GetPlayerPosX();
		unsigned short GetPlayerPosY();
		unsigned short GetInventorySize();

		void OpenDoor();
		void PickUpShield();	
		void PickUpSword();
		void PickUpKey();
		void SwitchShield();
		void SwitchSword();
		void SwitchKey();	
		void Attack();
		void Defense();		   
		void Inventory();	   
		void DropItem();
		void EnemyInventory();
		void LootEnemy();
		void Heal();			//Agregar el item de poti, la subclase, pues..?
		void Craft();
		void OpenCraftingB();
		~Player();
};
