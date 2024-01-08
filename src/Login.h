
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "Admin.h"
#include "Lecturer.h"
#include "TeachingAssistant.h"

using namespace::std;
bool authorizeStudent(string ,string);
bool authorizeLecturers(string,string);
bool authorizedAdmin(string, string);
void login();

void login(){
    cout <<  "------------------------------School Login Page------------------------------" << endl;
    
    int choice;
    cout << "1. Login\n";
    cout << "2. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    string username;
    string password;
    if (choice== 1 ){
        cout << "Enter username: ";
        cin>> username;
        cout<<endl;
        cin.ignore();
        cout << "Enter password: ";
        cin>> password;
        cin.ignore();
        cout<<endl;
        if (authorizeStudent(username,password)== true)
        {
            cout <<"login succesfull";
            Student student;
            student.StudentMenu();
        }
        else if (authorizeLecturers(username,password)==true)
        {
            cout <<"login succesfull";
            Lecturer lecturer;
            lecturer.LecturerMenu();

        }
        else if(authorizedAdmin(username, password)==true)
        {
            cout <<"login succesfull";
            Admin admin;
            admin.adminMenu();

        }
        else
            cout<< "wrong username or password";
    }
    else if (choice == 2 )
    {
        cout <<"exit succesfull";
    }
}


bool authorizeStudent(string u,string p)
{
    string line, name = "studentscopy.csv";
    ifstream txtFile (name);
    size_t pos;
    if (txtFile.is_open())
    {
        while (getline(txtFile, line))
        {
            pos = line.find(u);
            if ((pos = line.find(u)) != string::npos)
            {
                cout << "username has found"<<endl;
                pos = line.find(p);
                if ((pos = line.find(p)) != string::npos)
                {
                    cout << "password has found"<<endl;
                    cout << "welcome"<< u<< endl;
                    return true;
                    break;
                }  
            }
        }
        
    }
    else{
        cout << "Unable to open file " << name;
        return false;
    }
    return true;
}

bool authorizeProfessors(string u,string p)
{
    string line, name = "Database/lecturers.csv";
    ifstream txtFile (name);
    size_t pos;
    if (txtFile.is_open())
    {
        while (getline(txtFile, line))
        {
            pos = line.find(u);
            if ((pos = line.find(u)) != string::npos)
            {
                cout << "username has found"<<endl;
                pos = line.find(p);
                if ((pos = line.find(p)) != string::npos)
                {
                    cout << "password has found"<<endl;
                    cout << "welcome"<< u<< endl;
                    return true;
                    break;
                }
                
            }
        }
    }
    else{
        cout << "Unable to open file " << name;
        return false;
    }
    return true;    
}

