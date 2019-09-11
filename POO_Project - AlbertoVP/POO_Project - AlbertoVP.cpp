#include "pch.h"
#include "Door.h"
#include "Room.h"
#include "Player.h"
#include "Enemy.h"
#include "Object.h"
#include "RayGun.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

std::vector<std::string> splitSt(std::string mainS, char space) {
	std::stringstream ss(mainS);
	std::string word;
	std::vector<std::string> stringsLeft;
	while (std::getline(ss, word, space)) {
		stringsLeft.push_back(word);
	}
	return stringsLeft;
}

int main() {
	//--------------------------------------------------------------------------------------Variables
	short verbCase;
	short roomSelector;
	short roomNumber = 0;
	unsigned short CurrentPx;
	unsigned short CurrentPy;
	std::string mainString;
	std::vector<std::string>::iterator it;
	std::multimap <short, std::string>::iterator it2;
	std::multimap <short, std::string> verbMM;
	Room roomArr[14][15];
	verbMM.insert(std::pair <short, std::string>(0, "atacar"));
	verbMM.insert(std::pair <short, std::string>(0, "matar"));
	verbMM.insert(std::pair <short, std::string>(1, "entrar"));
	verbMM.insert(std::pair <short, std::string>(1, "moverme"));
	verbMM.insert(std::pair <short, std::string>(2, "craftear"));
	verbMM.insert(std::pair <short, std::string>(2, "hacer"));
	verbMM.insert(std::pair <short, std::string>(3, "recoger"));
	verbMM.insert(std::pair <short, std::string>(3, "tomar"));
	verbMM.insert(std::pair <short, std::string>(4, "cambiar"));
	verbMM.insert(std::pair <short, std::string>(5, "cubrir"));
	verbMM.insert(std::pair <short, std::string>(5, "protegerme"));
	verbMM.insert(std::pair <short, std::string>(6, "inventario"));
	verbMM.insert(std::pair <short, std::string>(7, "tirar"));
	verbMM.insert(std::pair <short, std::string>(8, "lootear"));
	verbMM.insert(std::pair <short, std::string>(9, "curarme"));

	//--------------------------------------------------------------------------------------Rooms
	//Creo que no necesito el room ID en los parametros del cuarto pero no afecta ni sireve de nada
	Room room011(0, 11, "Estas es la habitacion de SPAWN"); 
	Room room111(1, 11, "Esta obscuro...");
	Room room211(2, 11, "hahah lol");
	Room room210(2, 10, "AQUI NO QUIERES ESTAR");
	Room room311(3, 11, "descripcion aqui2");

	//--------------------------------------------------------------------------------------Doors
	Door d011_1(true, 1, 11); // Door - Room011 - Door1 
	room011.doorMap.insert(std::pair <unsigned short, Door>(1, d011_1));

	Door d111_1(true, 0, 11); // Door - Room111 - Door1 (Back door)
	Door d111_2(true, 2, 11); // Door - Room111 - Door2
	room111.doorMap.insert(std::pair <unsigned short, Door>(1, d111_1));
	room111.doorMap.insert(std::pair <unsigned short, Door>(2, d111_2));

	Door d211_1(true, 1, 11); // Door - Room211 - Door1 (Back door)
	Door d211_2(true, 2, 10); // Door - Room211 - Door2
	Door d211_3(false, 3, 11); // Door - Room211 - Door3
	room211.doorMap.insert(std::pair <unsigned short, Door>(1, d211_1));
	room211.doorMap.insert(std::pair <unsigned short, Door>(2, d211_2));
	room211.doorMap.insert(std::pair <unsigned short, Door>(3, d211_3));

	Door d210_1(true, 2, 11); // Door - Room210 - Door1 (Back door)
	Door d210_2(false, 2, 9);  // Door - Room210 - Door2
	room210.doorMap.insert(std::pair <unsigned short, Door>(1, d210_1));
	room210.doorMap.insert(std::pair <unsigned short, Door>(2, d210_2));

	//--------------------------------------------------------------------------------------Objects
	RayGun rg1;
	
	//room0.objectMap.insert(std::pair <unsigned short, Object>(0, new Object()));
	//room0.enemyMap.insert(std::pair <unsigned short, Enemy>(0, new Enemy()));
	//room1.objectMap.insert(std::pair <unsigned short, Object>(0, new Object()));
	/*Enemy e11;*/
	/*room1.enemyMap.insert(std::pair <unsigned short, Enemy>(0, e11));*/
	//room1.objectMap.insert(std::pair <unsigned short, Object>(0, new Object()));
	//room1.enemyMap.insert(std::pair <unsigned short, Enemy>(0, new Enemy()));


	//--------------------------------------------------------------------------------------Insert Rooms into Array
	roomArr[0][11] = room011;
	roomArr[1][11] = room111;
	roomArr[2][11] = room211;
	roomArr[2][10] = room210;
	roomArr[3][11] = room311;

	//--------------------------------------------------------------------------------------player
	Player p1(100,50,50,0,11); // (HP, Power, Defense, posX, posY)

	//--------------------------------------------------------------------------------------Game
	while(true) {
		mainString.clear();		
		std::cin.clear();
		std::cout << "================Room Info================" << std::endl;
		std::cout << "Estas en la habitacion [" << p1.GetPlayerPosX() << "]" << "[" << p1.GetPlayerPosY() << "]" << std::endl; 
		std::cout << "\"" << roomArr[p1.GetPlayerPosX()][p1.GetPlayerPosY()].DisplayInfo() << "\"" << std::endl; 
		std::cout << "En este cuarto hay " << roomArr[p1.GetPlayerPosX()][p1.GetPlayerPosY()].GetDoorN() << " puerta/s." << std::endl;
		std::cout << "En este cuarto hay " << roomArr[p1.GetPlayerPosX()][p1.GetPlayerPosY()].GetEnemyN() << " enemigo/s." << std::endl;
		std::cout << "En este cuarto hay " << roomArr[p1.GetPlayerPosX()][p1.GetPlayerPosY()].GetObjN() << " objeto/s." << std::endl;
		std::cout << "=========================================" << std::endl;
		std::cout << std::endl << "Que quieres hacer? \n";
		std::cout << "- ";
		std::getline(std::cin, mainString);
		std::vector<std::string> wordVec = splitSt(mainString, ' ');
		
		//Compares the vector of strings with the multimap 
		for (it = wordVec.begin(); it < wordVec.end(); it++) {
			for (it2 = verbMM.begin(); it2 != verbMM.end(); it2++) {
				if (*it == (*it2).second) {
					verbCase = (*it2).first;
					switch (verbCase) {	
						case 0:
							std::cout << "----------\n";
							std::cout << "Found Atacar \n";
							break;

						case 1:
							std::cout << "A que puerta te quieres mover? \n";
							std::cout << "- ";
							std::cin >> roomSelector;
							if (roomSelector > 0) {
								if (roomSelector <= roomArr[p1.GetPlayerPosX()][p1.GetPlayerPosY()].GetDoorN()) {
									if (roomArr[p1.GetPlayerPosX()][p1.GetPlayerPosY()].doorMap[roomSelector].GetOpen() == true){
										//Variables that prevent any misleading room position when setting x and y to the player
										CurrentPx = p1.GetPlayerPosX(); 
										CurrentPy = p1.GetPlayerPosY();
										p1.SetPlayerPosX(roomArr[CurrentPx][CurrentPy].doorMap[roomSelector].GetPairedRoomIDx());
										p1.SetPlayerPosY(roomArr[CurrentPx][CurrentPy].doorMap[roomSelector].GetPairedRoomIDy());
										std::cout << "Entrando a la siguiente habitacion..." << std::endl;
										system("pause");
									}
									 else if (roomArr[p1.GetPlayerPosX()][p1.GetPlayerPosY()].doorMap[roomSelector].GetOpen() == false) {
										std::cout << "Esta puerta esta cerrada!" << std::endl;
										system("pause");
									}
								} 
								else {
									std::cout << "El numero es demasiado alto!" << std::endl;
									system("pause");
								}
							}
							else {
								std::cout << "El numero no puede ser 0!" << std::endl;
								system("pause");
							}
							break;
								
						case 2:
							std::cout << "----------\n";
							std::cout << "Found craftear \n";
							break;

						case 3:
							std::cout << "----------\n";
							std::cout << "Found recoger \n";
							break;

						case 4:
							std::cout << "----------\n";
							std::cout << "Found cambiar \n";
							break;

						case 5:
							std::cout << "----------\n";
							std::cout << "Found cubrir \n";
							break;

						case 6:
							system("cls");
							std::cout << "================Inventario!================" << std::endl;
							std::cout << "Tienes " << p1.GetInventorySize() << " objetos en tu inventario." << std::endl;
							std::cout << "===========================================" << std::endl;
							
							system("pause");
							break;

						case 7:
							std::cout << "----------\n";
							std::cout << "Found tirar \n";
							break;

						case 8:
							std::cout << "----------\n";
							std::cout << "Found lootear \n";
							break;

						case 9:
							std::cout << "----------\n";
							std::cout << "Found curarse \n";
							break;

						default:
							break;
					}
				}
			}
		}
		system("cls");
	}
	return 0;
}