#include <string>
using namespace std;

class TeachingAssistant
{
    int phone;
    string mail;
    string birth;
    int courseID; //the course id 

    string seeCourseInfo();
    string attendanceList();  // reach to attendance list file for the specific course
    string seeGrades();  // see the grades of each student for the specific course.
    void dropCourse(); // assistant can drop the course
    string updateInfo(); // assistant can update address and telephone number info


};