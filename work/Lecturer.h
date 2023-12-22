#include <string>
using namespace std;


class Professor
{
    int courseId;
    int phone;
    string mail;
    string birth;

    string seeCourse(); // see all the courses that lecturer gives
    string addCourse(); // add another course
    int deleteCourse(); // delete a course
    string editCourseInfo(); //change the description of the course
    string seeGrades();  // will take the courseID as parameter and show each grade for that selected course. Lecturer can only choose courses that she is teaching
    int editGrades(); //will give notes for only the courses she gave
    string seeAttendance();
    string updateInfo(); //lecturer can only update phone number and address info



};