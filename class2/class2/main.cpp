
//Linked List
#include <iostream>

using namespace std;

class ThreeD {
public:
    int ht;
    int wid;
    int dep;
    int vol() { return ht * wid * dep; }
    ThreeD(int i, int j, int k) : ht(2 * i), wid(2 * j), dep(2 * k) {} //constructor for initialization
    ThreeD(){}//default constructor
    /*
    alternatively,
    ThreeD(int i, int j, int k){ht = 2*i; wid = 2*j; dep = 2*k;     }
    */
};

class node {
public:
    int value;
    node* next;

    node(int i) { value = i; next = nullptr; }
    node() { next = nullptr; }//default constructor
};

class LinkedList {
public:
    node* head;// points to the first node of the linked list.
    LinkedList() { head = nullptr; }//default constructor
    LinkedList(int n, int m);//constructor an n-node linked list with random values in 0 ... m-1
    void print();
    void reverse();
    //void sort();

};




void LinkedList::reverse() {
    if (!head || !head->next) return; //0 or 1 node

//    node* p1{ head }, * p2, * p3;
//        p2 = p1->next;
//        while (p2) {
//            p3 = p2->next;
//            p2->next = p1;
//            if (p1 == head) p1->next = nullptr;
//            p1 = p2;
//            p2 = p3;
//        }
//        head = p1;
    node* nextNode, *prev = nullptr;
    while(head){
        nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    head = prev;

}





LinkedList::LinkedList(int n, int m) {
    head = nullptr;
    for (int i = 0; i < n; ++i) {
        node* p1 = new node{ rand() % m };
        p1->next = head;
        head = p1;
    }
}


void LinkedList::print() {
    node* p1{ head };
    while (p1) {//while (p1 != nullptr)
        cout << p1->value << " ";
        p1 = p1->next;
    }
}





int main() {

    int A[3]{ 1,2,3 };
    cout << 2[A] << " " << A[2] << endl; //*(2+A) or *(A+2)

    int* p1;
    p1 = nullptr;//NULL is out of date
    if (p1 == nullptr) cout << " p1 is not pointing to any object" << endl;
    if (!p1) cout << " p1 is not pointing to any object" << endl;//equivalent
    /*
    if (p1) is the same as if (p1 != nullptr)
    */


    ThreeD t1;
    t1.ht = 25;
    t1.wid = 14;
    ThreeD t2{ 1,2,3 };//ht = 1, wid = 2, dep = 3; aggregate initialization

    cout << t2.vol() << endl;// 48  constructor takes priority over aggregate initialization

    ThreeD* p2 = new ThreeD{ 2,2,2 };

    cout << (*p2).vol() << endl;//Nobody would use this.
    cout << p2->vol() << endl;//arrow or select






    char c1;
    double d1;
    float f1;



    LinkedList L1{ 20, 10 };
    L1.print();
    L1.reverse();
    cout << endl;
    L1.print();




    return 0;
}
