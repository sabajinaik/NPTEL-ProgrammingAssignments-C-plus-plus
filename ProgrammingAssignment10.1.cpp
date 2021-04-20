/*You are supposed to define a Histogram class to store Histogram objects. A histogram is a sequence of integers.
The size of a histogram is the number of integers stored in it. Your class should have only and all of the
following public methods :

Histogram (int n) : A constructor which takes an integer n as argument and initializes a Histogram object with
a sequence of n integers, indexed [0,n-1], all set to 0.
Histogram () : A default constructor. This generates an empty histogram with an empty sequence. In essence, this
is same as passing 0 to the previous constructor.
void add (int i) : This member function adds 1 to the value stored at index i. If the index i is out of range,
print a message saying “Invalid update performed” with a newline.
void print() const : This member function prints the sequence in order 0 to n-1. Each integer is to be separated
by a space and there should be a newline at the end. This is already implemented for you. If you are unfamiliar
with the syntax, we recommend reading about it over the internet.
Histogram operator + (const Histogram &h) const : An overloaded operator + to add 2 histograms. Addition of 2
histograms is defined as follows : suppose H1 has a size of n and H2 has a size m and suppose n>=m, then the first
m entries of H3 = H1+H2 are the sum of entries of H1 and H2 and the remaining entries are copied from H1 as is.
*/

#include <iostream>
#include <vector>

using namespace std;
class Histogram {
    vector <int> seq;
public:
    // define all the methods

    Histogram() {
        //default constructor
        Histogram(0);
    }
    Histogram(int n) {
        //parameterized constructor
        seq.resize(n, 0);
    }
    void add(int i) {
        if (i >= seq.size()) cout << "Invalid update performed" << endl;
        else seq[i] = seq[i] + 1;
    }

    void print() const
    {
        for (auto val : seq) cout << val << " ";
        cout << endl;
    }

    Histogram operator+(const Histogram& h) const {
        Histogram* temp;
        int rhsSize;
        temp = new Histogram;
        temp->seq = seq;

        rhsSize = h.seq.size();
        if (rhsSize > temp->seq.size()) temp->seq.resize(rhsSize, 0);
        for (int i = 0; i < h.seq.size(); i++) temp->seq[i] = temp->seq[i] + h.seq[i];
        return *temp;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    Histogram h1(n), h2(m);
    Histogram h3;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int hist, index;
        cin >> hist >> index;
        if (hist == 0) h1.add(index);
        if (hist == 1) h2.add(index);
    }
    h1.print();
    h2.print();
    h3 = h1 + h2;
    h3.print();
}