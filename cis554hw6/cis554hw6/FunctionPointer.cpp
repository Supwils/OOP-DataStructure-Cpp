//Function Pointers
#include <iostream>
#include <list>

using namespace std;

bool f1(int i, int j) { return i < j; }
bool f2(int i, int j) { return i % 5 < j % 5; }

int Min(int a, int b, bool (* comp)(int i, int j)) {//function pointer as a parameter
    return comp(a, b) ? a : b;
}


int main() {

    list<int> L1{ 7, 10, 14, 5,12 };
    L1.sort();//5 7 10 12 14
    L1.sort(f2);//5 10 7 12 14 or eqivalent

    //function pointer
    bool (*fp) (int a, int b);
    fp = f1;//function name without augument is the address of function in memory
    cout << fp(3, 5) << endl;//1  true   fp is f1


    fp = f2;
    cout << fp(3, 5) << endl;//0 false  fp is f2
    
    cout << Min(3, 5, f1) << " " << Min(3, 5, f2) << endl;//3 5

    return 0;
}
