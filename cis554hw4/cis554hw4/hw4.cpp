//HW4 Due: 11:59pm, Wednesday, March 2, 2022

#include <iostream>
#include <map>


using namespace std;


class course {
public:
    string name;
    int section;
    int credits;
    string grade;
    course() {}
    course(string n, int s, int c, string g) { name = n; section = s; credits = c; grade = g; }
};


template <class T> class Record {
public:
    map<int, map<int, T*>*> Data;
    Record() { }
    Record(const initializer_list < pair<int, initializer_list<pair <int, T>>>>& I);
    Record(const Record<T>& R);//Copy Constructor
    void operator=(const Record<T>& R);//Copy Assignment
    ~Record();//Destructor
    Record<T> deleteFirst();//DeleteFirst
    Record(Record<T>&& R);//Move Constructor
    void operator=(Record<T>&& R);//Move Assignment
};

template <class T> void Record<T>::operator=(Record<T>&& R) {//Move Assignment
    //Your code
    if (this == &R) { cout << "Move Assignment" << endl; return; }
    auto it = Data.begin();
    while (it != Data.end()) {
        auto it2 = (*(it->second)).begin();
        while (it2 != (*(it->second)).end()) {
            delete it2->second;
            (*(it->second)).erase(it2);
            it2 = (*(it->second)).begin();
        }
        delete (it->second);
        Data.erase(it);
        it = Data.begin();
    }
    Data = R.Data;
    R.Data.erase(R.Data.begin(), R.Data.end());
    cout << "Move Assignment" << endl;
}

template <class T> Record<T>::Record(Record<T>&& R) {//Move Constructor
//Your code
    Data = R.Data;
    auto it = R.Data.begin();
    while (it != R.Data.end()) {
        auto it2 = (*(it->second)).begin();
        while (it2 != (*(it->second)).end()) {
            delete it2->second;
            (*(it->second)).erase(it2);
            it2 = (*(it->second)).begin();
        }
        delete (it->second);
        R.Data.erase(it);
        it = R.Data.begin();
    }
    cout << "Move Constructure" << endl;

}

template<class T> Record<T> Record<T>::deleteFirst() {//DeleteFirst
//Your code
    Record<T> temp{ *this };
    auto it1 = temp.Data.begin();
    temp.Data.erase(it1);
    cout << "Delete First" << endl;
    return temp;
}

template<class T> Record<T>::~Record() {//Destructor
//Yor code
    //map<int, map<int, T*>*> Data
    auto it = Data.begin();
    while (it != Data.end()) {
        auto it2 = (*(it->second)).begin();
        while (it2 != (*(it->second)).end()) {
            delete it2->second;
            (*(it->second)).erase(it2);
            it2 = (*(it->second)).begin();
        }
        delete (it->second);
        Data.erase(it);
        it = Data.begin();
    }
    cout << "Destructor" << endl;
}
template <class T> void Record<T>::operator=(const Record<T>& R) {//Copy Assignment
//Your code
    if (this == &R) { cout << "Copy Assignment" << endl; return; }
    //delete the previous data
    auto it = Data.begin();
    while (it != Data.end()) {
        auto it2 = (*(it->second)).begin();
        while (it2 != (*(it->second)).end()) {
            delete it2->second;
            (*(it->second)).erase(it2);
            it2 = (*(it->second)).begin();
        }
        delete (it->second);
        Data.erase(it);
        it = Data.begin();
    }
    for (auto it_R = R.Data.begin(); it_R != R.Data.end(); it_R++) {
        int R_int = it_R->first;
        auto the_list = *(it_R->second);

        map<int, T*>* map2P = new map<int, T*>();
        for (auto it_the_list = the_list.begin(); it_the_list != the_list.end(); it_the_list++) {
            int course_int = it_the_list->first;
            T* thecourse = new T{ *(it_the_list->second) };
            map2P->insert({ course_int, thecourse });
        }
        Data.insert({ R_int, map2P });
    }
    cout << "Copy Assignment" << endl;


}

