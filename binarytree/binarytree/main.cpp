
//Linked List
#include <iostream>

using namespace std;



class Tnode {
public:
    int value;
    Tnode* Lchild;
    Tnode* Rchild;
    Tnode(int i) { value = i; Lchild = Rchild = nullptr; }
    Tnode() { Lchild = Rchild = nullptr; }
};

class Tree {//full tree;  1 node (level 1), 3 nodes (Level 2), 7 nodes (level 3), 15 nodes
public:
    Tnode* root;
    Tree() { root = nullptr; }
    Tnode* MakeTree(int k, int m);//k levels with values in 0 ... m-1
    void InorderPrint(Tnode* p);
    int LeftHeavy(Tnode* p);
    void mirror(Tnode* p);
    
    Tnode* mirrorCopy(Tnode* p);
    
    bool Existing(Tnode* p, int k);//check existence of a node
    //Make the tree, rooted at a node pointed by p, Left Heavy
    //You required to implement LeftHeavy using recursion.
};

Tnode* Tree::MakeTree(int k, int m) {
    Tnode* p1 = new Tnode(rand() % m);
    if (k == 1) return p1;
    p1->Lchild = MakeTree(k - 1, m);
    p1->Rchild = MakeTree(k - 1, m);
    return p1;
}
int Tree::LeftHeavy(Tnode *p){
    if (!p) return 0;
    if (!p->Lchild) return p->value;
    return 0;
    
}
void Tree::mirror(Tnode *p){
    if (!p ) return;
    swap(p->Lchild,p->Rchild);
    mirror(p->Lchild);
    mirror(p->Rchild);
    
    
}

Tnode* Tree::mirrorCopy(Tnode *p){
    if (!p) return nullptr;
    Tnode* newTree = new Tnode(p->value);
    newTree->Lchild = mirrorCopy(p->Rchild);
    newTree->Lchild = mirrorCopy(p->Lchild);
    return newTree;
    
    
}
void Tree::InorderPrint(Tnode* p) {
    if (!p) return;
    InorderPrint(p->Lchild);
    cout << p->value << " ";
    InorderPrint(p->Rchild);
}
bool Tree::Existing(Tnode* p, int k){
    if (!p) return false;
    if (p->value == k) return true;
    
    
    return (Existing(p->Lchild, k) ||Existing(p->Rchild, k));
}


int main() {

    

    Tree T1;
    T1.root = T1.MakeTree(3, 20);
    T1.InorderPrint(T1.root);
    //cout << endl;
    //T1.LeftHeavy(T1.root);
    //T1.mirror(T1.root);
    //T1.InorderPrint(T1.root);
//    bool ans =T1.Existing(T1.root, 1);
//    cout<<ans<<endl;
//    Tree T2;
//    T2.root = T1.mirrorCopy(T1.root);
//    T2.InorderPrint(T2.root);
    
    return 0;
}
