
//HW2 Due: 11:59pm, Wed. Feb. 16.
#include <iostream>

using namespace std;

class node { //for doubly linked list; double linked list
public:
    int value;
    node* next;
    node* previous;
    node(int i) { value = i; next = previous = nullptr; }
    node() { next = previous = nullptr; }

};


class DLinkedList {
public:
    node* head;
    node* tail;
    DLinkedList(int n, int m);//n nodes with random values in 0 ...m-1
    void print_F();
    void print_B();
    void sort();
    /*
    Sort the DLinkedList into asscending order.
    You are only allowed to modify next and previous of a node, but not value.
    You are not allowed to use any external stucture (such as array) to help.
    Do not introduce any additional function.
    You are required to implement selection sort.
    */

    // void removeAll(int k);
    /*
    Remove all nodes with value k.
    You are allow to modify  value, next, and previous of a node.
    You are not allowed to use any external stucture (such as array) to help.
    Do not introduce any additional function.
    */

};


// void DLinkedList::removeAll(int k) {
//     if (!head) return;
    
//     while (head -> value == k) {
//         node * p1 = head -> next;
//         delete head;
//         head = p1;
//     }
    
//     node * p1 = head -> next;
    
//     while (p1) {
//         while (p1 -> value == k) {
//             if (p1 -> next != nullptr) {
//                 node * p1_b = p1 -> previous;
//                 node * p1_n = p1 -> next;
//                 p1_b -> next = p1_n;
//                 p1_n -> previous = p1_b;
//                 delete p1;
//                 p1 = p1_n;
//             }
//             else {
//                 node * p1_b = p1 -> previous;
//                 p1_b -> next = nullptr;
//                 delete p1;
//                 return;
//             }
//         }
//         p1 = p1 -> next;
//     }
// }


void DLinkedList::sort() {
    if (!head) return; // 0 or 1 node
    
    node * change = head;
    node * cur = head -> next;
    node * p_min = change;

    while (change) {
        while (cur) {
            if (p_min -> value > cur -> value) {
                p_min = cur;
                cur = cur -> next;
            }
            else{
            cur = cur -> next;
            }
        }
        if (p_min != change) {
            if (change -> previous) change -> previous -> next = p_min;
            if (p_min -> next) p_min -> next -> previous = change;
            if (change -> next == p_min) {
                change -> next = p_min -> next;
                p_min -> next = change;
                p_min -> previous = change -> previous;
                change -> previous  = p_min;
                change = p_min -> next;
                p_min = change;
                cur = change -> next;
            }
            else{
                node* change_p = change -> previous;
                node* change_n = change -> next;
                node* p_minP = p_min -> previous;
                node* p_minN = p_min -> next;
                p_min -> next = change -> next;
                p_minP -> next = change;
                change -> next = p_minN;
                change -> previous = p_minP;
                change_n -> previous = p_min;
                p_min -> previous = change_p;
                change = p_min -> next;
                p_min = change;
                cur = change -> next;
            }
            
        }
        else{
            change = change -> next;
            p_min = change;
            cur = change;
        }
    }
    while (head->previous){
        head = head->previous;
    }
    while(tail ->next){
        tail = tail->next;
    }
}


DLinkedList::DLinkedList(int n, int m) {
    for (int i = 0; i < n; ++i) {
        node* p1 = new node(rand() % m);
        if (!head) {//empty DLinkedList
            head = tail = p1;
        }
        else {
            p1->previous = tail;
            tail->next = p1;
            tail = p1;
        }
    }
}


void DLinkedList::print_F() {
    node* p1 = head;
    while (p1) {
        cout << p1->value << " ";
        p1 = p1->next;
    }
}
void DLinkedList::print_B() {
    node* p1 = tail;
    while (p1) {
        cout << p1->value << " ";
        p1 = p1->previous;
    }
}


int main() {

    DLinkedList DL1(20, 10);
    DL1.print_F();
    cout << endl;
    DL1.print_B();
    cout << endl;


//     DL1.removeAll(5);
//     DL1.print_F();
//     cout << endl;
//     DL1.print_B();
//     cout << endl;

    
    DL1.sort();
    DL1.print_F();
    cout << endl;
    DL1.print_B();
    cout << endl;
    

    return 0;
}
