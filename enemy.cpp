#include<stdio.h>
#include<iomanip>
#include "roomStructs.h"
#include "stack.h"
#include "player.h"
using namespace std;

bool enemy::printEnemies(roomStack& s, enemy enemy[], playerInfo& p)
{
	if (this->roomID == s.front())     //if enemy exists in the room
	{
		if (this->status != 0) //if enemy is not deceased
		{
		
			if (this->name == "Goblin")
			{
				cout << ">Event: You encounter a goblin !" << endl;
				this->fight(p, enemy);
				return 1;
			}
			else if (this->name == "Spartacus the eagle")
			{
				cout << ">Event: You encounter Spartacus The Eagle !" << endl;
				this->fight(p, enemy);
				return 1;

			}
			else
			{
				cout << ">Event: You encounter a Dragon !" << endl;
				this->fight(p, enemy);
				return 1;

			}
		}
		
	}
}

void enemy::fight(playerInfo& p, enemy enemy[])
{
	while (true)
	{
		if (this->health <= 0)
		{
			cout << " ! You have slayed the enemy. " << endl;
			this->status = 0;
			return;
		}
		else if (p.health <= 0)
		{
			cout << " !! You have been defeated... " << endl;
			return;
		}

		if (this->speed > p.speed) //enemy attacks first if faster
		{
			int attackNo = rand() % 2;
			int attack = enemyatk(this->enemyID,this->strength,this->speed,attackNo, p); //calculating the damage
			p.health -= attack; //player takes damage
		}

		int playerAtk= p.playerAtk(*this);

		
	}
}

int playerInfo::playerAtk(enemy& e)
{
	int atk = 0, choice;
	bool hasSword = this->inv.checkInven("Sword");
	bool hasHammer = this->inv.checkInven("Hammer");
	bool hasBomb = this->inv.checkInven("Bomb");

	cout << "\n=== Choose Your Action ===" << endl;
	if (hasSword) cout << "1. Use Sword" << endl;
	if (hasHammer) cout << "2. Use Hammer" << endl;
	if (!hasSword && !hasHammer) cout << "1. Punch or Kick (Unarmed)" << endl;
	if (hasBomb) cout << "3. Throw Bomb" << endl;

	// Choose your category
	while (true)
	{
		cout << "Enter your choice: ";
		cin >> choice;

		// Sword Attacks
		if (choice == 1 && hasSword)
		{
			cout << "\nChoose your Sword attack:" << endl;
			cout << "1. Blade Rush\n2. Crescent Slash" << endl;
			while (true)
			{
				cin >> choice;
				if (choice == 1)
				{
					cout << "-> You used: Blade Rush!" << endl;
					atk = (this->strength * 1.2) + (this->speed * 0.8);
					break;
				}
				else if (choice == 2)
				{
					cout << "-> You used: Crescent Slash!" << endl;
					atk = (this->strength * 1.5) + (this->speed * 0.5) + 5;
					break;
				}
				else cout << "* Invalid option." << endl;
			}
			break;
		}

		// Hammer Attacks
		else if ((choice == 2 && hasHammer) || (choice == 1 && !hasSword && hasHammer))
		{
			cout << "\nChoose your Hammer attack:" << endl;
			cout << "1. Hammer Slam\n2. Shockwave Smash" << endl;
			while (true)
			{
				cin >> choice;
				if (choice == 1)
				{
					cout << "-> You used: Hammer Slam!" << endl;
					atk = (this->strength * 1.3) + (this->speed * 0.3);
					break;
				}
				else if (choice == 2)
				{
					cout << "-> You used: Shockwave Smash!" << endl;
					atk = (this->strength * 1.4) + (this->speed * 0.2);
					break;
				}
				else cout << "* Invalid option." << endl;
			}
			break;
		}

		// Bomb Attack
		else if ((choice == 3 && hasBomb) || (choice == 2 && !hasSword && !hasHammer && hasBomb))
		{
			cout << "You threw a BOMB!" << endl;
			atk = 50;
			this->inv.dropFromInventory("Bomb"); // one-time use!
			break;
		}

		// Unarmed Punch/Kick
		else if ((choice == 1 && !hasSword && !hasHammer && !hasBomb))
		{
			cout << "\nYou're unarmed. Choose:\n1. Punch\n2. Kick" << endl;
			while (true)
			{
				cin >> choice;
				if (choice == 1)
				{
					cout << "-> You used: Punch!" << endl;
					atk = (this->strength / 2) + (this->speed / 10) - 5;
					break;
				}
				else if (choice == 2)
				{
					cout << "-> You used: Kick!" << endl;
					atk = (this->strength / 2) + (this->speed / 8) - 2;
					break;
				}
				else cout << "* Invalid option." << endl;
			}
			break;
		}
		else
		{
			cout << "* Invalid choice, try again." << endl;
		}
	}

	atk = max(0, atk); // ensure no negative damage
	e.health -= atk;

	cout << "\t\t\t\tPlayer Health: " << this->health << endl;
	cout << "\t\t\t\tEnemy Health: " << e.health << endl;

	return atk;
}




int enemy::enemyatk(int id, int str, int speed,int atk, playerInfo& p)
{
	int attack=10;
	if (id == 0)
	{
		if (atk == 1) //punch
		{
			cout << "] The goblin used: Punch" << endl;
			attack = str * (1 + speed / 200);
			attack -= 10;
			cout << "\t\t\t\tPlayer Health: " << p.health << endl;
			cout << "\t\t\t\tEnemy Health: " << this->health << endl;


		}
		else //kick
		{
			str = str - 5;
			cout << "] The goblin used: Kick" << endl;
			attack = str * (1 + speed / 200);
			attack -= 15;
			cout << "\t\t\t\tPlayer Health: " << p.health << endl;
			cout << "\t\t\t\tEnemy Health: " << this->health << endl;

		}
	}

	return attack;
}