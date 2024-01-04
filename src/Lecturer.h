#include <string>
#include <iostream>
#include <fstream>
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
    int numOfCourses;

    

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
        if (index >= 0 && index < numOfCourses) {
            return myCourses[index];
        } else {
            // Handle index out of bounds
            static std::string emptyString = "";
            return emptyString;
        }
    }

    void setMyCourses(int index, const string& course) 
    {
        if (index >= 0 && index < numOfCourses) {
            myCourses[index] = course;
        } else {
            // Handle index out of bounds
            cerr << "Index out of bounds." << endl;
        }
    }

    //Add every attribute of the object of the Student class to students.csv database
    void saveToFile(const string &fileName)
    {
        ofstream file(fileName, ios::out |ios::app);
        if(file.is_open())
        {
            file << name << ", ";
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
            file << birth << ", ";
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
            file << numOfCourses << ", ";
            file << birth << ", ";
            file << gender << endl;

            file.close();
            cout << "Student Information was updated in the database" << endl;
        }
        else
            cout << "Unable to update the information" << endl;  
    }
    
    void seeYourCourses()
    {
        cout << "Your Courses" << endl;
        for(int i=0; i<numOfCourses; i++)
        {
            if(myCourses[i] != myCourses[numOfCourses-1])
                cout << this->myCourses[i] << ", ";
            cout << this->myCourses[i];
        }
    } 

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
            updateInfoToCSV("updated_lecturers.csv");

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
                    updateInfoToCSV("updated_lecturers.csv");
                }
                else
                    cerr << "Not a registered course" << endl;
            }
            
        }
        else
            cout << "Invalid value." << endl;

    }

    void seeGrades()
    {
        string line;
        
        ifstream file("studentScoreboard.csv");
        if(file.is_open())
        {
            cout << "Student scoreboard:" << endl;
            while(getline(file, line))
                cout << line << endl;
            file.close();
        }
        else
            cerr << "Unable to open file" << endl;
    }  

    void editGrades()
    {

    } 


    void updateInfo()
    {
        int n;
        cout << "Which information you would like to change:\n1) Phone number\n2) Birth year\n";
        cin >> n;

        if (n == 1)
        {
            cout << "Enter the new phone number: ";
            cin >> phone;
        }
        else if (n == 2)
        {
            cout << "Enter the new birth year: ";
            cin >> birth;
        }
        else
        {
            cerr << "Invalid choice." << endl;
            return;
        }

        updateInfoToCSV("updated_lecturers.csv");
    }
    

    void LecturerMenu()
    {
        int chosen;
        cout << "-----------------Student Menu-----------------" << endl;
        cout << "1) See your courses" << endl;
        cout << "2) Add or Remove courses" << endl;
        cout << "3) See grades" << endl;
        cout << "4) Edit grades" << endl;
        cout << "5) Change information " << endl;
        cout << "Choose the operation: ";
        cin >> chosen;
        switch (chosen)
        {
            case 1:
                seeYourCourses();
                break;

            case 2:
                addRemoveCourse();
                break;

            case 3:
                seeGrades();
                break;
                
            case 4:
                editGrades();
                break;

            case 5:
                updateInfo();
                break;                          

            default:
                break;
        }
    }

};