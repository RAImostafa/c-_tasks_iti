#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    Person(const string& Name) : name(Name) {}
    virtual ~Person() {}

    string getName(void ) const {
        return name;
    }
};

class Student : public Person {
private:
    int studentID;

public:
    Student(const string& Name, int StudentID) : Person(Name), studentID(StudentID) {}

    int getStudentID() const {
        return studentID;
    }
};

class Teacher : public Person {
private:
    int teacherID;

public:
    Teacher(const string& Name, int TeacherID) : Person(Name), teacherID(TeacherID) {}

    int getTeacherID() const {
        return teacherID;
    }
};

class TeachingAssistant : public Student, public Teacher {
private:
    string course;

public:
    TeachingAssistant(const string& Name, int StudentID, int TeacherID, const string& Course)
        : Student(Name, StudentID), Teacher(Name, TeacherID), course(Course) {}

    string getCourse() const {
        return course;
    }
};

int main() {
   
 
   Student stu ("reem" , 89);
   cout<<stu.getName()<<endl;

   /*Teacher tea ("Aly" , 789999);
    TeachingAssistant obj("ali", 888, 7898, "Computer Science");

    cout << " Teacher's Name: " << obj.Teacher::getName()<< endl;
    cout << " Students's Name: " << obj.Student::getName()<< endl;
    cout << "Student ID: " << obj.getStudentID() << endl;
    cout << "Teacher ID: " << obj.getTeacherID() << endl;
    cout << "Course: " << obj.getCourse() << endl;*/

    return 0;
}
