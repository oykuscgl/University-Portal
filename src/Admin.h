#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Admin
{
private:
    
public:

void adminMenu();

// Functions to write databases
void addNewStudent();
void addNewLectuer();
void addNewCourses();

void removeStudent();
void removeLecturer();
void removeCourse();


// Functions to read databases
void readFile(string);
void getAllCourses();
void getAllLecturerCourse();
void getAllLecturers();
void getAllStudents();
void getAllStudentScoreBoards();
void getAllStudentsCourse();

void getAllDatabase();

};

void Admin::addNewStudent(){

    string name = "studentscopy.csv";
    ofstream file (name,ios::app); // Open file in append mode
    if (file.is_open())
    {
        string stdId,stdName,stdDoB,stdGender,stdEmail,StdPhone,StdDep;
        cout<< "Add student ID: "<<endl;
        getline(cin, stdId);
        cout<< "Write the student name: "<<endl;
        getline(cin, stdName);
        cout<< "Write the student date of birth: "<<endl;
        getline(cin, stdDoB);
        cout<< "Write the student gender: "<<endl;
        getline(cin, stdGender);
        cout<< "Write the student schoo mail: "<<endl;
        getline(cin, stdEmail);
        cout<< "Enter the student phone: "<<endl;
        getline(cin, StdPhone);
        cout<< "Write the student department: "<<endl;
        getline(cin, StdDep);

        file << stdId <<","
        << stdName<< " , "
        << stdDoB<<" , "
        << stdGender<<" , "
        << stdEmail<<" , "
        << StdPhone<<" , "
        << StdDep<<endl;
        file.close();
        cout << "Student added.";

    }
    else cout << "Unable to open file " << name;
}

void Admin::addNewLectuer(){
    string name = "Database/lecturers.csv";
    ofstream file (name,ios::app); // Open file in append mode
    if (file.is_open())
    {
        string lecUserName,lecName,lecGender;
        cout<< "Write the lectuer user name: "<<endl;
        getline(cin, lecUserName);
        cout<< "Write the lectuer full name: "<<endl;
        getline(cin, lecName);
        cout<< "Write the lectuer gender: "<<endl;
        getline(cin, lecGender);
     

        file << lecUserName <<","
        << lecName<< " , "
        << lecGender<<" , ";   
        file.close();
        cout << "Lectuer added.";

    }
    else cout << "Unable to open file " << name;

}

void Admin::addNewCourses(){

    string name = "Database/courses.csv";
    ofstream file (name,ios::app); // Open file in append mode
    if (file.is_open())
    {
        string courseID,courseName,room,teachingAssistances;
        cout<< "Enter the Course ID: "<<endl;
        getline(cin, courseID);
        cout<< "Enter the Course Name:"<<endl;
        getline(cin, courseName);
        cout<< "Enter the Room:"<<endl;
        getline(cin, room);
        cout<< "Enter the Teaching Assistants:"<<endl;
        getline(cin, teachingAssistances);
     

        file << courseID <<","
        << courseName<< " , "
        << room<<" , "
        << teachingAssistances<<endl;     
        file.close();
        cout << "Course added.";

    }
    else cout << "Unable to open file " << name;

}


void Admin::removeStudent(){

    // Open the input and output files
    std::ifstream inputFile("studentscopy.csv");
    std::ofstream outputFile("temp.csv");
    int lineInput;
    cout << "Please enter the line you want to remove: ";
    cin >> lineInput;
    if (inputFile.is_open() && outputFile.is_open() && lineInput != 1){
        
        
        string line;
        int currentLineNumber = 1;
        

        

        while (getline(inputFile, line)) {
            if(currentLineNumber != lineInput) {
                outputFile << line << std::endl;
            }   
            currentLineNumber++;
        }

        // Close the input and output files
        inputFile.close();
        outputFile.close();

         // Remove the original file
        if (remove("studentscopy.csv") != 0 ) {
            cerr << "Error deleting original file." << endl;
        }

        // Rename the temporary file to the original file name
        if (rename("temp.csv", "studentscopy.csv") != 0) {
            cerr << "Error renaming file." << endl;
        }

    
        cout << "Line " << lineInput << " deleted successfully." <<endl;
    
    }
    else
        cout << "unable to open the files.";
}

