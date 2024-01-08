
#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "User.h"
#include "Lecturer.h"
#include "Student.h"
#include "TeachingAssistant.h"
#include "Admin.h"
#include "Login.h"
using namespace std;


int main()
{
    
    Student student;
    // Set values using setters
    student.setUserName("oykusucuoglu");
    student.setPassword("sucuoglu");
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
    student.saveToFile(studentFile);

    Student student1;
    student1.setUserName("kayraakbas");
    student1.setPassword("akbas");
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

    student1.saveToFile(studentFile);

    Student student2;
    student2.setUserName("leylaakbas");
    student2.setPassword("akbas");
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
    student2.setAddress("Kadikoy");
    student2.setGPA(3.1);
    student2.setBirthYear(2001);
    student2.setNumOfCourses(6);
    student2.setDebtInformation(0);
    student2.setStudentID(20191601046);
    student2.setGender('F');    

    student2.saveToFile(studentFile);

// Adding admins
    Admin admin;
    Admin admin1;

    const string adminFile = "admin.csv";



// Adding lecturers
    Lecturer lecturer;  
    Lecturer lecturer1;
    Lecturer lecturer2;
    Lecturer lecturer3;

    const string lecturerFile = "lecturer.csv";



// Adding teaching assistants
    TeachingAssistant ta;
    TeachingAssistant ta1;

    const string teachAstFile = "teachAst.csv";

    login();



}