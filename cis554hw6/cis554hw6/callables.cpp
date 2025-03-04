
#include <iostream>
#include <list>


using namespace std;


//functor
class myFunctorClass {
public:
    int value;
    myFunctorClass() { value = 0; }
    myFunctorClass(int i) { value = i; }


    int operator()(int k) { return k * k; }//functor
    //int operator[](int k)

    bool operator()(int i, int j) { return i % 4 < j % 4; }

};


bool cp1(int i, int j) { return i % 3 < j%3; }


int main() {
myFunctorClass m1(5);
    cout << m1(10) << endl;//m1(10) looks like a function call
    //cout << m1[3]

    list<int> L1{ 3,1,5,9,2 };
    //L1.sort(cp1);
    //L1.sort(m1);

    L1.sort([](int i, int j) {return i > j; });//lambda
    for (auto& i : L1)  cout << i << " ";
    cout << endl;



    

    return 0;

}