void Admin::removeLecturer(){
    // Open the input and output files
    std::ifstream inputFile("lecturers.csv");
    std::ofstream outputFile("temp.csv");
    int lineInput;
    cout << "Please enter the line you want to remove: ";
    cin >> lineInput;
    if (inputFile.is_open() && outputFile.is_open() && lineInput != 1){
        
        
        string line;
        int currentLineNumber = 1;
        

        

        while (getline(inputFile, line)) {
            if(currentLineNumber != lineInput) {
                outputFile << line << std::endl;
            }   
            currentLineNumber++;
        }

        // Close the input and output files
        inputFile.close();
        outputFile.close();

         // Remove the original file
        if (remove("lecturers.csv") != 0 ) {
            cerr << "Error deleting original file." << endl;
        }

        // Rename the temporary file to the original file name
        if (rename("temp.csv", "lecturers.csv") != 0) {
            cerr << "Error renaming file." << endl;
        }

    
        cout << "Line " << lineInput << " deleted successfully." <<endl;
    
    }
    else
        cout << "unable to open the files.";

}

void Admin:: removeCourse(){
    // Open the input and output files
    std::ifstream inputFile("courses.csv");
    std::ofstream outputFile("temp.csv");
    int lineInput;
    cout << "Please enter the line you want to remove: ";
    cin >> lineInput;
    if (inputFile.is_open() && outputFile.is_open() && lineInput != 1){
        
        
        string line;
        int currentLineNumber = 1;
        

        

        while (getline(inputFile, line)) {
            if(currentLineNumber != lineInput) {
                outputFile << line << std::endl;
            }   
            currentLineNumber++;
        }

        // Close the input and output files
        inputFile.close();
        outputFile.close();

         // Remove the original file
        if (remove("courses.csv") != 0 ) {
            cerr << "Error deleting original file." << endl;
        }

        // Rename the temporary file to the original file name
        if (rename("temp.csv", "courses.csv") != 0) {
            cerr << "Error renaming file." << endl;
        }

    
        cout << "Line " << lineInput << " deleted successfully." <<endl;
    
    }
    else
        cout << "unable to open the files.";
}


void Admin::readFile(string fileName){
    string line;
    string name = "Database/"+fileName+".csv";
    ifstream txtFile (name);
    if (txtFile.is_open())
    {
        while (getline(txtFile, line))
            cout << line << endl;
        txtFile.close();
    }
    else 
        cout << "Unable to open file " << name;
}


void Admin::getAllCourses(){
    readFile("courses");
}

void Admin::getAllLecturerCourse(){
    readFile("lecturerCourse");
}

void Admin::getAllLecturers(){
    readFile("lecturers");
}

void Admin::getAllStudents(){
    readFile("students");
}
void Admin::getAllStudentScoreBoards(){
    readFile("studentScoreboard");
}

void Admin::getAllStudentsCourse(){
    readFile("studentsCourse");
}

void Admin::getAllDatabase(){
    getAllCourses();
    getAllLecturers();
    getAllStudents();
    getAllLecturerCourse();
    getAllStudentScoreBoards();
    getAllStudentsCourse();  
}


void Admin::adminMenu(){
    cout <<  "------------------------------Admin Menu Page------------------------------" << endl;
    
    cout <<  "1-Add new student."<<endl;
    cout <<  "2-Add new lecturer."<<endl;
    cout <<  "3-Add new course."<<endl;

    cout <<  "4-Remove student."<<endl;
    cout <<  "5-Remove lecturer."<<endl;
    cout <<  "6-Remove course."<<endl;

    cout << "7-See spesific student's information."<<endl;
    cout << "8-See spesific lecturer's information."<<endl;


    cout <<  "9-Get all database information."<<endl;
    cout <<  "10-See all Courses. "<<endl;
    cout <<  "11-Get all lecturers. "<<endl;
    cout <<  "12-Get all students."<<endl;
    cout <<  "13-Get all students score boards."<<endl;
    cout <<  "14-Get all students course."<<endl;
    cout <<  "15-Get all lectures course."<<endl;
    cout << "16-Back.";

    cout <<  "------------------------------Admin Menu Page------------------------------" << endl;


    cout <<endl<< "Please Select Operation Number:"<<endl;

    int Operation;
    cin>>Operation;
    switch (Operation) {
        case 1:
        void addNewStudent();
        break;
        case 2:
        void addNewLectuer();
        break;
        case 3:
        void addNewCourses();
        break;
        case 4:
        void removeStudent();
        break;
        case 5:
        void removeLecturer();
        break;
        case 6:
        void removeCourse();
        break;
        case 7:
        void seeInfo();
        break;
        case 8:
        void seeInfo();
        break;
        case 9:
        void getAllDatabase();
        break;
        case 10:
        void getAllCourses();
        break;
        case 11:
        void getAllLecturers();
        break;
        case 12:
        void getAllStudents();
        break;
        case 13:
        void getAllStudentScoreBoards();
        break;
        case 14:
        void getAllStudentsCourse();
        break;
        case 15:
        void getAllLecturerCourse();
        break;
        case 16:
        void login();
        break;
        default :
        cout << "Wrong number! Please select again." << endl;
    }

}

