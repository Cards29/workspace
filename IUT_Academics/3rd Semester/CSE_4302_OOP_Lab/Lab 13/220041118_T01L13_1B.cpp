#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person() : name("Rahinur"), id(220041118) {}

    void getPersonData(string _name, int _id) {
        name = _name;
        id = _id;
    }
    void displayPersonData() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class Student : public Person {
private:
    set<string> coursesEnrolled;
public:
    Student() : Person::Person() {}

    void addCourse(string _course) {
        coursesEnrolled.insert(_course);
    }
    void displayStudentData() const {
        Person::displayPersonData();
        cout << "Courses Enrolled: ";
        for (auto i : coursesEnrolled) cout << i << ", ";
        cout << endl;
    }
    string studentInfoForFile() {
        string str;
        str += name;
        str += " ";
        str += to_string(id);
        str += " ";
        for (auto i : coursesEnrolled) {
            str += i;
            str += " ";
        }
        return str;
    }
};

class Instructor : public Person {
private:
    set<string> coursesTeaching;
public:
    Instructor() : Person::Person() {}

    void addCourse(string _course) {
        coursesTeaching.insert(_course);
    }
    void displayInstructorData() const {
        Person::displayPersonData();
        cout << "Courses Teaching: ";
        for (auto i : coursesTeaching) cout << i << ", ";
        cout << endl;
    }
    string instructorInfoForFile() {
        string str;
        str += name;
        str += " ";
        str += to_string(id);
        str += " ";
        for (auto i : coursesTeaching) {
            str += i;
            str += " ";
        }
        return str;
    }
};



class manageCourses {
private:
    map<string, string> courses;
    vector<Student> students;
    vector<Instructor> instructors;
public:

    void addCourse(string courseCode, string courseName) {
        courses[courseCode] = courseName;
    }
    void enrollStudent(string _name, int _id, string courseCode) {
        Student s1;
        s1.getPersonData(_name, _id);
        s1.addCourse(courses[courseCode]);
        students.push_back(s1);
    }
    void assignInstructor(string _name, int _id, string courseCode) {
        Instructor i1;
        i1.getPersonData(_name, _id);
        i1.addCourse(courses[courseCode]);
        instructors.push_back(i1);
    }
    void displayCourses() const {
        for (auto i : courses)
            cout << "Code: " << i.first << ", Name: " << i.second << endl;
    }
    void displayStudents() const {
        for (auto i : students) {
            i.displayStudentData();
            cout << endl;
        }
    }
    void displayInstructors() const {
        for (auto i : instructors) {
            i.displayInstructorData();
            cout << endl;
        }
    }
    void saveData() const {
        ofstream o1("courses.txt");
        for (auto i : courses)
            o1 << i.first << " " << i.second << endl;

        ofstream o2("students.txt");
        for (auto i : students)
            o2 << i.studentInfoForFile() << endl;

        ofstream o3("instructors.txt");
        for (auto i : instructors)
            o3 << i.instructorInfoForFile() << endl;
    }
    void loadData() {
        // ifstream i1("courses.txt");
        // string _name, courseCode, _id, courseName;
        // if(i1.is_open()) {
        //     while (i1 >> _name >> courseCode) {
        //         courses[codeCourse] = _name;
        //     }
        // }

        // ifstream i2("students.txt");
        // s
        // if(i2.is_open()) {

        // }
    }
};



int main() {
    manageCourses MC;
    int t;
    cout << "1. Add Course\n"
        << "2. Enroll Student\n"
        << "3. Assign Instructor\n"
        << "4. Display Data\n"
        << "5. Save Data\n"
        << "6. Load Data\n"
        << "7. Exit\n"
        << "Enter your choice: ";

    while (cin >> t) {
        if (t == 7) {
            cout << "Exiting program...\n";
            break;
        }
        string courseCode, courseName, name;
        int id;
        switch (t) {
        case 1:
            cout << "Enter course code: ";
            cin >> courseCode;
            cout << "Enter course name: ";
            cin >> courseName;
            MC.addCourse(courseCode, courseName);
            cout << "Course added successfully!\n\n";
            break;
        case 2:
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter course code: ";
            cin >> courseCode;
            cout << "Enter student name: ";
            cin >> name;
            MC.enrollStudent(name, id, courseCode);
            cout << "Student enrolled successfully!\n\n";
            break;
        case 3:
            cout << "Enter instructor ID: ";
            cin >> id;
            cout << "Enter course code: ";
            cin >> courseCode;
            cout << "Enter instructor name: ";
            cin >> name;
            MC.assignInstructor(name, id, courseCode);
            cout << "Instructor assigned successfully!\n\n";
            break;
        case 4:
            cout << "Courses:\n";
            MC.displayCourses();
            cout << "\nStudents\n";
            MC.displayStudents();
            cout << "Instructors:\n";
            MC.displayInstructors();
            cout << endl;
            break;
        case 5:
            MC.saveData();
            cout << "Data saved to files!\n";
            break;
        default:
            break;
        }
        cout << "1. Add Course\n"
            << "2. Enroll Student\n"
            << "3. Assign Instructor\n"
            << "4. Display Data\n"
            << "5. Save Data\n"
            << "6. Load Data\n"
            << "7. Exit\n"
            << "Enter your choice: ";
    }


    return 0;
}