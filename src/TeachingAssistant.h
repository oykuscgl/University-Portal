#include <string>
#include <iostream>
#include <fstream>
#include "User.h"
#include "Professor.h"
#include "Student.h"
using namespace std;

class TeachingAssistant: protected Student, protected Professor
{
private:
    
    int courseID; //the course id 
public:

    TeachingAssistant(){
        userName = "";
        password = "";
        name = "";
        myFaculty = "";
        email = "";
        phone = 0;
        myCourses[MAXCOURSES]= [];
        address = "";
        gpa = 0.0;
        birthYear = 0;
        numOfCourses=0;
        debtInformation=0;
        studentID=0;
        gender='';
        
    }


    string seeCourseInfo();
    string attendanceList();  // reach to attendance list file for the specific course
    string seeGrades();  // see the grades of each student for the specific course.
    dropCourse(); // assistant can drop the course
    string updateInfo(); // assistant can update address and telephone number info

    TeachingAssistant(int courseID):User,Student,Lecturer;
    {
        this->courseID = courseID;
    }

    string getName()
    {
        return name;
    }
    void setName(string nm)
    {
        name = nm;
    }

    string getEmail()
    {
        return email;
    }
    void setEmail(const string mail)
    {
        email = mail;
    }

    long getPhone()
    {
        return phone;
    }
    void setPhone(long phoneNum)
    {
        phone = phoneNum;
    }

    unsigned long getStudentID()
    {
        return studentID;
    }

    void setStudentID(unsigned long ID)
    {
        studentID = ID;
    }

    string getMyFaculty()
    {
        return myFaculty;
    }

    void setMyFaculty(string faculty)
    {
        myFaculty = faculty;
    }

    const string& getMyCourse(int index)  
    {
        if (index >= 0 && index < MAXCOURSES) {
            return myCourses[index];
        } else {
            // Handle index out of bounds
            static string emptyString = "";
            return emptyString;
        }
    }

    void setMyCourse(int index, const string& course) 
    {
        if (index >= 0 && index < MAXCOURSES) {
            myCourses[index] = course;
        } else {
            // Handle index out of bounds
            cerr << "Index out of bounds." << endl;
        }
    }

    const string& getAddress() 
    {
        return address;
    }

    void setAddress(const string& addr) 
    {
        address = addr;
    }

    float getGPA()
    {
        return gpa;
    }

    void setGPA(float studentGPA)
    {
        gpa = studentGPA;
    }

    int getBirthYear()
    {
        return birthYear;
    }
    void setBirthYear(int year)
    {
        birthYear = year;
    }

    int getNumOfCourses() const {
        return numOfCourses;
    }

    void setNumOfCourses(int numCourses) {
        numOfCourses = numCourses;
    }


    int getDebtInformation() const {
        return debtInformation;
    }

    void setDebtInformation(int debtInfo) 
    {
        debtInformation = debtInfo;
    }

    char getGender() const {
        return gender;
    }

    void setGender(char gen) {
        gender = gen;
    }


    void saveToFile(){
        Student::saveToFile();
    }

    void updateInfoToCSV(const string &fileName)
    {
        ofstream file(fileName, ios::out | ios::app);

        if (file.is_open())
        {
            file << name << ", ";
            file << myFaculty << ", ";
            file << email << ", ";
            file << phone << ", ";
            for (int i = 0; i < numOfCourses; i++)
            {
                if (myCourses[i] == myCourses[numOfCourses - 1])
                    file << myCourses[i];
                else
                    file << myCourses[i] << "/";
            }
            file << ", ";
            file << address << ", ";
            file << gpa << ", ";
            file << birthYear << ", ";
            file << numOfCourses << ", ";
            file << debtInformation << ", ";
            file << studentID << ", ";
            file << gender << endl;

            file.close();
            cout << "Student Information was updated in the database" << endl;
        }
        else
            cout << "Unable to update the information" << endl;  
    }

    void seeCourses(){
        Student::seeCourses();
    }


    void seeEnrolledCourses(){
        Student::seeEnrolledCourses();
    }
    void addRemoveCourse(){
        Student::addRemoveCourse();
    }

    void seeDebtInformation(){
        Student::seeDebtInformation();
    }

    gpaCalculator(){
        Student::gpaCalculator();
    }

    printPersonalInfo(){
        Student::printPersonalInfo();
    }
    changeInfo(){
        student::changeInfo();
    }

    void Ta Menu()
    {
        int chosen;
        cout << "-----------------TA Menu-----------------" << endl;
        cout << "1) See all courses" << endl;
        cout << "2) See enrolled courses" << endl;
        cout << "3) Add or Remove courses" << endl;
        cout << "4) See debt information" << endl;
        cout << "5) GPA Calculator" << endl;
        cout << "6) Print personal information " << endl;
        cout << "7) Change information " << endl;
        cout << "Choose the operation: ";
        cin >> chosen;
        switch (chosen)
        {
            case 1:
                seeCourses();
                break;

            case 2:
                seeEnrolledCourses();
                break;

            case 3:
                addRemoveCourse();
                break;  

            case 4:
                seeDebtInformation();
                break;
                
            case 5:
                gpaCalculator();
                break;

            case 6:
                printPersonalInfo();
                break;

            case 7:
                changeInfo();
                break;                            

            default:
                break;
        }
    }
      
};


