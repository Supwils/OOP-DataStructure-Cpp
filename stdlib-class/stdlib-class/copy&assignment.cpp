//Initializer_List, Copy constructor, Copy assignment, destructor, deep and shallow copy/assign/destruct
#include <iostream>
#include <vector>

using namespace std;

template <class T> class node {
public:
    T value;
    node<T>* next;
    node() { next = nullptr; }
    node(T i) {value = i; next = nullptr;}
};

template <class T> class LinkedList {
public:
    node<T>* head;
    LinkedList() { head = nullptr; cout << "Default Constructor" <<endl; }
    LinkedList(int m, T n);//Constructor ; m nodes with random values in 0 ... n-1
    LinkedList(const initializer_list<T>& I);//Initializer_List
    LinkedList(const LinkedList<T>& L);//Copy Constructor
    void operator=(const LinkedList<T>& L);//copy assignment
    ~LinkedList();//Destructor

};
template <class T> LinkedList<T>::~LinkedList() {//Destructor

    while (head) {
        node<T>* p1 = head->next;
        delete head;
        head = p1;
    }
    cout << "Destructor" << endl;

}



template <class T> void LinkedList<T>::operator=(const LinkedList<T>& L) {//Copy Assignment
    while (head) {
        node<T>* p1 = head->next;
        delete head;
        head = p1;
    }

    node<T>* p1{ L.head }, * p2;
    while (p1) {
        p2 = new node<T>{};
        p2->next = head;
        head = p2;
        p1 = p1->next;
    }
    p1 = L.head;
    p2 = head;
    while (p1) {
        p2->value = p1->value;
        p1 = p1->next;
        p2 = p2->next;
    }

    cout << "Copy Assignment" << endl;


}



template <class T> LinkedList<T>::LinkedList(const LinkedList<T>& L): LinkedList<T>{} {//Copy Constructor
    //head = nullptr;

    node<T>* p1{ L.head }, *p2;
    while (p1) {
        p2 =  new node<T>{} ;
        p2->next = head;
        head = p2;
        p1 = p1->next;
    }
    p1 = L.head;
    p2 = head;
    while (p1) {
        p2->value = p1->value;
        p1 = p1->next;
        p2 = p2->next;
    }

    cout << "Copy Constructor" << endl;
}

template <class T> LinkedList<T>::LinkedList(const initializer_list<T>& I): LinkedList<T>{} {//Initializer_List
    //head = nullptr;
    auto p = I.end()-1;
    while (p != I.begin() - 1) {
        node<T>* p1{ new node<T>{*p} };
        p1->next = head;
        head = p1;
        --p;
    }
    cout << "Initializer_List" << endl;


}
template <class T> LinkedList<T>::LinkedList(int m, T n) : LinkedList<T>{} {//Constructor
    //head = nullptr;
    for (int i = 0; i < m; ++i) {
        node<T>* p1{ new node<T>(rand() % n) };
        p1->next = head;
        head = p1;
    }
    cout << "Constructor" << endl;
}

template <class X> ostream& operator<<(ostream& str, const LinkedList<X>& L);


int main() {
    LinkedList<int>  L1(15, 10);//will call constructor with {) rather than {}
    cout << L1 << endl;
    //LinkedList<int>

    LinkedList<int> L2 { 3,4,5,6,7,8,9 };//3 4 5 6 7 8 9
    cout << L2 << endl;
    LinkedList<int> L3{ 15,10 };//will call initializer_list
    //initializer_list > constructor > aggregate initilaiziton

    //vector<int> V{ 3,4,5,6 };

    //shallow vs deep copy and assignment

    LinkedList<int> L4{ L2 };//will call copy constructor
    cout << L4 << endl;
    cout << L2 << endl;
    L4.head->value = 25;
    cout << L4 << endl;
    cout << L2 << endl;
    cout << "*********" << endl;




    L3 = L4;//will call copy assignment
    L3.head->next->value = 100;
    cout << L3 << endl;
    cout << L4 << endl;





    LinkedList<int> L5 = L4;// the same as LinkedList<int> L5 { L4};  will call copy constructor not
    //copy assignment
    /*
    Under the following 3 cases will copy constructor be called by system:
    (1) When an object is declared and initialized to another object in the same statement.
    (2) Call by value
    (3) Return by value
    */


    {
        LinkedList<int> L6{ L4 };

    }

    //cout << L6 << endl;  Error!  L6 has been deleted by destructor


    return 0;
}

template <class X> ostream& operator<<(ostream& str, const LinkedList<X>& L) {
    node<X>* p1{ L.head };
    str << "{ ";
    while (p1) {
        str << p1->value << " ";
        p1 = p1->next;
    }
    str << "}";
    return str;
}
