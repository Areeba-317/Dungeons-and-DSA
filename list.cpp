#include<iostream>
#include<iomanip>
#include "list.h"
#include "player.h"
#include<string>
using namespace std;

extern item items[];
extern roomStack rooms;

void inventory::addToInventory(string item, playerInfo &p)
{
	for (int i = 0; i < 9; i++)
	{
		if (items[i].name == item)   //if item actually exists
		{
			if (items[i].type == PUZZLE) //dont add to inventory if puzzle
			{
				p.inv.puzzle(p);
			}
			else {
				if (head.it.itemID == -1)  //nothing in inv right now
				{
					//creating a node to add to the list
					itemNode* node = new itemNode(items[i].itemID, items[i].name, items[i].roomID, items[i].weight, items[i].pickable, items[i].type, items[i].damage);
					head.it = node->it;
					cout << ">Picked up item." << endl;
				}
				else if (p.inv.checkFull(items[i].weight) == 1) //if doesnt exceed inventory limit
				{
					itemNode* node = new itemNode(items[i].itemID, items[i].name, items[i].roomID, items[i].weight, items[i].pickable, items[i].type, items[i].damage);
					//head.next = node;
					itemNode* curr = &head;
					while (curr->next != NULL)
					{
						curr = curr->next;
					}
					curr->next = node;
					cout << ">Picked up item." << endl;
				}
				else
				{
					cout << "* Inventory full !" << endl;
				}
			}
		}
	}
}

void inventory::puzzle(playerInfo& p)
{
	string riddle="If you drop me, I'm sure to crack. Give me a smile, and I'll always smile back.";
	string answer = "mirror", inp;
	cout << "A lock encloses a dark wooden box. A riddle seems to be enscribed on it..." << endl << "'" << riddle << "'" << endl;
	cout << "_ _ _ _ _ _" << endl;

	while (true) {
		cout << "You mix and match to find the right answer: ('exit' to leave)" << endl;
		cin >> inp;
		cin.ignore();
		for (int i = 0; i < inp.length(); i++)  //converting the player's answer to lowercase
		{
			tolower(inp[i]);
		}
		if (inp == answer)
		{
			char choice=' ';
			cout << "The box opens with a faint click, revealing the key that lay within." << endl;
			cout << "> Pick up? (Y | N) " << endl;
			cin >> choice;
			cin.ignore();
			if (choice == 'Y' || choice == 'y')
			{
				//items[1] = { "key01", 1, 1, 2, true, KEY,0 };
				items[0]={ "Puzzle", 0, -1, 0, false, PUZZLE, 0 };
				this->addToInventory(items[1].name, p);
				break;
			}
		}
		else if (inp == "exit" || inp == "Exit")
		{
			break;
		}
		else
		{
			cout << "You stare in frustration. It seems to br wrong." << endl;
		}
	}
	

}


int inventory::checkFull(int i)   //checking to see if inventory full or can hold new item
{
	bool flag = 1;                //set to not full
	int capacity=0;
	if (head.it.itemID !=-1)   //if something exists
	{
		itemNode* temp = &head;
		while (temp)              //traverse the list and count the capacity/weights of items
		{
			capacity+= temp->it.weight;
			temp = temp->next;
		}
		if ((capacity >= 10) || ((capacity+=i)>=10))
		{
			flag = 0;
		}
	}
	return flag;
}

void inventory::viewInventory()
{
	itemNode* curr = &head;

	if (head.it.itemID == -1)
	{
		cout << "(empty)";
	}
	else {

		while (curr)
		{
			cout << curr->it.name << ", ";
			curr = curr->next;
		}
	}
	cout << endl;
}

void inventory::dropFromInventory(string item)
{
	bool flag = false;

	if (head.it.itemID == NULL)
	{
		cout << "* Inventory already empty" << endl;
		return;
	}

	// the first node is the item we want to delete
	if (head.it.name == item)
	{
		if (head.next != nullptr)
		{
			// Copy next node's contents into head
			itemNode* temp = head.next;
			head.it = temp->it;
			head.next = temp->next;
			delete temp;
			temp = nullptr;
		}
		else
		{
			head.clear();
		}
		cout << ">Item dropped." << endl;
		for (int i = 0; i < 9; i++)
		{
			if (items[i].name == item) //Drop item into current room
			{
				items[i].roomID = rooms.front();
			}
		}
		return;
	}

	//item is somewhere beyond the head
	itemNode* prev = &head;
	itemNode* curr = head.next;

	while (curr != nullptr)
	{
		if (curr->it.name == item)
		{
			prev->next = curr->next;
			delete curr;
			cout << ">Item dropped." << endl;
			for (int i = 0; i < 9; i++)
			{
				if (items[i].name == item) //Drop item into current room
				{
					items[i].roomID = rooms.front();
				}
			}
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	cout << "* Item not found!" << endl;
}

bool inventory::checkInven(string item)
{
	itemNode* curr = &head;

	if (head.it.itemID == -1)
	{
		return 0;
	}
	else {

		while (curr)
		{
			if (curr->it.name == item)
			{
				return 1;
			}
			curr = curr->next;
		}
	}
	return 0;
}
