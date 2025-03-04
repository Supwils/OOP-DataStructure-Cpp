//
//  copy.cpp
//  class2
//
//  Created by 尚华豪 on 2/22/22.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
template<class T> class node{
public:
    T value;
    node<T> next;
    node(){next = nullptr;}
    node(T i){value = i; next = nullptr;}
};
template<class T> class Listlist{
public:
    node<T> head;
    LinkedList(){head = nullptr; cout<<"DC";}
    LinkedList (int m , T n);
    
}
