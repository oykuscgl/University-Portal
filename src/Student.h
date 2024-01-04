#include <string>
#include <fstream>
#include <iostream>
#include "User.h"
using namespace std;
#define MAXCOURSES 10

//student ID, GPA calculation function(access to studentScoreboard, only the specific student), See enrolled courses function(acces to studentCourses file), see content of the courses function(choose a course name and acces to course info file), access to attendance list function(only for the specific student), changing the phone number(access to student file only for the specific student)

class Student: public User
{

    protected: 
    string name;
    string myFaculty;
    string email;
    long phone;
    string myCourses[MAXCOURSES];
    string address;
    float gpa;
    int birthYear;
    int numOfCourses;
    int debtInformation;
    unsigned long studentID;
    char gender;


    public:
    // Constructor
    Student() : gpa(0.0), numOfCourses(0), debtInformation(0), studentID(0), gender(' ') {}


    public:
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

       // Getter and setter for myCourses
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

    // Getter and setter for address
    const string& getAddress() 
    {
        return address;
    }

    void setAddress(const string& addr) 
    {
        address = addr;
    }

    // Getter and setter for gpa
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

    // Getter and setter for numOfCourses
    int getNumOfCourses() const {
        return numOfCourses;
    }

    void setNumOfCourses(int numCourses) {
        numOfCourses = numCourses;
    }

    // Getter and setter for debtInformation
    int getDebtInformation() const {
        return debtInformation;
    }

    void setDebtInformation(int debtInfo) 
    {
        debtInformation = debtInfo;
    }


    // Getter and setter for gender
    char getGender() const {
        return gender;
    }

    void setGender(char gen) {
        gender = gen;
    }

    //Add every attribute of the object of the Student class to students.csv database
    void saveToFile(const string &fileName)
    {
        ofstream file(fileName, ios::out |ios::app);
        if(file.is_open())
        {
            file << name << ", ";
            file << myFaculty << ", ";
            file << email << ", ";
            file << phone << ", ";
            for(int i=0;i<numOfCourses;i++)
            {
                if(myCourses[i] == myCourses[numOfCourses-1])
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
            cout << "Student Information was added to the database" << endl;
        }
        else
        {
            cout << "Unable to load the information" << endl;
        }
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



    //See all courses in the database
    void seeCourses()
    {
        string line, fileName = "courses.csv";
        fstream file(fileName);
        if(file.is_open())
        {
            cout << "Courses: " << endl;
            while(getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else    
        {
            cout << "Unable to open the file" << endl;
        }
    }

    void seeEnrolledCourses()
    {
        cout << "Enrolled Courses: " << endl;
        for(int i=0; i<numOfCourses;i++)
            cout << this->myCourses[i] << ", ";
    }


    //Add or remove a course for that specific student
    //The database of studentCourse will be updated. New course for that student will be added. 
    void addRemoveCourse()
    {
        int n;
        cout << "Choose operation:\n1)Add new course\n2)Remove remaining course";
        cin >> n;
        if(n==1)
        {
            string newCourse;
            cout << "Enter course ID: ";
            cin >> newCourse;
            numOfCourses++;
            myCourses[numOfCourses-1] = newCourse;
            updateInfoToCSV("updated_students.csv");

        }
        else if(n==2)
        {
            string removeCourse;
            for(int i=0; i<numOfCourses;i++)
            {
                if(myCourses[i] != myCourses[numOfCourses-1])
                    cout << myCourses[i] << ", ";
                cout << myCourses[i] << endl;
            }
            for(int i=0; i<numOfCourses; i++)
            {
                if(myCourses[i] == removeCourse)
                {
                    myCourses[i] = "";
                    updateInfoToCSV("updated_students.csv");
                }
                else
                    cerr << "Not a registered course" << endl;
            }
            
        }
        else
            cout << "Invalid value." << endl;
             
    }


    //See debt information for that specific student
    void seeDebtInformation()
    {
        cout << "Debt Info" << endl;
        cout << this->debtInformation << " $" << endl;
    }

    //Enter each letter grade and calculate the GPA for entered lecture
    void gpaCalculator()
    {
        double credit, fin;
        unsigned short courseNum;
        string ID;
        int grade = 0;
        unsigned short totalCredit = 0;

        cout << "How many courses: ";
        cin >> courseNum;

        //calculate the GPA
        for(unsigned short i=0; i<courseNum; i++)
        {
            cout << "Enter the Course ID: ";
            cin >> ID; 
            cout << "Enter the Course Credit: ";
            cin >> credit;
            totalCredit += credit;


            do
            {
            cout << "Enter the Total Grade: ";
            cin >> fin;
            }while(fin > 4);

            grade += fin* credit;
        }

        cout << (double)grade/totalCredit;

    }

    void printPersonalInfo()
    {
        cout << "Your personal Information:" << endl;
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
        int n;
        cout << "Which information you would like to change:\n1) Address\n2)Phone number\n3)Birth year" << endl;
        cin >> n;
        if(n==1)
        {
            string newAdd;
            cout << "Enter the new address: ";
            cin >> newAdd;
            this->setAddress(newAdd);
            updateInfoToCSV("updated_students.csv");
        }

        else if(n==2)
        {
            long newPhone;
            cout << "Enter the new phone number: ";
            cin >> newPhone;
            this->setPhone(newPhone);            
            updateInfoToCSV("updated_students.csv");
        }

        else if(n==3)
        {
            int newYear;
            cout << "Enter the new year: ";
            cin >> newYear;
            this->setBirthYear(newYear);
            updateInfoToCSV("updated_students.csv");
        }
        else
            cerr << "Unauthorized." << endl;        
        
    }

    void StudentMenu()
    {
        int chosen;
        cout << "-----------------Student Menu-----------------" << endl;
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