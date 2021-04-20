/*Design a class named Student. The class should have the following data members:

char Name[100] ( This is to say that you will not deal with name longer than 99 characters)

int EnglishMarks[4]

int MathsMarks[4]

EnglishMarks represents the marks of a student in 4 different English Examinations. MathsMarks
represents the marks of a student in 4 different Maths Examinations

Write a constructor to initialize the instance of Student, it takes as input the string and the
arrays given below, and initializes the data structures accordingly.

Write a member function avg that takes as input a character and returns a double.The character
is described below

The char is  ‘E’ : return the average in English across the four marks

The char is ‘M’ : return the average in Maths across the four marks

It is anything else: return -1

Note that the second argument, if present will be a char.

Now define the < operator for Student class to compare the performance of the two students. The
operation (s1<s2) must return true when the sum of marks of s1 is less than that of s2, and false
otherwise. Note that by sum we mean the sum of all eight marks, the four of English and the four of
maths

To aid you, please copy paste the following template in the editor and fill in the code where
indicated by the template:

class Student{
public:
    char name[100];
    int EnglishMarks[4];
    int MathsMarks[4];
    Student(){}
    Student(char* nam_inp, int em[4], int mm[4]){
      Copy the characters from nam_inp into name, DO NOT set name=nam_inp as this will just make
     them point to the same address, and will cause an error.You can use a for loop to do this. Similarly,
     copy the values from em into EnglishMarks and mm into MathsMarks
    }

    double avg(char subject) {
        //Write the function as described above
    }

    bool operator<(Student s2) {
        //Write the function as described above
    }
};
*/
#include<iostream>
#include<string>
#include <cstring>
using namespace std;

class Student {
public:
    char name[100];
    int EnglishMarks[4];
    int MathsMarks[4];

    //default constructor
    Student() {}
    //parameterized contructor
    Student(char* nam_inp, int em[4], int mm[4]) {
        int i = 0;
        for (i = 0; nam_inp[i] != '\0'; i++) name[i] = nam_inp[i];
        name[i] = '\0';
        for (i = 0; i < 4; i++) {
            EnglishMarks[i] = em[i];
            MathsMarks[i] = mm[i];
        }
    }
    double avg(char subject) {
        if (subject == 'E') return ((double)(EnglishMarks[0] + EnglishMarks[1] + EnglishMarks[2] + EnglishMarks[3])) / 4.0;
        else if (subject == 'M') return ((double)(MathsMarks[0] + MathsMarks[1] + MathsMarks[2] + MathsMarks[3])) / 4.0;
        else return -1.0;
    }
    bool operator<(Student s2) {
        if (avg('M') + avg('E') < s2.avg('M') + s2.avg('E')) return true;
        else return false;
    }
};
int main() {
    int n;
    cin >> n;
    Student students[10];
    for (int i = 0; i < n; i++) {
        char name[100];
        int Maths[4];
        int English[4];
        scanf("%s", name);

        for (int j = 0; j < 4; j++) {
            cin >> English[j];
        }
        for (int j = 0; j < 4; j++) {
            cin >> Maths[j];
        }
        Student curr = Student(name, English, Maths);
        students[i] = curr;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char name[100];
        scanf("%s", name);
        char mode;
        cin >> mode;
        for (int j = 0; j < n; j++) {
            if (strcmp(name, students[j].name) == 0) {
                cout << students[j].avg(mode) << endl;
                break;
            }
        }
    }
    char name1[100], name2[100];
    scanf("%s", name1);
    scanf("%s", name2);
    Student s1, s2;
    for (int i = 0; i < n; i++) {
        if (strcmp(name1, students[i].name) == 0) {
            s1 = students[i];
        }
        if (strcmp(name2, students[i].name) == 0) {
            s2 = students[i];
        }
    }
    if (s1 < s2) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}