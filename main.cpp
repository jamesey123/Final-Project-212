//main.cpp
#include <cassert>
#include <iostream>
#include <set>
#include "Apartment.h"

using namespace APARTMENT;
using namespace std;

int main() {
    
    set<string>::iterator it;
    
    Apartment a;
    
    a.moveIn("Luffy");
    a.moveIn("Naruto");
    a.moveIn("Goku");
    a.moveIn("Ace");
    a.moveIn("Sasuke");
    a.moveIn("Vageta");
    cout << "Luffy moved into the apartment complex" << " " << endl;
    cout << "Naruto moved into the apartment complex" << " " << endl;
    cout << "Goku moved into the apartment complex" << " " << endl;

    cout << "Ace moved into the apartment complex" << " " << endl;
    cout << "Sasuke moved into the apartment complex" << " " << endl;
    cout << "Vageta moved into the apartment complex" << " " << endl;
    
    a.addRoommate("Luffy","Naruto");
    a.addRoommate("Naruto","Luffy");
    a.addRoommate("Luffy","Goku");
    a.addRoommate("Goku", "Luffy");
    a.addRoommate("Goku", "Naruto");
    a.addRoommate("Naruto", "Goku");
    
    a.addRoommate("Ace","Sasuke");
    a.addRoommate("Sasuke","Ace");
    a.addRoommate("Ace","Vageta");
    a.addRoommate("Vageta", "Ace");
    a.addRoommate("Vageta", "Sasuke");
    a.addRoommate("Sasuke", "Vageta");
    
    assert(a.isRoommate("Luffy", "Naruto"));
    set<string> Roomates;

    cout << "Narutos Roomates are "; 

    Roomates = a.roommates("Naruto");
    for(it = Roomates.begin(); it != Roomates.end(); it++)
        cout << *it << ", ";
    
    cout << "The common roomates between Vageta and Ace is "; 
    
    Roomates = a.commonRoommate("Ace", "Vageta");
    for(it = Roomates.begin(); it != Roomates.end(); it++)
        cout << *it << " " << endl;
    return 0;
}




