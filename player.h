#pragma once
#include<iostream>
#include<iomanip>
#include "list.h"
using namespace std;

class playerInfo
{
public:
	inventory inv;
	int health;
	int speed; 
	int strength;


	playerInfo()
	{
		health = 100;
		strength = 35;
		speed = 5;
	}

	int playerAtk(enemy& e);
};