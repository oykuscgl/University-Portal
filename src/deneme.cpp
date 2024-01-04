#include "Lecturer.h"
#include "User.h"
#include <iostream>
using namespace std;

int main()
{
    Lecturer lecturer1;
    lecturer1.setName("deneme");
    lecturer1.setPhone(2341234564);
    lecturer1.setEmail("denemeee");
    lecturer1.setName("dene");
    lecturer1.setPassword("ad");
    lecturer1.setUserName("sa");
    lecturer1.setBirthYear(2002);
    lecturer1.setGender('F');
    lecturer1.setNumOfCourses(4);
    lecturer1.setMyCourses(0, "cmpe");

    lecturer1.saveToFile("lecturers.csv");
    lecturer1.LecturerMenu();

}