#pragma once
#include<iostream>
#include<iomanip>
#ifndef ROOMSTRUCTS_H
#define ROOMSTRUCTS_H
#include <string>
#include "stack.h"
class playerInfo;
using namespace std;

enum itemType { WEAPON, KEY, PUZZLE, POTION, UTILITY };
struct item {            //struct to hold item info
	string name;
	int itemID;
	int roomID;
	int weight;
	bool pickable;
	itemType type;
	int damage;
	
	void printItems(roomStack& s, item items[]);
};

struct enemy {           //struct to hold enemy info
	string name;
	int enemyID;
	int roomID;
	int strength;        //from 1-100
	int speed;           //from 1-10
	int health;
	bool status;         //1 for alive, 0 for deceased

	void fight(playerInfo &p, enemy enemy[]);
	int enemyatk(int id, int str, int speed, int atk, playerInfo& p);  //return the attack value of the enemy 
	bool printEnemies(roomStack &s, enemy enemy[], playerInfo& p);
};

class room {             //class to hold room info 
public:
	int id;
	string name;
	int itemID;         //if room requires certain item before entering
	enemy* roomEnemy;
	bool locked;

	room()
	{
		this->id = NULL;
		this->name = "";
		this->itemID = NULL;
		this->roomEnemy = NULL;
		this->locked = 0;
	}

	room(int i, string n, bool lock = NULL, int item=NULL, enemy* enemy=NULL)
	{
		this->id = i;
		this->name = n;
		this->itemID = item;
		this->roomEnemy = enemy;
		this->locked = lock;
	}
};

#endif