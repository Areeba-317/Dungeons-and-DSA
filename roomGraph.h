#pragma once
#include<iostream>
#include<iomanip>
#include "stack.h"
#include "utils.h"
using namespace std;

class Graph
{		                         //graph to connect the rooms of size 11

	int roomConnections[11][11] = { 0,1,1,0,0,0,0,0,0,0,0,
								 1,0,0,0,0,0,0,0,0,0,0,
								 1,0,0,1,1,0,0,0,0,0,0,
								 0,0,1,0,0,1,0,0,0,0,0,
								 0,0,1,0,0,1,1,1,0,0,0,
								 0,0,0,1,1,0,0,0,0,0,0,
								 0,0,0,0,1,0,0,0,0,0,0,
								 0,0,0,0,1,0,0,0,1,0,0,
								 0,0,0,0,0,0,0,1,0,1,0,
								 0,0,0,0,0,0,0,1,0,0,1,
								 0,0,0,0,0,0,0,0,0,1,0 };
								 
public:
	
	void printGraph();                //printing the graph matrix
	void printRooms(roomStack rooms);     //to display current and connected rooms
	void moveRooms(roomStack& rooms, string s);      //to move across rooms
};