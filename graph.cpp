#include<iostream>
#include<iomanip>
using namespace std;
#include "roomGraph.h"
#include "stack.h"
#include "utils.h"
#include "player.h"

extern playerInfo player;
extern room r[];

void Graph::printGraph()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			cout << roomConnections[i][j];
		}
		cout << endl;
	}
}

void Graph::printRooms(roomStack rooms)
{
	int roomNo = rooms.front(); //getting the current room id
	cout << "| You are currently in: " << printRoomName(roomNo) << endl;  //replace with actual room name
	cout << "> Connected rooms: ";  //displaying connected rooms

		for (int j = 0; j < 11; j++)
		{
			if (roomConnections[roomNo][j]==1)
			{
				cout << printRoomName(j) << ", ";
			}
		}

	cout << endl;
}

void Graph::moveRooms(roomStack &rooms, string s)
{
	bool flag = false;     //to check if room exists
	int roomNo = rooms.front(); //getting the current room id

	for (int j = 0; j < 11; j++)
	{
		if (roomConnections[roomNo][j] == 1)
		{
			if (printRoomName(j) == s)    //checking if the room name is the same as what the player entered
			{
				if (r[j].locked == 1)     //if room locked
				{
					if (r[j].id == 5)     //check if it's dark shrine
					{
						if (player.inv.checkInven("key01") == 1)
						{
							flag = 1;
							roomNo = j;               //updating room number
							player.inv.dropFromInventory("key01");  //drop key after using
							cout << ">Using key01."<<endl<<">The Door opens with a creak..." << endl;
							break;
						}
						else
						{
							cout << "* You do not have the key to enter this room." << endl;
							flag = 0;
							break;
						}
					}
					else                 //else it's the final gate
					{
						if (player.inv.checkInven("key02") == 1)
						{
							flag = 1;
							roomNo = j;               //updating room number
							player.inv.dropFromInventory("key02");  //drop key after using
							cout << ">Using key01." << endl << ">The Door opens with a creak..." << endl;
							break;
						}
						else
						{
							cout << "* You do not have the key to enter this room." << endl;
							flag = 0;
							break;
						}
					}
				}
				flag = 1; 
				roomNo = j;               //updating room number
				break;
				 				
			}
		}
	}

	if (flag == 1)  //move room
	{
		rooms.push(roomNo);
	}
	else
	{
		cout << "Invalid room!" << endl;
	}
}