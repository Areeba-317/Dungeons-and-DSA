#include<iostream>
#include<iomanip>
#include "stack.h"
#include "list.h"
using namespace std;



roomStack::roomStack()   //intializing the stack
{
	top = new roomNode();
	top->id = 0;  //begin in the first room(entrance)
	top->next = nullptr;
}
void roomStack::push(int id)
{
	roomNode* node = new roomNode(id, NULL);

	node->next = top;
	top = node;

}

int roomStack::pop()
{
	int id = top->id;
	roomNode* temp = top;
	top = top->next;
	delete temp;
	temp = nullptr;
	return id;
}

bool roomStack::isEmpty() {
	if (top->next == nullptr)
	{
		return true;
	}
	else return false;
}

int roomStack::front()
{
	if (top->id == NULL)
	{
		return 0;
	}
	else return top->id;
}