
#ifndef TeachingAssistant_H
#define TeachingAssistant_H
#include <string>
#include <iostream>
#include <fstream>
#include "User.h"
#include "Student.h"
using namespace std;

class TeachingAssistant: public Student
{
private:
    
    int courseID; //the course id 
public:

    TeachingAssistant()
    {
        userName = "";
        password = "";
        name = "";
        myFaculty = "";
        email = "";
        phone = 0;
        for (int i = 0; i < MAXCOURSES; i++) {
            myCourses[i] = "";
        }
        address = "";
        gpa = 0.0;
        birthYear = 0;
        numOfCourses=0;
        debtInformation=0;
        studentID=0;
        gender = '\0';
        
    }

    TeachingAssistant(int courseID)
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


    void saveToFile(const string &fileName)
    {
        Student::saveToFile(fileName);
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
            file << getStudentID() << ", ";
            file << getGender() << endl;

            file.close();
            cout << "Student Information was updated in the database" << endl;
        }
        else
            cout << "Unable to update the information" << endl;  
    }

    void seeCourses()
    {
        Student::seeCourses();
    }


    void seeEnrolledCourses()
    {
        Student::seeEnrolledCourses();
    }
    void addRemoveCourse()
    {
        Student::addRemoveCourse();
    }

    void seeDebtInformation()
    {
        Student::seeDebtInformation();
    }

    void gpaCalculator() {Student::gpaCalculator();}


    void printPersonalInfo()
    {
        cout << "Your personal Information:" << endl;
        cout << "User name: " << this->userName << endl;
        cout << "Name: " << this->name << endl;
        cout << "Faculty: " << this->myFaculty << endl;
        cout << "Email: " << this->email << endl;
        cout << "Phone: " << this->phone << endl;

        cout << "Enrolled Courses: ";
        for (int i = 0; i < this->numOfCourses; ++i)
        {
            cout << this->myCourses[i];
            if (i < this->numOfCourses - 1)
                cout << ", ";
        }
        cout << endl;

        cout << "Address: " << this->address << endl;
        cout << "GPA: " << this->gpa << endl;
        cout << "Birth Year: " << this->birthYear << endl;
        cout << "Student ID: " << this->studentID << endl;
        cout << "Gender: " << this->gender << endl;
    }
    
    void changeInfo()
    {
        Student::changeInfo();
    }

    void TaMenu()
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
                TeachingAssistant::seeCourses();
                break;

            case 2:
                TeachingAssistant::seeEnrolledCourses();
                break;

            case 3:
                TeachingAssistant::addRemoveCourse();
                break;  

            case 4:
                TeachingAssistant::seeDebtInformation();
                break;
                
            case 5:
                TeachingAssistant::gpaCalculator();
                break;

            case 6:
                TeachingAssistant::printPersonalInfo();
                break;

            case 7:
                TeachingAssistant::changeInfo();
                break;                            
        }
    }
      
};
#endif