#include<iostream>
#include<iomanip>
#include <chrono>
#include <thread>
#include<string>
#include<vector>
#include "roomStructs.h"
using namespace std;

extern room r[11];

string printRoomName(int id)
{
	if (id >= 0 && id <= 11) {
		return r[id].name;
	}
	else return "unknown";
}

void typewriterPrint(const string& line, int delay = 50) {
    for (char c : line) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

void welcome() {
    vector<string> introLines = {
        "You wake up in the hall, battered and bruised.",
        "You look around you; there's barely any light to illuminate the area.",
        "You only have one option, and that is to keep moving forward and surviving. No matter what it takes.",
        "There's a backpack next to you. You pick it up.",
        "Now you can hold items while you move across rooms. But beware, there is a limit.",
        "Go now. Make it to the final gate."
    };

    for (const string& line : introLines) {
        typewriterPrint(line, 30);  
        this_thread::sleep_for(chrono::milliseconds(500)); 
    }
}
