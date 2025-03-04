
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

class Tnode{
public:
    int val;
    Tnode* left;
    Tnode* right;
    Tnode(int i){val =i; left = right = nullptr;}
    Tnode(){left = right = nullptr;}
    
};

class Tree{//full node
public:
    Tnode* root;
    Tree() {root = nullptr;}
    Tnode* MakeTree(int k, int m);
    void InorderPrint(Tnode* p);
};

Tnode* Tree::MakeTree(int k, int m){
    Tnode* p1 = new Tnode(rand()%m);
    if (k == 1)return p1;
    p1->left = MakeTree(k-1, m);
    p1->right = MakeTree(k-1, m);
    return p1;
}

void Tree::InorderPrint(){
    InorderPrint(root->left);
    cout<<p-val<<" ";
    InorderPrint(p->right);
}

class node {
public:
    int value;
    node* next;

    node(int i) { value = i; next = nullptr; }
    node() { next = nullptr; }//default constructor
};

class Dnode{//double linked list node
public:
    int val;
    Dnode* next;
    Dnode* prev;
    Dnode(int i){val = i; next = prev = nullptr; }
    
};
class Dlinkedlist{
public:
    Dnode* head;
    Dnode* tail;
    Dlinkedlist(int n,int m);
    void print_f();
    void print_b();
    void reverse();
};
Dlinkedlist::Dlinkedlist(int n, int m){
    for (int i = 0; i<n;i++){
        Dnode* p1 = new Dnode(rand() % m);
        if (!head){
            head = tail = p1;
        }
        else{
            p1->prev = tail;
            tail->next = p1;
            tail = p1;
        }
    }
}

void Dlinkedlist::reverse(){
    if (!head || !head->next) return;
    Dnode* p1{head},*p2{head->next};
    while(p1){
        swap(p1->next,p1->prev);
        p1 = p2;
        p2 = p2->next;
    }
    swap(head,tail);
    
}
void Dlinkedlist::print_f(){
    Dnode* p1{head};
    while(p1){
        cout << p1->val <<" ";
        p1 = p1->next;
    }
}
void Dlinkedlist::print_b(){
    Dnode* p1{tail};
    while(tail){
        cout<<p1->val<<" ";
        p1 = p1->prev;
    }
}
class LinkedList {
public:
    node* head;// points to the first node of the linked list.
    LinkedList() { head = nullptr; }//default constructor
    LinkedList(int n, int m);//constructor an n-node linked list with random values in 0 ... m-1
    void print();
    void reverse();
    //void sort();
    void sort();//prototype
    void remove_one(int k);

};

void LinkedList::sort(){
    if (!head || !head->next){
        return;
    }
    while(!head->next){
        node* nex,* cur{head};
        nex = cur->next;
        node* pmin{cur};
        int min{cur->value};
        while(nex){
            if (nex->value < min){
                pmin = nex;
                min = nex->value;
            }
            nex = nex->next;
            
        }
        pmin->value = cur->value;
        cur->next = pmin;
        cur = cur->next;
        
    }
}

void LinkedList::remove_one(int k){
    if (!head) return;
    if (head->value == k){
        node* p1{head->next};
        head = p1;
        return;
        }
    node* p1{head},*p2{head->next};
    while(p2){
        if (p2->value == k){
            p1->next = p2->next;
            return;
        }
        p1 = p2;
        p2 = p2->next;
    }
}

void LinkedList::reverse() {
    if (!head || !head->next) return; //0 or 1 node

    node* p1{ head }, * p2, * p3;
        p2 = p1->next;
        while (p2) {
            p3 = p2->next;
            p2->next = p1;
            if (p1 == head) p1->next = nullptr;
            p1 = p2;
            p2 = p3;
        }
        head = p1;

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
    L1.remove_one(9);
    cout<<"wewewe"<<endl;
    L1.sort();
    L1.print();

//    Dlinkedlist L2{12,20};
//    L2.print_f();
//    L2.print_b();
    

    return 0;
}
