#pragma once
#include<iostream>
#include<iomanip>
class roomNode;
using namespace std;

class roomStack  //to track current room number player is in
{
public:
	roomNode* top;

	roomStack();
	
	void push(int id); //player has entered a room
	int pop();         //player has backtracked from a room 
	bool isEmpty();   //has the player entered any rooms yet
	int front();        //returns the current room player is in 
};

