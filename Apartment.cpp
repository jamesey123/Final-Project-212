//Apartment.cpp

#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include "Apartment.h"
#include "graph.h"

using namespace std;

namespace APARTMENT
{
    // constructor takes in a file and creates a graph base on the contents of the file
    /*  Apartment::Apartment(const string& file_name) {
     apartment = create_graph(file_name);
     }
     */
    void Apartment::moveIn(const string& name){
        apartment->add_vertex(name);
    }
    // addRoomate takes in two string names and creates an edge between them
    // it does this by finding the index of the two names and using them as
    // parameters in add_edge which accepts two parameters, but before it can do this
    // we must add the new vertice, which is the second name.
    void Apartment::addRoommate(const string& first_name, const string& second_name) {
        size_t m, n;
        //apartment->add_vertex(second_name);
        m = get_index(*apartment, first_name);
        n = get_index(*apartment, second_name);
        apartment->add_edge(m, n);
    }
    
    // remove the edge between two vertices,
    // it first finds the index of the two strings in order to locate the vertices and
    // removes the edge between them.
    void Apartment::removeRoomate(const string& first_name, const string& second_name) {
        size_t m, n;
        m = get_index(*apartment, first_name);
        n = get_index(*apartment, second_name);
        apartment->remove_edge(m, n);
    }
    
    
    set<string> Apartment::roommates(const string& name) {
        size_t n;
        string f_name;
        set<size_t> f_i_set;
        set<string> f_set;
        // get the index of the name
        n = get_index(*apartment, name);
        
        // fine the indexes of all the the vertices that are neighbors to n
        // and place them in the set f_i_set
        f_i_set = apartment->neighbors(n);
        // create an iterator for the set, and iterate the set f_i_set
        for (set<size_t>::iterator it = f_i_set.begin(); it != f_i_set.end(); it++) {
            // insert the strings associated with index into f_set
            f_set.insert((*apartment)[*it]);
        }
        return f_set;
    }
    
    set<string> Apartment::commonRoommate (const string& first_name, const string& second_name) {
        //TODO: common_friends
        // will implement a set-intersect method
        size_t m, n;
        set<string> f_set;
        // create two sets to store the index of each names neighbor
        set<size_t> f_i_set1;
        set<size_t> f_i_set2;
        // get the vertex index of the two names
        m = get_index(*apartment, first_name);
        n = get_index(*apartment, second_name);
        // store the index of the two names index in the sets f_i_set1 and f_i_set2
        f_i_set1 = apartment->neighbors(m);
        f_i_set2 = apartment->neighbors(n);
        // itorate the neighbors of the first name  and if you find it in the second second set
        // insert it to f_set
        for (set<size_t>::iterator it = f_i_set1.begin(); it != f_i_set1.end(); it++) {
            if (f_i_set2.find(*it) != f_i_set2.end())
                f_set.insert((*apartment)[*it]);
        }
        return f_set;
    }
    
    
    // checks if there is an edge between two vertices
    bool Apartment::isRoommate(const string& first_name, const string& second_name) {
        size_t m, f;
        m = get_index(*apartment, first_name);
        f = get_index(*apartment, second_name);
        return apartment->is_edge(m, f);
    }
    
    
    // this is used to get the index of a specific vertice
    size_t Apartment::get_index (const graph<string>& g, const string& target) {
        size_t i = 0;
        while (i < g.size() && g[i] != target)
            ++i;
        // made sure i is not greater than the size of the graph.
        assert (i < g.size());
        return i;
    }
    
    
}
