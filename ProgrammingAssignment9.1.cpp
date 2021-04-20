/*Define a structure [1] for representing axis-parallel rectangles, i.e. rectangles whose sides are parallel
to the axes. An axis parallel rectangle can be represented by the coordinates of the diagonally opposite
points. Then, write a function [2] that takes an array of rectangles (axis parallel) and a point as arguments,
and determine how many rectangles the point is inside of.

[1] - struct Rectangle

[2] - int num_inside( Rectangle r[], int sz, int px, int py)

where

r is the rectangle array.

sz is the size of the array (n below)

px is the x coordinate of the point

py is the y coordinate of the point.

Using the above structure and function, solve the below problem.

INPUT DETAILS

You will be given n, the number of rectangles in the 2d plane. Then there will be n lines giving the coordinates
of diagonally opposite points i.e. bottom left (say (x1, y1)) and top right corner (say (x2, y2)) of the rectangle
in the format.

x1 y1 x2 y2

Then the program will give you several queries in the form of

x y

for each such query, you have to output the number of rectangles (out of n) the point (x, y) lies inside of in a
new line. By inside of, we mean that point can be properly inside or can be on the boundary too!

The last query will be -1 -1 upon which you can exit the program without printing anything. (the point (-1, -1)
will not be queried for any time during the program).
*/
#include <iostream>
#define repeat(x) for(int _iterator_i = 0; _iterator_i<x;_iterator_i++)
#define main_program int main()
#include <cmath>
using namespace std;
struct Rectangle {
	int x1, y1;
	int x2, y2;
};

int num_inside(Rectangle r[], int sz, int px, int py) {
	int total = 0;

	for (int i = 0; i < sz; i++) {
		if ((px >= r[i].x1 && px <= r[i].x2) &&
			(py >= r[i].y1 && py <= r[i].y2)) {
			total++;
		}
	}
	return total;
}
int main() {
	int n; cin >> n;
	Rectangle r[n];
	for (int i = 0; i < n; i++) cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
	while (true) {
		int px, py; cin >> px >> py;
		if (px == -1 && py == -1) break;
		cout << num_inside(r, n, px, py) << endl;
	}
}
