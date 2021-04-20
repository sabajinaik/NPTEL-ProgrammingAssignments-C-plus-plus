/*C++ int variables usually use 4 bytes of space and it restricts their values to a range of [-2147483648,2147483647].
While this is a big range, in many applications, a much larger range of integers is desired. One can use long int and
long long int for various purposes but we would like to design an unbounded integer class, BigInt.

In this assignment, we define a BigInt class which can store arbitrary length integers. This class will store digits
of a big integer into a vector of integers. It is required to have the following public functionality :

BigInt() : A constructor which initializes the BigInt to 0. It is advised that an empty vector be initialized here.
Note that you need not do this yourself, the vector class does this automatically.

BigInt(string s)  : A constructor which takes a string s of numeric characters as input.

BigInt operator + (const BigInt& x) const : overloaded + operator which adds 2 bigints

bool operator < (const BigInt& x) const : overloaded < operator to compare 2 bigints

string str() const : returns the decimal representation as a string. For an empty vector, print “0”


You can be sure that s would not start with a ‘0’. Observe that there is no way to produce negative integers using
these methods so you need not deal with that.


We have created a function len(), which returns the length of the digits vector, this is purely to make your coding less tedious.

Note that you need not create a copy constructor or a destructor for this class if you use vectors. These actions will
automatically be performed by the methods for the vector class.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInt
{
    vector<int> digits;
    int len() const;
public:
    BigInt();
    BigInt(string);
    BigInt operator + (const BigInt&) const;
    bool operator < (const BigInt&) const;
    std::string str() const;
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    BigInt x(s1);
    BigInt y(s2);
    BigInt z;
    cout << z.str() << (z + z).str() << endl;
    cout << (x + z).str() << " " << (y + z).str() << endl;
    z = x + y;
    cout << (x < y) << endl;
    cout << z.str() << endl;
}
/*BigInt will use vector of integers
each integer will store 8 decimal places (last two decimal places will be used for carry over)
the carry over will be passed on from lower index to higher index

Use string to get data from the user - parse string from last 8 digit and fill the vector from back to front

Perform addition of two vectors from back to front the 9th digit will be a carry over to earlier index of an array

result vector will NOT need additional index (e.g. addition of 99999999 and 99999999 will result in 199999998)*/

BigInt::BigInt() {
    //default constructor
}

BigInt::BigInt(string s) {
    string temp = s;
    while (temp.length() > 8) {
        int offset = temp.length() - 8;
        digits.push_back(stoi(temp.substr(offset, 8)));
        temp = temp.substr(0, offset);
    }
    digits.push_back(stoi(temp));
}

string BigInt::str() const {
    string bigIntegerString = "";
    int max_index = digits.size();
    if (max_index == 0) return "0";
    for (int i = 0; i < max_index; i++) {
        string packetString = "";
        if (i == 0) {
            //not an interim array
            packetString = packetString.append(to_string(digits[max_index - i - 1]));
        }
        else {
            //number is not 8 digits pad the index with zero if interim vector
            string packetString1 = to_string(digits[max_index - i - 1]);
            string prefix((8 - packetString1.length()), '0');
            packetString = prefix.append(packetString1);
        }
        bigIntegerString = bigIntegerString.append(packetString);
    }
    return bigIntegerString;
}

BigInt BigInt::operator + (const BigInt& a) const {
    //add the integers and include carry over to next index of the vector
    BigInt resultInteger;
    int carryOver = 0;
    int max_index = (a.digits.size() > digits.size()) ? a.digits.size() : digits.size();
    if (digits.size() == 0 && a.digits.size() == 0) return resultInteger;
    for (int i = 0; i < max_index; i++) {
        int packetTotal = 0;
        //cout << "part1: " << ((i < digits.size()) ? digits[i] : 0) << endl;
        //cout << "part2: " << ((i < a.digits.size()) ? a.digits[i] : 0)<< endl;
        packetTotal = carryOver + ((i < digits.size()) ? digits[i] : 0) + ((i < a.digits.size()) ? a.digits[i] : 0);
        if (i == max_index - 1) {
            resultInteger.digits.push_back(packetTotal);
            //cout << "CarryOver Last: " << carryOver << endl;
            //cout << "PacketTotal Last: " << packetTotal << endl;
        }
        else {
            carryOver = (int)(packetTotal / 100000000);
            resultInteger.digits.push_back(packetTotal % 100000000);
            //cout << "CarryOver:" << carryOver << endl;
            //cout << "PacketTotal:" << packetTotal % 100000000 << endl;
        };
    };
    return resultInteger;
}

bool BigInt::operator < (const BigInt& a) const {
    //check packet sizes first - larger the size, bigger the number
    if (digits.size() < a.digits.size()) return true;
    else if (digits.size() > a.digits.size()) return false;
    //check individual contents if packet sizes are equal
    int max_index = digits.size();
    for (int i = 0; i < max_index; i++) {
        if (digits[max_index - i - 1] < a.digits[max_index - i - 1]) return true;
        else if (digits[max_index - i - 1] > a.digits[max_index - i - 1]) return false;
    }
    //both strings are equal
    return false;
}
