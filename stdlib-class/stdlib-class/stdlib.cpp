
//Standard Template Library (STL)  containers:  vector, list, map, stack, queue, etc.
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <string> //"CIS554"

using namespace std;

int main() {

    vector<int> V1;// 0 elements
    vector<int> V2(10); //vector of 10 int elements  0 0 0 0 0 0 0 0 0 0
    vector<int> V3(5, 2); // 2 2 2 2 2
    vector<int> V4{ 1,2,3,4,5,6 };//1 2 3 4 5 6
    vector<int*> V5{ new int{3}, new int{2} };

    V4.push_back(3);//1 2 3 4 5 6 3
    V4.pop_back();//1,2,3,4,5,6
    cout << V4.size() << endl;//6
    cout << V4.front() << " " << V4.back() << endl;//1 6

    for (size_t i = 0; i < V4.size(); ++i) {//size_t non-negative int
        cout << V4[i] << " ";
    }//1 2 3 4 5 6
    cout << endl;
    for (int i : V4) { cout << i << " "; ++i; }//1 2 3 4 5 6 ; i: call by value
    cout << endl;
    for (int i : V4) { cout << i << " "; }//1 2 3 4 5 6
    cout << endl;

    for (int& i : V4) { cout << i << " "; ++i; }//1 2 3 4 5 6 ;   i: call by reference
    cout << endl;
    for (int i : V4) { cout << i << " "; }//2 3 4 5 6 7
    cout << endl;

    for (auto i : V4) { cout << i << " "; }//2 3 4 5 6
    cout << endl;

    list<int> L1{ 1,2,3,4,5 };
    for (auto& i : L1) { cout << i << " "; } //1 2 3 4 5
    list<int> L2(10);//0 0 0 0 0 0 0 0 0 0
    list<int> L3(6, 3); //3 3 3 3 3 3
    L3.push_back(4);//3 3 3 3 3 3 4
    L3.pop_back();//3 3 3 3 3 3
    L3.push_front(2);//2 3 3 3 3 3 3
    L3.pop_front();//3 3 3 3 3 3
    //cout << L3[2] <<endl;  Error!  list does not support array like subscript

    cout << L3.front() << " " << L3.back() << " " << L3.size() << endl;
    L3.clear();//set the size to 0
    if (L3.empty()) cout << "L3 is empty" << endl; //L3 is empty


    //iterator: special type  of pointers used in STL containers


    vector<int>::iterator it1{ V4.begin() };//the  address of the first element of V4
    auto it2{ V4.end() };// the address after the last element

    for (vector<int>::iterator i1 = V4.begin(); i1 != V4.end(); ++i1) {
        cout << *i1 << " ";
    }
    cout << endl;

    for (size_t i1 = 0; i1 < V4.size(); ++i1) cout << V4[i1] << " ";

    list<int> L4{ 2, 4,7,1,5 };
    auto it3 = find(L4.begin(), L4.end(), 4);//return the address of first match.  return end() if not found
    if (it3 != L4.end()) cout << *it3 << endl; // L4.erase(it3);
    if (it3 != L4.end()) L4.erase(it3);
    vector<int> V6{ 2, 4,7,1,5 };
    auto it4 = find(V6.begin(), V6.end(), 4);//return the address of first match.  return end() if not found
    if (it4 != V6.end()) cout << *it4 << endl; // L4.erase(it3);
    if (it4 != V6.end()) V6.erase(it4);

    L4.remove(1);//remove the element 1 if matched; else do nothing.  Only for list, not vector
    L4.sort();//sort

    auto it5{ V6.begin() };
    it5++;
    it5 = V6.begin() + 3;

    list<int> L5{ 9,8,7,6,5,4,3 };
    auto it6{ L5.end() };
    --it6;//cout < *it6 <<endl; 3
    //it6 = it6-1; Error
    /*
    iterator of list only allows the following operations:
    ++it, it++, --it, it--
    */

    vector<vector<int>> V7(10, vector<int>(5, 1)); //10 rows,  5 cols, all with initial value 1
    for (auto& i : V7) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    /*
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    ...
    
    */

    for (size_t i = 0; i < V7.size(); ++i) {
        for (size_t j = 0; j < V7[0].size(); ++j)
            cout << V7[i][j] << " ";
        cout << endl;
    }


    list<vector<int>> L6{ {1,2, 3}, {4,5,6,7} , {8,9} };
    for (auto& i : L6) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    map<int, string> M1{ {7, "Bob"}, {4, "Mary"}, {2, "John"}, {5, "Nancy"}, {7, "Jesse"} };// {7, "Jesse"} will be ignored
    for (auto& i : M1) { cout << i.first << " " << i.second << "  "; }
    cout << endl;
    // 2 John   4 Mary  5 Nancy  7 Bob
    //elements will be automatically sorted based on key (i.e., the first object of each pair)

    //each pair consists of key and value;  a relation of association

    cout << M1[7] << endl;//Bob

    M1[7] = "Dave";// Override
    M1[22] = "Jeff";//insert a new element
    M1.insert({ 11, "Mike" });//insert a new element
    M1.insert({ 11, "Ben" });//11 already exists, insert will be ignored.

    pair<map<int, string>, bool> ret;
    //ret = M1.insert({0,"James"});
    

    return 0;
}
