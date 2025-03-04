//CIS554 HW5  Due: 11:59PM, Wednesday, March. 30.
#include <iostream>
#include <memory>

using namespace std;

class node {
public:
    int value;
    weak_ptr<node> east;
    shared_ptr<node> l_child;
    shared_ptr<node> r_child;
    node() {}
    node(int i) { value = i; }
};

class tree {
public:
    shared_ptr<node> root;
    tree() { }

    //Implement all member functions below
    tree(int n, int m);//constructor for n-level tree with random values in 0 ... m-1
    //n=1: 1 node; n-2: 3 nodes; n=3: 7 nodes; n=4: 15 nodes, etc.

    tree(const tree& T);//copy constructor
    ~tree();//destructor
    tree(tree&& T); //move constructor

    tree(const initializer_list<int>& V);//See lecture video recording for this.
    void operator = (const tree& T);//copy assignment
    void operator = (tree&& T); //move assignment
    tree ThreeTimes(); //return a tree with all node value being three times

    shared_ptr<node> operator[](int k);//The function returns the address of kth node
    //in the overall ring (or cycle).  For example, when k is 0, it returns the address of the
    //root; when k is 1, it returns the address of left child of root; when k is 2, it returns
    //the address of right child of root, etc.
    //For a level 4 tree, when k=14, it returns the address of the very last node of the tree.
    friend ostream& operator<<(ostream& str, const tree& T);//print in the order ring/cycle atarting at the root node
    void InorderPrint(shared_ptr<node>);//in-order printing
};
void tree::InorderPrint(shared_ptr<node> p) {
    if (!p) return;
    InorderPrint(p->l_child);
    cout << p->value << " ";
    InorderPrint(p->r_child);
}

tree::tree(int m, int n) {
    if (m == 0) {
        root = root->l_child = root->r_child = nullptr;
        root->east = root;
        return;
    }
    if (m == 1) {
        shared_ptr<node> p{ make_shared<node>(rand() % n) };
        root = p;
        p->east = p;
        return;
    }
    shared_ptr<node> p{ make_shared<node>(rand() % n) };
    root = p;
    shared_ptr<node> p1 = root, Pe = root;
    for (int i = 1; i < m; i++) {
        int j = 1;
        for (int k = 0; k < i; k++) {
            j = j * 2;
        }
        for (int s = 0; s < j; s++) {
            if (s % 2 == 0) {
                shared_ptr<node> Px{ make_shared<node>(rand() % n) };
                Pe->east = Px;
                p1->l_child = Px;
                Pe = Px;
            }
            else {
                shared_ptr<node> Px{ make_shared<node>(rand() % n) };
                Pe->east = Px;
                p1->r_child = Px;
                Pe = Px;
                p1 = p1->east.lock();
            }

        }
    }
    Pe->east = root;
    cout << "Constructor" << endl;

}
tree::~tree() {
    cout << "Destructor" << endl;
    root = nullptr;
}
tree::tree(const tree& T) {
    cout << "Copy Constructor" << endl;
    //cout<<"true"<<endl;
    if (T.root->east.lock() == T.root) {
        //cout<<"true"<<endl;
        shared_ptr<node> Px{ make_shared<node>(T.root->value) };
        root = Px;
        root->east = root;
        return;
    }
    int nodes = 2;
    shared_ptr<node> check{ T.root->east.lock() };
    while (check != T.root) {
        nodes++;
        check = check->east.lock();
    }
    int levels = 0;
    cout << "num = " << nodes-1 << endl;
    while (nodes != 1) {
        nodes /= 2;
        levels++;
    }
    int Tnodes = 0;

    shared_ptr<node> p{ make_shared<node>(T.root->value) };
    shared_ptr<node> theNode = T.root->east.lock();
    Tnodes++;
    root = p;
    shared_ptr<node> p1 = root, Pe = root;
    for (int i = 1; i < levels; i++) {
        int j = 1;
        for (int k = 0; k < i; k++) {
            j = j * 2;
        }
        for (int s = 0; s < j; s++) {
            if (s % 2 == 0) {
                shared_ptr<node> Px{ make_shared<node>(theNode->value) };
                Pe->east = Px;
                p1->l_child = Px;
                Pe = Px;
                theNode = theNode->east.lock();
                Tnodes++;
            }
            else {
                shared_ptr<node> Px{ make_shared<node>(theNode->value) };
                Pe->east = Px;
                p1->r_child = Px;
                Pe = Px;
                p1 = p1->east.lock();
                theNode = theNode->east.lock();
                Tnodes++;
            }

        }
    }
    Pe->east = root;


}
void tree:: operator=(const tree& T) {
    root = nullptr;
    if (T.root->east.lock() == T.root) {
        //cout<<"true"<<endl;
        shared_ptr<node> Px{ make_shared<node>(T.root->value) };
        root = Px;
        root->east = root;
        return;
    }
    int nodes = 2;
    shared_ptr<node> check = T.root->east.lock();
    while (check != T.root) {
        nodes++;
        check = check->east.lock();
    }
    int levels = 0;
    while (nodes != 1) {
        nodes /= 2;
        levels++;
    }
    int Tnodes = 0;

    shared_ptr<node> p{ make_shared<node>(T.root->value) };
    shared_ptr<node> theNode{ T.root->east.lock() };
    Tnodes++;
    root = p;
    shared_ptr<node> p1 = root, Pe = root;
    for (int i = 1; i < levels; i++) {
        int j = 1;
        for (int k = 0; k < i; k++) {
            j = j * 2;
        }
        for (int s = 0; s < j; s++) {
            if (s % 2 == 0) {
                shared_ptr<node> Px{ make_shared<node>(theNode->value) };
                Pe->east = Px;
                p1->l_child = Px;
                Pe = Px;
                theNode = theNode->east.lock();
                Tnodes++;
            }
            else {
                shared_ptr<node> Px{ make_shared<node>(theNode->value) };
                Pe->east = Px;
                p1->r_child = Px;
                Pe = Px;
                p1 = p1->east.lock();
                theNode = theNode->east.lock();
                Tnodes++;
            }

        }
    }
    Pe->east = root;
    cout << "Copy Assignment" << endl;
}
tree::tree(tree&& T) {
    cout << "Move Constructor" << endl;
    if (T.root->east.lock() == T.root) {
        //cout<<"true"<<endl;
        shared_ptr<node> Px{ make_shared<node>(T.root->value) };
        root = Px;
        root->east = root;
        return;
    }
    int nodes = 2;
    shared_ptr<node> check = T.root->east.lock();
    while (check != T.root) {
        nodes++;
        check = check->east.lock();
    }
    int levels = 0;
    while (nodes != 1) {
        nodes /= 2;
        levels++;
    }
    int Tnodes = 0;

    shared_ptr<node> p{ make_shared<node>(T.root->value) };
    shared_ptr<node> theNode = T.root->east.lock();
    Tnodes++;
    root = p;
    shared_ptr<node> p1 = root, Pe = root;
    for (int i = 1; i < levels; i++) {
        int j = 1;
        for (int k = 0; k < i; k++) {
            j = j * 2;
        }
        for (int s = 0; s < j; s++) {
            if (s % 2 == 0) {
                shared_ptr<node> Px{ make_shared<node>(theNode->value) };
                Pe->east = Px;
                p1->l_child = Px;
                Pe = Px;
                theNode = theNode->east.lock();
                Tnodes++;
            }
            else {
                shared_ptr<node> Px{ make_shared<node>(theNode->value) };
                Pe->east = Px;
                p1->r_child = Px;
                Pe = Px;
                p1 = p1->east.lock();
                theNode = theNode->east.lock();
                Tnodes++;
            }

        }

    }
    Pe->east = root;
    T.root = nullptr;
}

