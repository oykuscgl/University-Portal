#include <string>
#include <fstream>
#include <iostream>
using namespace std;
#define MAXCOURSES 10

//student ID, GPA calculation function(access to studentScoreboard, only the specific student), See enrolled courses function(acces to studentCourses file), see content of the courses function(choose a course name and acces to course info file), access to attendance list function(only for the specific student), changing the phone number(access to student file only for the specific student)

class Student
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
        }
        else    
        {
            cout << "Unable to open the file" << endl;
        }
    }

    void seeEnrolledCourses(Student student)
    {
        cout << "Enrolled Courses: " << endl;
        for(int i=0; i<numOfCourses;i++)
            cout << student.myCourses[i] << ", ";
    }


//Add or remove a course for that specific student
//The database of studentCourse will be updated. New course for that student will be added. 
    void addRemoveCourse(Student student)
    {
        int n;
        cout << "Choose operation:\n1)Add new course\n2)Remove remaining course";
        cin >> n;
        if(n==1)
        {

        }
        else if(n==2)
        {

        }
        else
            cout << "Invalid value." << endl;
             
    }


//See debt information for that specific student
    void seeDebtInformation(Student student)
    {
        cout << "Debt Info" << endl;
        cout << student.debtInformation << " $" << endl;
    }

//Enter each letter grade and calculate the GPA for entered lecture
    int gpaCalculator(Student student)
    {
        unsigned short ID, mid, fin, courseNum;
        int grade = 0;

        //function will reach to student's enrolled courses. Will take an input for each course.
 

        //calculate the GPA
        for(int i=0; i<courseNum; i++)
        {
            cout << "Enter the Course ID: ";
            cin >> ID; 

            cout << "Enter the Midterm Grade: ";
            cin >> mid;
            mid = mid*40/100;

            cout << "Enter the Final Grade: ";
            cin >> fin;
            fin = fin*60/100;

            grade = mid + fin;
        }
        return grade/courseNum;

    }

    void printPersonalInfo(Student student);

    void changeInfo(Student student );


 
        
};