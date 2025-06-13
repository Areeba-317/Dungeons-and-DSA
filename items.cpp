#include<iostream>
#include<iomanip>
#include"stack.h"
#include"roomStructs.h"
using namespace std;

void item::printItems(roomStack& s, item it[])
{
		if (this->roomID == s.front())     //if item exists in the room
		{
			if (this->type == PUZZLE)
			{
				cout << ">Event: A puzzle awaits you." << endl;
			}
			else if (this->type == WEAPON)
			{
				cout << ">Event: You found a " << this->name << " ! [" << this->weight << "kg +" << this->damage << " atk]" << endl;
			}
			else if (this->type == POTION)
			{
				cout << ">Event: You found a potion: " << this->name <<" [" << this->weight << " kg ]"<< endl;
			}
			else
			{
				cout << ">Event: You found an item: " << this->name<< " [" << this->weight << " kg ]" << endl;

			}
		}

}