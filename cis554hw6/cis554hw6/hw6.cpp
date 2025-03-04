//Huahao Shang
//CIS554 HW6 Due: 11:59pm, Monday, April 11.
#include <iostream>
#include <vector>
#include <list>
#include <map>


using namespace std;


bool f1(int i, int j) { return i%5 > j%5; }






//void Sort(vector<int> &nums, bool (*func)(int i, int j)){
//    long size = nums.size();
//
//    for (long i = 0; i<size; i++){
//        bool swapped = false;
//        for (long j = 0; j<size-1; j++ ){
//            if (func(nums[j],nums[j+1])){
//                swap(nums[j], nums[j+1]);
//                swapped = true;
//            }
//        }
//        if (!swapped) break;
//    }
//    //if (func(nums[0], nums[1])) nums[1] = 20;
//   // nums[0] = 90;
//}

void Sort(vector<int> &nums, function<bool(int a, int b)> func){
    long size = nums.size();
    
    for (long i = 0; i<size; i++){
        bool swapped = false;
        for (long j = 0; j<size-1; j++ ){
            if (func(nums[j],nums[j+1])){
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}


//    bool operator()(const list<int*>* &L1, const list<int*>* &L2);
//    bool operator()(const map<list<int*>*, vector<int*>> &M1, const map<list<int*>*, vector<int*>> &M2);


class myFunctorClass{
public:
    bool operator()(const list<int*>* L1, const list<int*>* L2) const;
    bool operator()(const map<list<int*>*, vector<int*>, myFunctorClass> &M1, const map<list<int*>*, vector<int*>, myFunctorClass> &M2) const;
//    bool operator()(const list<int*>* L1, const list<int*>* L2) const;

};
class myCompareClass{
public:
    myCompareClass(){}
    bool operator()(int i, int j){
        return i>j;
    }
    bool operator()(const map < list<int*>*, vector<int*>, myFunctorClass > &M1, const map < list<int*>*, vector<int*>, myFunctorClass > &M2){
        int sum1 = 0, sum2 = 0;
        for (const auto &item:M1){
            for (const auto &nums:*item.first){
                sum1 += *nums;
            }
            for (const auto &ints:item.second){
                sum1 += *ints;
            }
            
        }
        for (const auto &item:M2){
            for (const auto &nums:*item.first){
                sum2 += *nums;
            }
            for (const auto &ints:item.second){
                sum2 += *ints;
            }
            
        }
        return sum1 < sum2;
    }
};
//bool myFunctorClass::operator()(const list<int*>* L1, const list<int*>* L2) const {
//    int sum1 = 0, sum2 = 0;
//    for (const auto i:*L1){
//        sum1 += *i;
//    }
//    for (const auto j:*L2){
//        sum2 += *j;
//    }
//    return sum1<sum2;
//}


bool myFunctorClass:: operator()(const list<int*>* L1, const list<int*>* L2) const{
    int sum1 = 0, sum2 = 0;
    for(const auto i : *L1) sum1 += *i;
    for(const auto j : *L2) sum2 += *j;
    return sum1<sum2;
}

bool myFunctorClass::operator()(const map<list<int*>*, vector<int*>, myFunctorClass> &M1, const map<list<int*>*, vector<int*>, myFunctorClass> &M2)const{
    int sum1 = 0, sum2 = 0;
    for (const auto &item:M1){
        for (const auto &nums:*item.first){
            sum1 += *nums;
        }
        for (const auto &ints:item.second){
            sum1 += *ints;
        }
        
    }
    for (const auto &item:M2){
        for (const auto &nums:*item.first){
            sum2 += *nums;
        }
        for (const auto &ints:item.second){
            sum2 += *ints;
        }
        
    }
    return sum1<sum2;
}

ostream& operator<<(ostream& str, const list<map < list<int*>*, vector<int*>, myFunctorClass > > &data){
    cout<<"( ";
    for (auto& item:data){
        cout<<"{ ";
        for(auto& M:item){
            cout<<"( ";
            for (auto & list:*M.first){
                cout<<*list<<" ";
            }
            cout<<") [ ";
            for (auto & nums:M.second){
                cout<<*nums<<" ";
            }
            cout<<"] ";
        }
        cout<<"} ";
    }
    cout<<")";
    return str;
}
ostream& operator<<(ostream& str, const map<map<list<int*>*, vector<int*>, myFunctorClass>, int, myFunctorClass> &data){
    cout<<endl;
    cout<<"{ ";
    for (auto& item:data){
        cout<<"{ ";
        for(auto &itemFirst:item.first){
            cout<<"( ";
            for (auto & list:*itemFirst.first){
                cout<<*list<<" ";
            }
            cout<<") [ ";
            for (auto & nums:itemFirst.second){
                cout<<*nums<<" ";
            }
            cout<<"] ";
            
        }
        cout<<"} ";
        cout<<item.second<<" ";
    }
    cout<<"}";
    return str;
}

ostream& operator<<(ostream& str, list<map < list<int*>*, vector<int*>>> &data){
    
    return str;
}

bool f2(map < list<int*>*, vector<int*>, myFunctorClass > & M1, map < list<int*>*, vector<int*>, myFunctorClass > & M2){
    int sum1 = 0, sum2 = 0;
    for (auto& item:M1){
        for(auto& list:*item.first){
            sum1 += *list;
        }
        for (auto& nums:item.second){
            sum1 += *nums;
        }
        
    }
    for (auto& item:M2){
        for(auto& list:*item.first){
            sum2 += *list;
        }
        for (auto& nums:item.second){
            sum2 += *nums;
        }
        
    }
    return sum1<sum2;

}
int main() {
    /*
    Write a bubble_sort function, Sort, which takes two arguments:
    a reference to vector<int> and a callable. (See how Sort is called in code below.)
    When the callable is a lambda, the result of sorting is in descending order.
    When the callable is a functor, the result of sorting is in ascending order.
    When the callable is a regular function, the result of sorting is an ascending mod 5 sequence.
    Also see the sample screenshot.
    */
    vector<int> a1{ 10,2,0,14,43,25,18,1,5,45};
    for (const auto& i : a1) { cout << i << " "; }
    cout << endl;
    Sort(a1, [](int a, int b) {return a < b; } );//You need to implement the lambda
    for (const auto& i : a1) { cout << i << " "; }
    cout << endl;
    vector<int> a2{ 10,2,0,14,43,25,18,1,5,45 };
    for (const auto& i : a2) { cout << i << " "; }
    cout << endl;
    Sort(a2, myCompareClass());
    for (const auto& i : a2) { cout << i << " "; }
    cout << endl;

    vector<int> a3{ 10,2,0,14,43,25,18,1,5,45 };
    for (const auto& i : a3) { cout << i << " "; }
    cout << endl;
    Sort(a3, f1);//You need to implement f1.
    for (const auto& i : a3) { cout << i << " "; }
    cout << endl;




    /*
    Remember that map will always sort elements by comparing the first part of each element (i.e., the key part).
    Implement functors in class myFunctorClass classes to allow the following map declaration to work.
    In both classes, when comparing two keys, count the sums of all int values at all levels, and compare the sums.
    */
    
    
    map<map<list<int*>*, vector<int*>, myFunctorClass>, int, myFunctorClass> M1
    {

        {   {
                { new list<int*>{new int{10}, new int{20}, new int{30} }   , {new int{20}, new int{40}}   },
                { new list<int*>{new int{40}, new int{20}, new int{30} }   , {new int{20}, new int{40}, new int{100}}   }
            } , 50
        },


        {    {
                { new list<int*>{new int{10}, new int{20}, new int{30} }   , {new int{20}, new int{40}}   },
                { new list<int*>{new int{40}, new int{20}, new int{30} }   , {new int{20}, new int{40}, new int{200}}   }
            } , 100
        }



    };
    
   cout << M1 << endl;
    cout << endl;
    //Implement the needed overloading operator<< to support the following printing.
    
    



    /*
    For the following, implement the functions used
    in sorting the list elements using regular funciton, functor, and lambda in the three cases.
    Similar to the case of map, we will compare the sums of int values at all levels.
    In addition, you need to implement the needed overloaded operator<< to supporting the printing.
    */
    

    list<map < list<int*>*, vector<int*>, myFunctorClass >> L1{ {
                {
                    new list<int*>{new int{10}, new int{20}, new int{30} } ,
                    {new int{20}, new int{400}}
                },

                {
                    new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                    {new int{20}, new int{40}, new int{100}}
                }
        } , {
                {
                    new list<int*>{new int{10}, new int{20}, new int{30} } ,
                    {new int{20}, new int{40}}
                },

                {
                    new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                    {new int{20}, new int{40}, new int{200}}
                }
    } };
    cout << L1 << endl;
    
    L1.sort(f2);//???: use a regular function
    
    
    cout << L1 << endl;
    
    
    cout << endl;

    list<map < list<int*>*, vector<int*>, myFunctorClass >> L2{ {
                {
                    new list<int*>{new int{10}, new int{20}, new int{30} } ,
                    {new int{20}, new int{400}}
                },

                {
                    new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                    {new int{20}, new int{40}, new int{100}}
                }
        } , {
                {
                    new list<int*>{new int{10}, new int{20}, new int{30} } ,
                    {new int{20}, new int{40}}
                },

                {
                    new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                    {new int{20}, new int{40}, new int{200}}
                }
    } };

    cout << L2 << endl;
//
//
    L2.sort(myCompareClass());//???: use a functor
//
//
    cout << L2 << endl;
    cout << endl;

    list<map < list<int*>*, vector<int*>, myFunctorClass >> L3{ {
                    {
                        new list<int*>{new int{10}, new int{20}, new int{30} } ,
                        {new int{20}, new int{400}}
                    },

                    {
                        new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                        {new int{20}, new int{40}, new int{100}}
                    }
        } , {
                    {
                        new list<int*>{new int{10}, new int{20}, new int{30} } ,
                        {new int{20}, new int{40}}
                    },

                    {
                        new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                        {new int{20}, new int{40}, new int{200}}
                    }
    } };

    cout << L3 << endl;
    L3.sort([](map < list<int*>*, vector<int*>, myFunctorClass > &M1, map < list<int*>*, vector<int*>, myFunctorClass > &M2){
        int sum1 = 0, sum2 = 0;
        for (const auto &item:M1){
            for (const auto &nums:*item.first){
                sum1 += *nums;
            }
            for (const auto &ints:item.second){
                sum1 += *ints;
            }
            
        }
        for (const auto &item:M2){
            for (const auto &nums:*item.first){
                sum2 += *nums;
            }
            for (const auto &ints:item.second){
                sum2 += *ints;
            }
            
        }
        return sum1 < sum2;
    
    });//???: use a lambda
    cout << L3 << endl;

    return 0;
     
}
//The following is a sample screenshot
//You must follow the exact format to avoid penalty in grading.
/*

10 2 0 14 43 25 18 1 5 45
45 43 25 18 14 10 5 2 1 0
10 2 0 14 43 25 18 1 5 45
0 1 2 5 10 14 18 25 43 45
10 2 0 14 43 25 18 1 5 45
10 0 25 5 45 1 2 18 43 14


{ { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 100 ] } 50 { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } 100 }

( { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } )
( { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } )

( { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } )
( { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } )

( { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } )
( { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } )
*/
