#include<iostream>
#include<iomanip>
#include<string>
#include "roomGraph.h"
#include"stack.h"
#include "roomStructs.h"
#include "utils.h"
#include "player.h"

using namespace std;

room r[11] = {                             //initializing the rooms 
				{0, "Entrance Hall"}, 
				{1, "North Tower"},
				{2, "Armory"},
				{3, "Barracks"}, 
				{4, "Library"},
				{5, "Dark Shrine",1},
				{6, "Dark Corridor"}, 
				{7, "Alchemy Lab"},
				{8, "South Tower"}, 
				{9, "Right Hall"}, 
				{10, "Final Gate",1}
			};

item items[] = {
	{"Puzzle", 0, 1, 0, false, PUZZLE,0},
	{"key01", 1, -1, 2, true, KEY,0},
	{"Sword", 2, 2, 5, true, WEAPON,20},
	{"Hammer", 3, 2, 4, true, WEAPON,15},
	{"Green potion", 4, 4, 2, true, POTION,0},
	{"Torch", 5, 4, 3, true, UTILITY,0},
	{"key02", 6, -1, 2, true, KEY,0},
	{"Mysterious potion", 7, 7, 3, true, POTION,0},
	{"Bomb", 8, 8, 3, true, UTILITY,35} 
};

enemy enemies[] = {
	{"Goblin",0,3,35,8,35,1},
	{"Spartacus the eagle",1,8,60,5,60,1},
	{"The Dragon",0,10,100,3,100,1}
				  };

roomStack rooms;                             //creating the stack to hold current room 
Graph g;                                 //graph to connect the rooms 
string commands[5] = { "goto", "pick", "drop", "view", "use"};
playerInfo player;
int main()
{
	//welcome();
    
	while (true)                        //main game loop, runs till player either dies or escapes
	{
		string cmd;
		cout << endl;
		g.printRooms(rooms);

		//printing the enemies and fighting them
		for (int i = 0; i < 3; i++)
		{
			if (enemies[i].printEnemies(rooms, enemies, player) == 1)
			{
				break;
			}
			
		}
		//if player's health depletes
		if (player.health <= 0)
		{
			cout << endl << "You crumple to your knees. All hope has been lost." << endl << "Game over.";
			break;

		}
		//printing the events in the rooms
		for(int i = 0; i < 9; i++){
			items[i].printItems(rooms,items); }

		cout << "Command: ";
		getline(cin, cmd);

		//checking the command user entered
		if (cmd.find(commands[0])==0)          //if player wants to change room
		{
			string roomName = cmd.substr(commands[0].length());
			roomName.erase(0, roomName.find_first_not_of(" \t"));
		    g.moveRooms(rooms,roomName);
		}
		else if (cmd.find(commands[1]) == 0)
		{
			string itemName = cmd.substr(commands[1].length());
			itemName.erase(0, itemName.find_first_not_of(" \t"));
			player.inv.addToInventory(itemName, player);

		}
		else if (cmd.find(commands[2]) == 0)
		{
			string itemName = cmd.substr(commands[2].length());
			itemName.erase(0, itemName.find_first_not_of(" \t"));
			player.inv.dropFromInventory(itemName);

		}
		else if (cmd.find(commands[3]) == 0)
		{
			player.inv.viewInventory();
		}
		else
		{
			cout << "Invalid command";
		}
	}
}
