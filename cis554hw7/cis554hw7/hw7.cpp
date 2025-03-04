//HW7. Due: Wednesday, April 20 at 11:59pm
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//For all comparisons, compare the sums of all int objects in the key parts of structures.
//For all hashing, use h(sum of all int objects in the key parts of structures), where hash<int> h; hash<int>{}(sum)
class myCompareClass{
public:
    
    bool operator() (const int *num1, const int *num2)const {
        return *num1 < *num2;
    }
        bool operator()(const list<set<int*,myCompareClass>*> &L1, const list<set<int*, myCompareClass>*> &L2)const{
            int sum1 = 0, sum2 = 0;
            for (auto &sets:L1){
                for (auto &nums:*sets){
                    sum1 += *nums;
                }
            }
            for (auto &sets:L2){
                for (auto &nums:*sets){
                    sum2 += *nums;
                }
            }
            return sum1 < sum2;
        }
    
};
class myFunctorClass{
public:
    size_t operator()(const map < list<set<int*, myCompareClass>*>, vector<int*>* , myCompareClass> &M1) const {
        int sum = 0;
        for (auto& item1:M1){
            for (auto& sets:item1.first){
                for(auto& nums1:*sets){
                    sum += *nums1;
                }
            }
            for (auto& nums2:*item1.second){
                sum += *nums2;
            }
        }
        return hash<int>{}(sum);
    }
    bool operator() (const map < list<set<int*, myCompareClass>*>, vector<int*>*,myCompareClass > &M1, const map < list<set<int*, myCompareClass>*>, vector<int*>* , myCompareClass> &M2) const {
        int sum1 = 0, sum2 = 0;
        for (auto& item1:M1){
            for (auto& sets:item1.first){
                for(auto& nums1:*sets){
                    sum1 += *nums1;
                }
            }
            for (auto& nums2:*item1.second){
                sum1 += *nums2;
            }
        }
        for (auto& item1:M2){
            for (auto& sets:item1.first){
                for(auto& nums1:*sets){
                    sum2 += *nums1;
                }
            }
            for (auto& nums2:*item1.second){
                sum2 += *nums2;
            }
        }
        return sum1 == sum2;
    }
};
//ostream& operator<<(ostream& str, unordered_map< map < list<set<int*, myCompareClass>*>, vector<int*>* >, vector<int>> &data){
//    return str;
//}
ostream& operator<<(ostream& str,unordered_map< map < list<set<int*, myCompareClass>*>, vector<int*>*, myCompareClass >, vector<int>, myFunctorClass, myFunctorClass> &data){
    cout<<"{"<<endl;
    for (auto &item1:data){
        cout<<"{ ";
        for (auto& item2:item1.first){
            cout<<"[ ";
            
            for (auto& lists:item2.first){
                cout<<"< ";
                for (auto& sets:*lists){
                    cout<<*sets<<" ";
                }
                cout<<"> ";
            }
            cout<<"] ( ";
            for (auto&vec:*item2.second){
                cout<< *vec<<" ";
            }
            cout<<") ";
        }
        cout<<"} ( ";
        for (auto& nums:item1.second){
            cout<<nums<<" ";
        }
        cout<<") "<<endl;;
    }
    cout<<"}"<<endl;
    return str;
}
int main() {
//The following won't run. Fix it.
//In addition, create your initialized values. For each STL container, at least three elements are required.
//Overload operator<< to allow "cout << H1 << endl;"
//    unordered_map< map < list<set<int*, myCompareClass>*>, vector<int*>* >, vector<int>> UM{ { { {new list<set*>{new int{5}, new int{1}, new int{6} } } , new list<int*>{ new int{1}, new int{6}, new int{2}} } , { new int{10},new int{12},new int{3} } }         };
    
    unordered_map< map < list<set<int*, myCompareClass>*>, vector<int*>* , myCompareClass>, vector<int>, myFunctorClass,myFunctorClass > UM{
        {
            {  { { new set<int*, myCompareClass>{new int{8}, new int{2}, new int{1}} ,  new set<int*, myCompareClass>{new int{3}, new int{2}, new int{1}},new set<int*, myCompareClass>{new int{444}, new int{2}, new int{3}} }
                , new vector<int*>{new int{5}, new int{3}, new int{10}} },
                { { new set<int*, myCompareClass>{new int{6}, new int{2}, new int{5} } ,  new set<int*, myCompareClass>{new int{3}, new int{2}, new int{100} },new set<int*, myCompareClass>{new int{7}, new int{2}, new int{300}} }
                    , new vector<int*>{new int{5}, new int{3}, new int{11}} },
                { { new set<int*, myCompareClass>{new int{1}, new int{2}, new int{99}} ,  new set<int*, myCompareClass>{new int{111}, new int{40}, new int{10}},new set<int*, myCompareClass>{new int{0}, new int{21}, new int{211}} }
                    , new vector<int*>{new int{5}, new int{3}, new int{12}} }
                
            }
            , {1,2,3,4,5,6 }
            
        },
        {
            {  { { new set<int*, myCompareClass>{new int{3}, new int{2}, new int{5}} ,  new set<int*, myCompareClass>{new int{3}, new int{2}, new int{7}},new set<int*, myCompareClass>{new int{7}, new int{2}, new int{555}} }
                , new vector<int*>{new int{5}, new int{3}, new int{44}} },
                { { new set<int*, myCompareClass>{new int{9}, new int{2}, new int{3}} ,  new set<int*, myCompareClass>{new int{3}, new int{2}, new int{6}},new set<int*, myCompareClass>{new int{7}, new int{222}, new int{3}} }
                    , new vector<int*>{new int{9}, new int{1}, new int{24}} },
                { { new set<int*, myCompareClass>{new int{1}, new int{2}, new int{12}} ,  new set<int*, myCompareClass>{new int{1}, new int{2}, new int{26}},new set<int*, myCompareClass>{new int{17}, new int{2}, new int{333}} }
                    , new vector<int*>{new int{5}, new int{90}, new int{14}} }
            }
            , {1,2,3,4,5 }
            
        },
        {
            {  { { new set<int*, myCompareClass>{new int{7}, new int{2}, new int{3}} ,  new set<int*, myCompareClass>{new int{3}, new int{2}, new int{999}},new set<int*, myCompareClass>{new int{7}, new int{2}, new int{30}} }
                , new vector<int*>{new int{500}, new int{3}, new int{10}} },
                { { new set<int*, myCompareClass>{new int{3}, new int{9}, new int{2}} ,  new set<int*, myCompareClass>{new int{3}, new int{2}, new int{4}},new set<int*, myCompareClass>{new int{7}, new int{20}, new int{3}} }
                    , new vector<int*>{new int{5}, new int{3},new int{99}} },
                { { new set<int*, myCompareClass>{new int{1}, new int{88}, new int{12}} ,  new set<int*, myCompareClass>{new int{1}, new int{2}, new int{88}}, new set<int*, myCompareClass>{new int{777}, new int{2}, new int{3}} }
                    , new vector<int*>{new int{5}, new int{0}, new int{44}} }
            }
            , {4,3,2,1 }
            
        },
        {
            {  { { new set<int*, myCompareClass>{new int{7}, new int{2}, new int{3}} ,  new set<int*, myCompareClass>{new int{3}, new int{2}, new int{999}},new set<int*, myCompareClass>{new int{7}, new int{2}, new int{30}} }
                , new vector<int*>{new int{500}, new int{3}, new int{10}} },
                { { new set<int*, myCompareClass>{new int{3}, new int{9}, new int{2}} ,  new set<int*, myCompareClass>{new int{3}, new int{2}, new int{4}},new set<int*, myCompareClass>{new int{7}, new int{20}, new int{3}} }
                    , new vector<int*>{new int{5}, new int{3},new int{99}} },
                { { new set<int*, myCompareClass>{new int{1}, new int{88}, new int{12}} ,  new set<int*, myCompareClass>{new int{1}, new int{2}, new int{88}}, new set<int*, myCompareClass>{new int{777}, new int{2}, new int{3}} }
                    , new vector<int*>{new int{5}, new int{0}, new int{44}} }
            }
            , {4,3,2,1 }
            
        }
        
        };
    cout << UM << endl;
return 0;
}
/*
The following is a possible output.
Depending on the initialization values you select, the output values will be different.
However, do follow the same format for set, map, vector and list.
{
{ [ < 3 5 7 > < 2 5 8 > < 3 6 11 > ] ( 7 19 13 ) [ < 3 5 17 > < 3 5 8 > < 1 3 6 > ] ( 4 14 3 ) [ < 1 7 13 > < 1 2 15 > < 6 16 20 > ]
( 5 19 4 ) } ( 7 8 9 )
{ [ < 3 5 7 > < 2 5 8 > <m 3 6 11 > ] ( 7 11 3 ) [ < 3 5 17 > < 3 5 8 > < 1 3 6 > ] ( 4 14 3 ) [ < 3 4 5 > < 2 5 18 > < 2 6 13 > ] ( 5 11
13 ) } ( 1 2 3 )
{ [ < 5 6 13 > < 3 4 5 > < 3 9 11 > ] ( 4 14 3 ) [ < 5 7 13 > < 1 11 15 > < 3 6 8 > ] ( 5 12 3 ) [ < 3 4 13 > < 2 5 12 > < 2 13
16 > ] ( 5 17 2 ) } ( 3 5 7 )
}
*/


