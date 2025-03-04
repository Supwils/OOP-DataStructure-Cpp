//HW3 Huahao Shang
//SU Net ID: hushang SUID: 826300916

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
ostream& operator<<(ostream& str, const course& c);
ostream& operator<<(ostream& str, map<int, map<int, list<course*>*>>& DB);

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
    //do nothing if student already exist
    if (DB.find(id) == DB.end()) return;
    // we should delete both map to avoid memory leak
    //delete the inside map first first, delete the course pointer then delete the list pointer
    auto it1 = DB[id].begin();
    //map<int, list<course*>*>::iterator itrator;
    while (it1 != DB[id].end()){
        for(auto insideMap: DB[id]){
            auto it2 = insideMap.second->begin();
            while (it2 != insideMap.second->end()){
                //delete course pointer
                delete *it2;
                //delete insideMap.second; should not use delete because the rest pointer will not be reached use delete
                //then resign iterator to the begining
                insideMap.second->erase(it2);
                it2 = insideMap.second->begin();
            }
        }
        DB[id].erase(it1);
        it1 = DB[id].begin();
    }
    DB.erase(DB.find(id));
    
}

void add_course(map<int, map<int, list<course*>*>>& DB, int semester, int id, course c) {


    //return if the student not exist
    if (DB.find(id) == DB.end()) return;
    
    //check if the course exist
    for (auto check_semester:DB[id]){
        for(auto courseP: *(check_semester.second)){
            if ((*courseP).name == c.name){
                return;
            }
    }
    }

    //check if the semester exists if not then create the semester
    if (DB[id].find(semester) == DB[id].end()) {
        list<course*>* newSemesterP = new list<course*>();
        DB[id][semester] = newSemesterP;
        DB[id][semester]->push_back(new course{ c });
    }
    else {
        course* theCourse = new course{ c };
        auto it1 = DB[id][semester]->begin();
        for (it1; it1 != DB[id][semester]->end(); it1++) {
            course theName = *(*it1);
            if ((theName < *theCourse) == false){
                DB[id][semester]->insert(it1, theCourse);
                return;
            }
        }

        DB[id][semester]->insert(it1, theCourse);
    }
    //if (DB[id][semester] == nullptr) {
    //    list<course*>* courseListP = new list<course*>();
    //    course* cP1 = new course{ c };
    //    courseListP->push_back(cP1);
    //    DB[id][semester] = courseListP;
    //
    //    return;
    //}
    //list<course*>* courseListP = DB[id][semester];
    //list<course*> courseList = *courseListP;
    //course* cP = &c;
    //auto iter2 = courseList.begin();
    ///*for (auto curCourseP : courseList) {
    //    course curCourse = *curCourseP;
    //    if (c.name < curCourse.name) {
    //        courseList.push_back(cP);
    //        return;
    //    }
    //}*/
    //for (iter2; iter2 != courseList.end(); iter2++) {
    //    course curCourse = *(*iter2);
    //    if (c.name < curCourse.name) {
    //        courseList.insert(iter2, cP);
    //        return;
    //    }
    //}
    //courseList.push_back(cP);
}

void drop_course(map<int, map<int, list<course*>*>>& DB, int semester, int id, course c) {
    //check student
    if (DB.find(id) == DB.end() || DB[id].find(semester) == DB[id].end()) return;
    
    //check the semester and course if found the same name of course then delete the course pointer
    //and also erase the iterator of that pointer to keep the map in order
    for(auto it_list = DB[id][semester]->begin(); it_list != DB[id][semester]->end(); it_list++){
        course theCourse = **it_list;
        if (theCourse.name == c.name){
            delete* it_list;
            DB[id][semester]->erase(it_list);
        }
    }
}

void print_student_semester_courses(map<int, map<int, list<course*>*>>& DB, int semester, int id) {
//
//    for (auto itrator = (*DB[id][semester]).begin(); itrator != (*DB[id][semester]).end(); itrator++) {
//        cout << (*itrator)->name << (*itrator)->credits << (*itrator)->grade << (*itrator)->section << endl;
//    }
    //return;
    cout << "Student ID = " << id << endl;
    cout << "Semester = " << semester << endl;
    for(auto courseP: *DB[id][semester]){
        cout <<"("<< (*courseP).name << " " << (*courseP).section << " " << (*courseP).credits << " "<<(*courseP).grade<< ")"<< " ";
    }
    cout<<endl;
    cout<<endl;
    
}

void print_student_all_courses(map<int, map<int, list<course*>*>>& DB, int id){
    if (DB.find(id) == DB.end()) {
        return;
    }
    cout<<"Student ID = " << id <<endl;
    for(auto sem:DB[id]){
        cout<<"Semester ="<<sem.first<<endl;
        for (auto courseP: *DB[id][sem.first]){
            cout <<"("<< (*courseP).name << " " << (*courseP).section << " " << (*courseP).credits <<" " << (*courseP).grade<< ")"<< " ";
        }
        cout<<endl;
    }
}

ostream& operator<<(ostream& str, map<int, map<int, list<course*>*>>& DB){
    str<<endl;
   
    for (auto student : DB) {
        str << "Student ID = " << student.first << endl;
        for (auto semester : student.second) {
            str << "semester = " << semester.first << endl;
            for(auto courseP: *(semester.second)){
                str <<"("<< (*courseP).name << " " << (*courseP).section << " " << (*courseP).credits << " " <<(*courseP).grade << ")"<< " ";
                }
            str << endl;
                
            }
        str << endl;
        }
    return str;
}

int main() {
    map<int, map<int, list<course*>*>> DB;
    add_student(DB, 11111);
    course C1("CIS554", 1, 3, "A-"), C2("CSE674", 1, 3, "B+"), C3("MAT296", 8, 4, "A"), C4("WRT205", 5, 3, "A");

    add_course(DB, 20171, 11111, C1);
    add_course(DB, 20171, 11111, C4);
    add_course(DB, 20171, 11111, C3);
    add_course(DB, 20171, 11111, C2);
    print_student_semester_courses(DB, 20171, 11111);

    drop_course(DB, 20171, 11111, C1);
    print_student_semester_courses(DB, 20171, 11111); //sorted according to course name

    course C5("CIS351", 2, 3, "A-"), C6("PSY205", 5, 3, "B+"), C7("MAT331", 2, 3, "A"), C8("ECN203", 4, 3, "A");
    add_course(DB, 20172, 11111, C5);
    add_course(DB, 20172, 11111, C6);
    add_course(DB, 20172, 11111, C7);
    add_course(DB, 20172, 11111, C8);
    add_course(DB, 20172, 11111, C3);
    print_student_all_courses(DB, 11111);//ID GPA

    add_student(DB, 11112);
    add_course(DB, 20171, 11112, C2);
    add_course(DB, 20171, 11112, C5);
    add_course(DB, 20171, 11112, C7);
    add_course(DB, 20171, 11112, C4);
    print_student_semester_courses(DB, 20171, 11112);

    add_course(DB, 20172, 11112, C8);
    add_course(DB, 20172, 11112, C3);
    add_course(DB, 20172, 11112, C5);
    add_course(DB, 20172, 11112, C1);
    print_student_semester_courses(DB, 20172, 11112);

    print_student_all_courses(DB, 11112);

    cout << DB << endl;
    remove_student(DB, 11111);
    cout << DB << endl;

    return 0;
}
