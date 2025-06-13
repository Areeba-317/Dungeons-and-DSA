#pragma once
#include<iostream>
#include<iomanip>
#include "roomStructs.h"
#include"stack.h"
class roomStack;  
class playerInfo;

using namespace std;

class roomNode    //node to use within the stack
{
public:
	int id;
	roomNode* next;

	roomNode(int id=NULL, roomNode* next=nullptr)
	{
		this->id = id;
		this->next = nullptr;
	}
};

class itemNode
{
public:
	item it;
	itemNode* next;

	itemNode()
	{
		this->it.itemID = -1;
		this->it.name = "";
		this->it.roomID = NULL;
		this->it.weight = NULL;
		this->it.pickable = NULL;
		this->it.type = UTILITY;
		this->it.damage = NULL;
		
		this->next = nullptr;
	}

	itemNode(int id, string name, int rid, int weight, bool pick, itemType type, int dmg)
	{
		this->it.itemID = id;
		this->it.name = name;
		this->it.roomID = rid;
		this->it.weight = weight;
		this->it.pickable = pick;
		this->it.type = type;
		this->it.damage = dmg;
		this->next = nullptr;
	}

	void clear()
	{
		this->it.itemID = -1;
		this->it.name = "";
		this->it.roomID = NULL;
		this->it.weight = NULL;
		this->it.pickable = NULL;
		this->it.type = UTILITY;
		this->it.damage = NULL;

		this->next = nullptr;
	}
};

class inventory
{
public:
	itemNode head;
	int capacity;

	inventory()
	{
		head.it.itemID = -1;
		head.it.damage = NULL;
		head.it.name = "";
		head.it.pickable = NULL;
		head.it.roomID = NULL;
		head.it.type = UTILITY;
		head.it.weight = NULL;
		head.next = nullptr;
		capacity = 10;    //max capacity
	}
	
	void addToInventory(string item, playerInfo &p);
	void dropFromInventory(string item);
	int checkFull(int i);
	void viewInventory();
	void puzzle(playerInfo& p);
	bool checkInven(string item);
};