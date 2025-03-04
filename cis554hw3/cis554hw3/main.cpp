//HW3
//Due: 11:59PM, February 23, Wednesday.

#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class course {
public:
    string name;
    int section;
    int credits;
    string grade;
    course() {}
    course(string n, int s, int c, string g) { name = n; section = s; credits = c; grade = g; }
    bool operator<(course c) { return (name < c.name); }
    bool operator==(course c) { return (name == c.name); }
};
void add_student(map<int, map<int, list<course*>*>>& DB, int id);
//Do nothing and return if the student is already in DB.


void remove_student(map<int, map<int, list<course*>*>>& DB, int id);
//Do nothing and ruturn if the student is not in DB.

void add_course(map<int, map<int, list<course*>*>>& DB, int semester, int id, course c);
//20171: Spring semester of 2017; 20172: Fall semester of 2017
//All courses in the list should be sorted according to name (ascending order)
//No duplicated courses allowed even if they are in different semesters.

void drop_course(map<int, map<int, list<course*>*>>& DB, int semester, int id, course c);
//Do nothing and return if the student, semester, or course is not in DB.

void print_student_semester_courses(map<int, map<int, list<course*>*>>& DB, int semester, int id);
//Do nothing and return if the student or semester is not in DB.

void print_student_all_courses(map<int, map<int, list<course*>*>>& DB, int id);
//Do nothing and return if the student is not in DB.

void add_student(map<int, map<int, list<course*>*>>& DB, int id) {
    if (DB.find(id) != DB.end()) return;
    
    DB.insert({ id, map<int, list<course*>*>() });
}
void remove_student(map<int, map<int, list<course*>*>>& DB, int id) {
    if (DB.find(id) != DB.end()) return;
    
    DB.erase(DB.find(id));
}
void add_course(map<int, map<int, list<course*>*>>& DB, int semester, int id, course c) {
//    auto iter = DB[id].begin();
//    while (iter != DB[id].end()) {
//        list<course*>* listP = iter->second;
//        list<course*> theList = *listP;
//        //?
//        for (course* courseP : theList) {
//
//            if ((*courseP).name == c.name) {
//                return;
//            }
//        }
//        iter++;
//    }
    //if (DB[id][semester]->empty()) {
        course* cP1 = &c;
        list<course*> courseL;
         courseL.push_back(cP1);
        list<course*>* courseListP = &courseL;
        //list<course*> courseList = *courseListP;
        DB[id][semester] = courseListP;
        return;
  //  }
//    list<course*>* courseListP = DB[id][semester];
//    list<course*> courseList = *courseListP;
//    course* cP = &c;
//    auto iter2 = courseList.begin();
//    /*for (auto curCourseP : courseList) {
//        course curCourse = *curCourseP;
//        if (c.name < curCourse.name) {
//            courseList.push_back(cP);
//            return;
//        }
//    }*/
//    for (iter2; iter2 != courseList.end(); iter2++) {
//        course curCourse = *(*iter2);
//        if (c.name < curCourse.name) {
//            courseList.insert(iter2, cP);
//            return;
//        }
//    }
//    courseList.push_back(cP);
}

void drop_course(map<int, map<int, list<course*>*>>& DB, int semester, int id, course c) {
    //check student
    if (DB[id].empty()) {
        return;
    }
    //check the semester and course
    auto iter = DB[id].begin();
    int contain = 0;
    while (iter != DB[id].end()) {
        int semesterNo = iter->first;
        if (semester == semesterNo) {
            list<course*>* listP = iter->second;
            list<course*> theList = *listP;
            for (auto courseP : theList) {
                course theCourse = *courseP;
                if (theCourse.name == c.name) {
                    contain = 1;
                    delete courseP;
                    return;
                }
            }
        }
        iter++;
    }
    if (contain == 0) { return; }

    //drop the course
}

void print_student_semester_courses(map<int, map<int, list<course*>*>>& DB, int semester, int id) {
    if (DB[id].empty()) {
        cout<<"pritn"<<endl;
        
        return;
    }
    int contains = 0;
    auto iterS = DB[id].begin();
    while (iterS != DB[id].end()){
        if (iterS->first == semester){
            contains = 1;
            iterS++;
        }
        else{
            iterS++;
        }
    }
    if (contains == 0){return;}
    cout<<"Student ID: "<< id << endl;
    cout<<"Semester: "<<semester<<endl;
    //auto iter = DB[id];
    //list<course*> list = *DB[id][semester];
    for(auto courseP:*DB[id][semester]){
        course theCourse = *courseP;
        cout<<"("<<theCourse.name<<" "<<theCourse.section<<" "
        <<theCourse.credits<<" "<<theCourse.grade<<")  ";
    }
    cout<<endl;
    
    
}
int main() {
    map<int, map<int, list<course*>*>> DB;
    map<int, list<int>*> amap;
    amap.insert({ 1,nullptr });
    add_student(DB, 11111);
    course C1("CIS554", 1, 3, "A-"), C2("CSE674", 1, 3, "B+"), C3("MAT296", 8, 4, "A"), C4("WRT205", 5, 3, "A");

    add_course(DB, 20171, 11111, C1);
//    add_course(DB, 20171, 11111, C4);
//    add_course(DB, 20171, 11111, C3);
//    add_course(DB, 20171, 11111, C2);
    //print_student_semester_courses(DB, 20171, 11111);

    //drop_course(DB, 20171, 11111, C1);
    cout<<"reached"<<endl;
    print_student_semester_courses(DB, 20171, 11111); //sorted according to course name

    //course C5("CIS351", 2, 3, "A-"), C6("PSY205", 5, 3, "B+"), C7("MAT331", 2, 3, "A"), C8("ECN203", 4, 3, "A");
    //add_course(DB, 20172, 11111, C5);
    //add_course(DB, 20172, 11111, C6);
    //add_course(DB, 20172, 11111, C7);
    //add_course(DB, 20172, 11111, C8);
    //add_course(DB, 20172, 11111, C3);
    //print_student_all_courses(DB, 11111);//ID GPA

    //add_student(DB, 11112);
    //add_course(DB, 20171, 11112, C2);
    //add_course(DB, 20171, 11112, C5);
    //add_course(DB, 20171, 11112, C7);
    //add_course(DB, 20171, 11112, C4);
    //print_student_semester_courses(DB, 20171, 11112);

    //add_course(DB, 20172, 11112, C8);
    //add_course(DB, 20172, 11112, C3);
    //add_course(DB, 20172, 11112, C5);
    //add_course(DB, 20172, 11112, C1);
    //print_student_semester_courses(DB, 20172, 11112);

    //print_student_all_courses(DB, 11112);

    //cout << DB << endl;
    //remove_student(DB, 11111);
    //cout << DB << endl;

    return 0;
}
