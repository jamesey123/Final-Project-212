//Apartment.h
#ifndef APARTMENT_H_
#define APARTMENT_H_

#include "graph.h"
#include <set>
#include <string>

using namespace std;

namespace APARTMENT
{
    class Apartment
    {
    public:
        graph<string>* apartment;
        // CONSTRUCTOR
        Apartment() {
            apartment = new graph<string>();
        }
        //Apartment(const string& file_name);
        // MODIFICATION MEMBER FUNCTIONS
        void moveIn(const string& name);
        void addRoommate (const string& first_name, const string& second_name);
        void removeRoomate (const string& first_name, const string& second_name);
        // CONST MEMBER FUNCTIONS
        std::set<string> roommates(const string& name);
        std::set<string> commonRoommate (const string& first_name, const string& second_name);
        bool isRoommate (const string& first_name, const string& second_name);
    private:
        //graph<string>* create_graph();
        size_t get_index (const graph<string>& g, const string& target);
    };
}

#endif /* APARTMENT_H_ */
