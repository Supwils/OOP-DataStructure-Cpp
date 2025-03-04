//HW1 Huahao Shang
//SU Net ID: hushang SUID: 826300916
//Do not modify main function


#include <iostream>

using namespace std;

class node {//for doubly linked list; double linked list
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

    void removeAll(int k);
    /*
    Remove all nodes with value k.
    You are allow to modify  value, next, and previous of a node.
    You are not allowed to use any external stucture (such as array) to help.
    Do not introduce any additional function.
    */

};


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

void DLinkedList::sort(){
    if (!head) return;
    
    node*change {head}, * cur {change->next}, *minP{change};
    do{
        //to find the value we need to swap
        while (cur){
            if (cur->value < minP-> value){
                minP = cur;
                cur = cur->next;
        }
            else{
                cur = cur->next;
            }
        }
        //if we found rhe smaller value
        if (minP != change){
            if (change->previous){
                change->previous->next = minP;
                
            }
            if (minP ->next){
                minP->next->previous = change;
                
            }
            if (change->next == minP){
                minP ->previous = change->previous;
                change->previous = minP;
                change->next =minP->next;
                minP->next = change;
                change = minP->next;
                cur= change->next;
                minP = change;
            }
            else{
                node* changePrev = change->previous;
                node* changeN{change->next},*minPrev{minP->previous},*minN{minP->next};
                minP->previous->next = change;
                minP->next = change->next;
                change->next =minN;
                change->previous = minPrev;
                changeN->previous = minP;
                minP->previous = changePrev;
                change = minP->next;
                cur= change->next;
                minP = change;
            }
            
        }
        //if not find the smaller value then keep look the next
        else{
                change= change->next;
                cur= change;
                minP = change;
            }
    }while (change);
    
    //to re-position the head and tail pointer
    while(head->previous != nullptr){
        head = head->previous;
    }
    while(tail->next != nullptr){
        tail = tail->next;
        
    }
    }



void DLinkedList::removeAll(int k) {
    if (!head) return; //0 or 1 node
    
    while(head->value == k){
        //if it is the head need to remove then remove it.
            node* head1{ head };
            head->next->previous=head->previous;
            head = head->next;
            delete head1;
            
    }
    node* cur{ head }, * curnext{ head->next };
    while (curnext) {
        if (curnext->value == k && curnext->next == nullptr) {
            cur->next = curnext->next;
            tail = tail->previous;
            delete curnext;
            break;
            return;
        }
            else if (curnext->value == k){
                node* curnext1 = cur->next;
                cur->next = curnext->next;
                curnext->next->previous = cur;
                curnext = curnext->next;
                //cur = cur->next;
                delete curnext1;
                
            }
        
            else{
                cur = curnext;
                curnext = curnext->next;
            }
        
}
}


    
void DLinkedList::print_F() {
    node* p1{ head };
    while (p1) {
        cout << p1->value << " ";
        p1 = p1->next;
    }
}
void DLinkedList::print_B() {
    node* p1{ tail };
    while (p1) {
        cout << p1->value << " ";
        p1 = p1->previous;
    }
}


int main() {

    DLinkedList DL1{ 20, 10};
    DL1.print_F();
    cout << endl;
    DL1.print_B();
    cout << endl;

    DL1.removeAll(5);
    DL1.print_F();
    cout << endl;
    DL1.print_B();
    cout << endl;

    DL1.sort();
    DL1.print_F();
    cout << endl;
    DL1.print_B();
    cout << endl;

    return 0;
}
