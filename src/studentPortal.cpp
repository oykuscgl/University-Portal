#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Lecturer.h"
#include "Student.h"
#include "TeachingAssistant.h"
#include "Admin.h"
using namespace std;

int main()
{
    
        Student student;
    // Set values using setters
    student.setName("Öykü");
    student.setMyFaculty("Engineering");
    student.setEmail("oyku.sucuoglu@stu.khas.edu.tr");
    student.setPhone(5388537588);
    student.setMyCourse(0, "CMPE241");
    student.setMyCourse(1, "CMPE341");
    student.setMyCourse(2, "CMPE343");
    student.setMyCourse(3,"CMPE351");
    student.setMyCourse(4, "CMPE353");
    student.setAddress("Maltepe");
    student.setGPA(3.5);
    student.setBirthYear(2002);
    student.setNumOfCourses(5);
    student.setDebtInformation(5000);
    student.setStudentID(20201701057);
    student.setGender('F');

    const string studentFile = "students.csv";
    //student.saveToFile(studentFile);

    Student student1;
    student1.setName("Kayra");
    student1.setMyFaculty("Engineering");
    student1.setEmail("kayra.akbas@stu.khas.edu.tr");
    student1.setPhone(5324536213);
    student1.setMyCourse(0, "CMPE241");
    student1.setMyCourse(1, "CMPE341");
    student1.setMyCourse(2, "CMPE343");
    student1.setMyCourse(3,"CMPE351");
    student1.setMyCourse(4, "CMPE353");
    student1.setAddress("Beylikdüzü");
    student1.setGPA(3.5);
    student1.setBirthYear(2002);
    student1.setNumOfCourses(5);
    student1.setDebtInformation(1000);
    student1.setStudentID(20201701053);
    student1.setGender('M');

    //student1.saveToFile(studentFile);

    Student student2;
    student2.setName("Leyla");
    student2.setMyFaculty("Engineering");
    student2.setEmail("leyla.can@stu.khas.edu.tr");
    student2.setPhone(5324536213);
    student2.setMyCourse(0, "");
    student2.setMyCourse(1, "");
    student2.setMyCourse(2, "");
    student2.setMyCourse(3,"");
    student2.setMyCourse(4, "");
    student2.setMyCourse(5, "");
    student2.setAddress("Kadıköy");
    student2.setGPA(3.1);
    student2.setBirthYear(2001);
    student2.setNumOfCourses(6);
    student2.setDebtInformation(0);
    student2.setStudentID(20191601046);
    student2.setGender('F');    

    //student2.saveToFile(studentFile);

    Admin admin;
    Admin admin1;

    const string adminFile = "admin.csv";



    Lecturer lecturer;
    Lecturer lecturer1;
    Lecturer lecturer2;
    Lecturer lecturer3;

    const string lecturerFile = "lecturer.csv";



    TeachingAssistant ta;
    TeachingAssistant ta1;
    TeachingAssistant ta2;
    TeachingAssistant ta3;
    TeachingAssistant ta4;
    const string teachAstFile = "teacAst.csv";


/*
    student will enter with student ID
    lecturer will enter with a user name like oykscgl
    admin will enter with a user name
    teachAsst will enter with a user name
*/
    string user;
    string password;
    cout <<  "------------------------------School Login Page------------------------------" << endl;
    cout << "User:  ";
    cin >> user;
    cout << "Password: " << endl;
    cin >> password;
    system("clear");

//check if the entered user name belongs to student class
    if(user == "20201701057" || user == "20201701053")
    {
        int chosen;
        cout << "------------------------------Student Login------------------------------" << endl;
        cout << "Choose the wanted operation:" << endl;
        cout << "1) See All Courses\n";
        cout << "2) See Enrolled Courses\n";
        cout << "3) Add/Remove Course\n";
        cout << "4) See Debt Info\n";
        cout << "5) GPA Calculator\n";
        cout << "6) Personal Info\n"; 
        cout << "7) Update Your Information\n";    
        cin >> chosen; 
        system("clear");

        switch(chosen)
        {
            case 1:
                student.seeCourses();
                break;
            case 2:
                student.seeEnrolledCourses(student);
                break;
            case 3:
                student.addRemoveCourse(student);
                break;
            case 4:
                student.seeDebtInformation(student);
            break;
            case 5:
                student.gpaCalculator(student);
                break;
            case 6:
                student.printPersonalInfo(student);
                break;
            case 7:
                student.changeInfo(student);
                break;
                
        }
    }

//check if the entered user name belongs to lecturer class
    if(user == "fabstr" || user == "ilkar" || user=="dgncrs" || user == "nmajfr")
    {
        cout << "------------------------------Lecturer Login------------------------------" << endl;
        cout << "Choose the wanted operation:" << endl;
        cout << "1) See Your Courses\n";
        cout << "2) Add New Course\n";
        cout << "3) Remove Course\n";
        cout << "4) Edit Course Info\n";
        cout << "5) See/Edit Grades\n";
        cout << "6) Update Your Information\n";

    }

//check if the username belong to admin class
    if(user == "admin" || user == "admin1")
    {
        cout << "------------------------------Admin Login------------------------------" << endl;
        cout << "Choose the wanted operation:" << endl;
        cout << "1) \n"; 
    }

//check if the username belong to teaching assistant class
    if(user == "a" || user == "b" || user == "c")
    {
        cout << "------------------------------Teaching Assistant Login------------------------------" << endl;
        cout << "Choose the wanted operation:" << endl;
        cout << "1) \n";        
    } 

}




