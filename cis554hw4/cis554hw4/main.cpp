//HW4 Due: 11:59pm, Wednesday, March 2, 2022

#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;


//void DB2_to_DB3(List<vector>)

int main() {
    course C1("CIS554", 1, 3, "A-"), C2("CSE674", 1, 3, "B+"), C3("MAT296", 8, 4, "A"), C4("WRT205", 5, 3, "A");
    course C5("CIS351", 2, 3, "A-"), C6("PSY205", 5, 3, "B+"), C7("MAT331", 2, 3, "A"), C8("ECN203", 4, 3, "A");


    Record<course> R1{ {10, { {12, C1}, {9, C2}  }},
        {7, {{8, C3}, {3, C4}, {1, C5}}},{4, {{21, C6}, {15, C7}} } };

    //cout << R1 << endl;


    //Record<course> R2{ R1 };
    //cout << R2 << endl;

    //Record<course> R3;
    //R3 = R1;
    //cout << R3 << endl;

    //R3 = R1.deleteFirst();
    //cout << R3 << endl;

    //R3 = R3;
    //cout << R3 << endl;

    return 0;
}