template <class T> Record<T>::Record(const Record<T>& R) {    //Copy constructor
//Your code
    //map<int, map<int, T*>*> Data
    for (auto it_R = R.Data.begin(); it_R != R.Data.end(); it_R++) {
        int R_int = it_R->first;
        auto the_list = *(it_R->second);

        map<int, T*>* map2P = new map<int, T*>();
        for (auto it_the_list = the_list.begin(); it_the_list != the_list.end(); it_the_list++) {
            int course_int = it_the_list->first;
            T* thecourse = new T{ *(it_the_list->second) };
            map2P->insert({ course_int, thecourse });
        }
        Data.insert({ R_int, map2P });
    }
    cout << "Copy Constructure" << endl;
}
template <class T> Record<T>::Record(const initializer_list < pair<int, initializer_list<pair <int, T>>>>& I) {
    //Your code
        //map<int, map<int, T*>*> Data;
    auto it_I = I.begin();
    while (it_I != I.end()) {
        int I_int = it_I->first;
        auto the_list = it_I->second;
        auto it_the_list = the_list.begin();
        map<int, T*>* map2P = new map<int, T*>();
        //map<int, T*> map2;
        //T* courseP; //= new T();
        while (it_the_list != the_list.end()) {
            int course_int = it_the_list->first;
            T* thecourse = new T{ it_the_list->second };
            //courseP = thecourse;
            map2P->insert({ course_int, thecourse });
            it_the_list++;
        }
        //map2P = &map2;
        Data.insert({ I_int, map2P });
        it_I++;
    }
    cout << "Initializer_List" << endl;
}
//You need to implement all needed overloaded operator<<
//ostream& operator<<(ostream& str, Record<course>& D) {
//    //str<<"print"<<endl;
//    //str<<endl;
//    str << "{ ";
//    auto one = D.Data.begin();
//    while (one != D.Data.end()) {
//        str << one->first << " { ";
//        for (auto map2 : *(one->second)) {
//            str << map2.first << " (" << (*map2.second).name << " " << (*map2.second).section << " " << (*map2.second).credits << " " << (*map2.second).grade << ") ";
//        }
//        str << "} ";
//        one++;
//    }
//    str << "}";
//    str << endl;
//    return str;
//
//}
//map<int, map<int, T*>*> Data
ostream& operator<<(ostream& str, const course& C) {
    str <<" ( " << C.name << " " << C.section << " " << C.credits << " "<<C.grade<<") ";
    return str;
}

//ostream& operator<<(ostream& str, const map<int, map<int, course*>*>& C) {
//    str<<"{";
//    for (auto one = C.begin(); one != C.end(); one++){
//        str<<one->first<<"{ ";
//        for (auto two = (*(one->second)).begin(); two != (*(one->second)).end(); two++){
//            str<<two->first<<" ";
//            str<<*(two->second);
//        }
//    }
//    str<<"}";
//    return str;
//}
template <class T> ostream& operator<<(ostream& str, Record<T>& D){
    str<<"{ ";
    for (auto it = D.Data.begin(); it != D.Data.end(); it ++){
        str<<it->first<<" { ";
        for(auto it2 = (*(it->second)).begin(); it2 != (*(it->second)).end(); it2++){
            str<<it2->first<< *(it2->second);
        }
    }
    str<<" }";
    return str;
}



int main() {
    course C1("CIS554", 1, 3, "A-"), C2("CSE674", 1, 3, "B+"), C3("MAT296", 8, 4, "A"), C4("WRT205", 5, 3, "A");
    course C5("CIS351", 2, 3, "A-"), C6("PSY205", 5, 3, "B+"), C7("MAT331", 2, 3, "A"), C8("ECN203", 4, 3, "A");

    Record<course> R1{ {10, { {12, C1}, {9, C2}  }},
        {7, {{8, C3}, {3, C4}, {1, C5}}},{4, {{21, C6}, {15, C7}} } };

    cout << R1 << endl;
 

    Record<course> R2{ R1 };
    cout << R2 << endl;

    Record<course> R3;
    //R3 = move(R1);
    cout << R3 << endl;

    R3 = R1.deleteFirst();
    cout << R3 << endl;

    R3 = R3;
    cout << R3 << endl;

    return 0;
}


