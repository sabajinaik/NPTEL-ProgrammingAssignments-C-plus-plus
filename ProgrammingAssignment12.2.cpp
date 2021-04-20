/*You are to write a program that manages (very simplified) information about highways in the
country. The information is stored in a map (explained later). The program is to accept
commands from the user and execute them until the user types an "T" (for terminate) command.
Here are the different commands:

        ->A <city1> <city2> length

        This is for adding information to the map. The information to be added is: there is
        a highway from <city1> to <city2> of the given length

        ->HL <city1> <city2>
        This should print the length of the highway from <city1> to <city2>, if such a
        highway exists. If there is no such highway, -1 should be printed.

        ->R <city1>
        This should print the names of the cities that are reachable from <city1> using a single
        highway, each on a newline.

        ->T
        This should terminate the program.
    You are only to write the functions which implement the commands HL and R. A main
    program is given which does the rest.

    The main function declares and uses a two-level map dTable to store the information
    regarding the highways as can be seen in the code provided below. Each entry of the map
    has a key corresponding to a city name, say C1. The value for this entry is another map
    storing (city name, length) key-value pairs for all cities connected to C1 via a highway.
*/

#include <iostream>
#include<cmath>
#include <map>
using namespace std;
#define main_program int main()
typedef map<string, map<string, int>> tabletype;


//This should print the names of the cities that are reachable from <city1> using a single highway, each on a new line.
void R(const string city1, tabletype& dTable) {
    for (auto srcTargetDistance : dTable) {
        if (srcTargetDistance.first == city1) {
            map<string, int> targetDistance = srcTargetDistance.second;
            for (auto destCity : targetDistance) if (destCity.second != 0) cout << destCity.first << endl;
            return;
        }
    }
}

//This should print the length of the highway from <city1> to <city2> if such a highway exists. If there is no such highway, -1 should be printed.
double HL(const string city1, const string city2, tabletype& dTable) {
    double result = -1.0;
    tabletype::iterator it = dTable.find(city1);
    if (it != dTable.end()) {
        int distance = it->second[city2];
        if (distance != 0) return distance;
    }
    return -1;
}
int main() {
    tabletype dTable;
    while (true) {
        string cmd; cin >> cmd;
        if (cmd == "T") break;
        else if (cmd == "A") {
            string city1, city2;
            double dist;
            cin >> city1 >> city2 >> dist;
            dTable[city1][city2] = dist;
            dTable[city2][city1] = dist;
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