void tree:: operator = (tree&& T) {
    cout << "Move Assignment" << endl;
    tree temp{ *this };
    //root = nullptr;
    root = T.root;
    T.root = temp.root;


}
tree::tree(const initializer_list<int>& V) {
    auto itr = V.begin();
    shared_ptr<node> p{ make_shared<node>(*itr) };
    itr++;
    root = p;
    shared_ptr<node> p1 = root, Pe = root;
    for (int i = 1; i < 5; i++) {
        int j = 1;
        for (int k = 0; k < i; k++) {
            j = j * 2;
        }
        for (int s = 0; s < j; s++) {
            if (s % 2 == 0) {
                shared_ptr<node> Px{ make_shared<node>(*itr) };
                Pe->east = Px;
                p1->l_child = Px;
                Pe = Px;
                itr++;
            }
            else {
                shared_ptr<node> Px{ make_shared<node>(*itr) };
                Pe->east = Px;
                p1->r_child = Px;
                Pe = Px;
                p1 = p1->east.lock();
                itr++;
            }

        }
    }
    Pe->east = root;
    cout << "Initializer List" << endl;
}
tree tree::ThreeTimes() {
    tree temp{ *this };
    shared_ptr<node> p1 = temp.root;
    temp.root->value = 3 * temp.root->value;
    p1 = p1->east.lock();
    while (p1->east.lock() != temp.root) {
        p1->value = 3 * p1->value;
        p1 = p1->east.lock();
    }
    cout << "ThreeTimes" << endl;
    return temp;
}
shared_ptr<node> tree::operator[](int k) {
    shared_ptr<node> ret;
    ret = root;
    for (int i = 0; i < k; i++) {
        ret = ret->east.lock();
    }
    return ret;
}
ostream& operator<<(ostream& str, const tree& T) {

    shared_ptr<node> p1 = T.root;
    if (p1->east.lock() == T.root) {
        str << p1->value << endl;
        return str;
    }
    str << p1->value << " ";
    p1 = p1->east.lock();
    while (p1 != T.root) {
        str << p1->value << " ";
        p1 = p1->east.lock();
    }
    return str;

}

int main() {
 

    tree T1(3, 10);
    cout << T1 << endl;
    T1.InorderPrint(T1.root);
    cout << endl;
    tree T2 = { 5 ,8 ,1, 0, 2, 9, 12, 16, 13, 10, 6, 19, 12, 3, 14, 12, 15, 11, 12, 5, 5, 8, 12, 21, 11, 6, 8, 7, 28, 43, 19};

    cout << T2 << endl;
    T2.InorderPrint(T2.root);
    cout << endl;

    tree T3{ T2 };
    cout << T3 << endl;
    T3.InorderPrint(T3.root);
    cout << endl;
    tree T4;
    T4 = T3;

 
    cout << T4 << endl;
    T4.InorderPrint(T4.root);
    cout << endl;

    T4 = T3.ThreeTimes();
    cout << T4 << endl;
    T4.InorderPrint(T4.root);
    cout << endl;



    return 0;
}
