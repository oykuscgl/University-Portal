#include <string>

//student ID, GPA calculation function(access to studentScoreboard, only the specific student), See enrolled courses function(acces to studentCourses file), see content of the courses function(choose a course name and acces to course info file), access to attendance list function(only for the specific student), changing the phone number(access to student file only for the specific student)
class Student
{
    int getStudentID(void);
    void setStudentID(int);
    
    //this func will calculate the GPA of the student via accessing the scoreboard and only getting the total of the relevant student ID
    void calculateGPA(int studentID);

    // this function will access to the studentCourse file and only read the relevant student ID course name and IDs.
    void enrolledCourses(int studentID);

    // this function will access to the courses file and print them on the terminal
    void courseContent();


    // this func will access to the attendance list file and read the relevant student ID info
    void attendance(int studentID);


    // this func will access to student file and allow the student to change only the email address info. 
    void changeInfo(int studentID);

        
};