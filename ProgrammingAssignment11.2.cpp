/*You are provided with the details of various flights available on a day. This will be
followed by some queries. The queries will be of type: You are given the names of two
cities, say city A and city B, and a departure time, say T. You have to write a program to
print the earliest time ON THE SAME DAY at which you can reach city B starting from
city A using a single flight departing on or after time T. This is to be done for every query.

Note:
1. The names of cities will be a single word. For example, “New Delhi” will be given as
“NewDelhi”.
2. The various times will be given as simple numbers. For example, 8:30 AM will be
given as 830 whereas 8:30 PM will be given as 2030.
Also, 12:00 AM (and similarly for any 12:xx AM) will be given as 0.
3. The problem statement requires you to find the EARLIEST time and not the
SHORTEST travel time.

Input
#Input starts with details of flights as given below:
#The end of the flight details is given by an asterisk.
*
#Followed by an integer N
N
#Followed by N queries in the following manner.
??????????1 ??????????1 ??1
...
???????????? ???????????? ????
Hint - You should store the flight details in a map with the key as the pair of the
departure city and arrival city, and the value as a vector of arrival times.
This will help you comfortably store the input as well as efficiently use it in the program.

Output
For every query, print the earliest time ON THE SAME DAY at which city B is reachable
from city A using a single flight departing on or after time T in a newline.
If there is no flight from A such that it departs after T and reaches B on the same day,
output -1.
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <iomanip>
#include <iterator>
#include <algorithm>
using namespace std;
#define main_program int main

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef pair<pair<string, int>, pair<string, int> > schedule;

class ArrivalDepartureSchedule {
    vector<schedule> arrivalDeparture;
public:
    void fetchDepartureArrival() {
        string parameter1;
        pair<string, int> departure, arrival;
        while (true) {
            cin >> parameter1;
            if (parameter1 == "*") break;
            int parameter2, parameter4;
            parameter2 = parameter4 = 0;
            string parameter3;
            cin >> parameter2 >> parameter3 >> parameter4;
            arrivalDeparture.push_back(make_pair(make_pair(parameter1, parameter2), make_pair(parameter3, parameter4)));
        }
    };

    int evaluateEarliestTravelTime(const string fromCity, const string toCity, const int asofTime) {
        int minTime = -1;
        //scope to optimize the code by using the out-of the box sort features provided by STL. No time :(
        for (vector<schedule>::iterator it = arrivalDeparture.begin(); it != arrivalDeparture.end(); ++it) {
            if (it->first.first == fromCity && it->second.first == toCity
                && it->first.second >= asofTime && it->second.second > it->first.second) {
                if (minTime == -1) minTime = it->second.second;
                else if (it->second.second < minTime) minTime = it->second.second;
            };
        };
        return minTime;
    };
};

int main()
{
    int totalVerificationInputs = 0;
    ArrivalDepartureSchedule scheduleObject;
    scheduleObject.fetchDepartureArrival();

    cin >> totalVerificationInputs;
    for (int i = 0; i < totalVerificationInputs; i++) {
        string fromCity, toCity;
        int asofTime;
        cin >> fromCity >> toCity >> asofTime;
        cout << scheduleObject.evaluateEarliestTravelTime(fromCity, toCity, asofTime) << endl;
    }
}