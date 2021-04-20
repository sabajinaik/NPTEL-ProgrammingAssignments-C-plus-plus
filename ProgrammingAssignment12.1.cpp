/*We build a program that manages (very simplified) information about highways in the country. The program is to accept commands from the user and execute them until the user types a "T" (for terminate) command. Here are the different commands:

A <city1> <city2> <length>

This is for adding information to the data structure. The information to be added is: there is a
highway from <city1> to <city2> of the given length.

HL <city1> <city2>

This should print the length of the highway from <city1> to <city2> if such a highway exists. If 
there is no such highway, -1 should be printed.

R <city1>

This should print the names of the cities that are reachable from <city1> using a
single highway, each on a new line.

T

This should terminate the program.

You are only to write the functions which implement the commands HL and R. The signatures for 
them look like:
double HL(string s, string d, vector<disttype> dTable)
void R(string s, vector<disttype> dTable)

The main program is given which does the rest.
*/

#include <bits/stdc++.h>
using namespace std;
struct disttype {
    string origin, dest;
    double distance;
};
//This should print the names of the cities that are reachable from <city1> using a single highway, each on a new line.
void R(const string city1, vector<disttype>& dTable) {
    for (vector<disttype>::iterator it = dTable.begin(); it != dTable.end(); ++it) {
        if (it->origin == city1 || it->dest == city1) cout << ((it->origin == city1) ? it->dest : it->origin) << endl;
    }
}

//This should print the length of the highway from <city1> to <city2> if such a highway exists. If there is no such highway, -1 should be printed.
double HL(const string city1, const string city2, vector<disttype>& dTable) {
    double result = -1.0;
    vector<disttype> tempTable;
    for (vector<disttype>::iterator it = dTable.begin(); it != dTable.end(); ++it) {
        if (it->origin == city1 || it->dest == city1) {
            disttype from_to_city_map;
            from_to_city_map.origin = (it->origin == city1) ? (it->origin) : (it->dest);
            from_to_city_map.dest = (it->origin == city1) ? (it->dest) : (it->origin);
            from_to_city_map.distance = it->distance;
            tempTable.push_back(from_to_city_map);
        };
    }

    for (vector<disttype>::iterator it = tempTable.begin(); it != tempTable.end(); ++it) {
        if (it->dest == city2) return it->distance;
    }
    return -1;
}
int main() {
    vector<disttype> dTable;

    while (true) {
        string cmd; cin >> cmd;
        if (cmd == "T") break;
        else if (cmd == "A") {
            disttype entry;
            cin >> entry.origin >> entry.dest >> entry.distance;
            dTable.push_back(entry);
        }
        else if (cmd == "R") {
            string city1; cin >> city1;
            R(city1, dTable);
        }
        else if (cmd == "HL") {
            string city1, city2;
            cin >> city1 >> city2;
            cout << HL(city1, city2, dTable) << endl;
        }
        else {}
    }
}
