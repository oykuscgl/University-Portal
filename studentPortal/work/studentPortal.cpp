#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include "Lecturer.h"
#include "Student.h"
#include "TeachingAssistant.h"


int main()
{
    
    string line, name = "lecturer.csv";
    fstream file (name);
    while(getline(file, line))
    {
        cout << line << " \n";
    }

}




