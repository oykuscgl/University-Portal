#include <string>
#include <iostream>
using namespace std;
#define MAXCOURSES 10

class Lecturer
{
    string name;
    string myCourses[MAXCOURSES];
    string phone;
    string email;
    string birth;
    char gender;

    

    string getName()
    {
        return name;
    }
    void setName(string nm)
    {
        name = nm;
    }

        const string& getMyCourses(int index)  
    {
        if (index >= 0 && index < MAXCOURSES) {
            return myCourses[index];
        } else {
            // Handle index out of bounds
            static std::string emptyString = "";
            return emptyString;
        }
    }

    void setMyCourses(int index, const string& course) 
    {
        if (index >= 0 && index < MAXCOURSES) {
            myCourses[index] = course;
        } else {
            // Handle index out of bounds
            cerr << "Index out of bounds." << endl;
        }
    }
    

    


    string seeYourCourses(); // see all the courses that lecturer gives
    string addNewCourse(); // add another course
    int deleteCourse(); // delete a course
    string editCourseInfo(); //change the description of the course
    string seeGrades();  // will take the courseID as parameter and show each grade for that selected course. Lecturer can only choose courses that she is teaching
    int editGrades(); //will give notes for only the courses she gave
    string seeAttendance();
    string updateInfo(); //lecturer can only update phone number and address info



};