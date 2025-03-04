#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class myCompareClass{
public:
    bool operator()( int* num1, int* num2)const{
        return *num1<*num2;
    }
    bool operator()(const int num1, const int num2){
        return  num1 < num2;
    }
};
int main(){
    set<int, myCompareClass>* S1; //= new set<int*>{new int{2},new int{3},new int{4},new int{1} };
    set<int, myCompareClass> S2{1,2,3,4,1,3,4};
    set<int, myCompareClass>* sp = &S2;
    S1 = sp;
    set<int*, myCompareClass>* S { new set<int*, myCompareClass>{ new int{2}, new int{44}} };
    return 0;
}
