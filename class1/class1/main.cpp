//
//  main.cpp
//  class1
//
//  Created by 尚华豪 on 1/25/22.
//

#include <iostream>
using namespace std;
void f1(int i){cout << "call by value"<<i++<<endl;};// copy the value of i, new oject created two copy of value
void f2(int& i){cout<<"call by reference"<<i++<<endl;}; //the same object, refer to the outside called object. directly affert the outside object
class threed{
public:
    int num1,num2,num3;
    int val(){return num1*num2*num3;}
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int j{100};
    int* p1(&j);
    
    cout << "Hello, World!\n"<<endl;

    cout << p1<<"  "<<*p1<<endl;
    
    *p1 = 1000;
    cout<<*p1<<endl;
    cout<<j<<endl;
    int A[5]{1,2,3,4,5};
    cout<<*(A+1)<<endl;
    //dynamic object (in heap) globle
    int* p4 = new int{5};
    /*new requeste a memory space from system for an int object.
    */
    cout<<*p4<<" "<< p4 + 1<< endl;
    
    delete p4;//delete the obejct
    p4 = new int;
    //int age;
    //cin>>age;
    
    int B[2][2]={{54,6},{1,2}};
    cout << (*(B[1]+1));
    threed people{1,2,3};
    cout<< people.val()<<endl;
    threed* p2 = new threed{2,2,2};
    cout << p2->val()<<endl;
    return 0;
}
