//
//  stdexamexample.cpp
//  binarytree
//
//  Created by 尚华豪 on 3/8/22.
//  Copyright © 2022 尚华豪. All rights reserved.
//
#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

//struct{
//
//    vector<map<int, list<int> >> Data1;
//    map<int, vector<list <vector<int>>>> Data2;
//};
class Myclass{
public:
    static int New_Objects;
    Myclass(){
        New_Objects++;
        
    }
    ~Myclass(){
        New_Objects--;
    }
    static int getnum(){
        return New_Objects;
    }
};
 int Myclass::New_Objects = 0;

void f1(int k){
    static int count{0};
    count += k*k;
    cout<<count<<endl;
}

int main(){
    Myclass C1;
    Myclass C2;
    
    cout<<Myclass::New_Objects<<endl;
    cout<<C2.getnum()<<endl;
    
    f1(1);
    f1(2);
    f1(4);
}
