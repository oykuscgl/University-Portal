#include <iostream>
#include <string>

using namespace std;

class User
{
    private:
    string userName;
    string password;


    public:
    string getUserName()
    {
        return userName;
    }
    void setUserName(string usern)
    {
        userName = usern;
    
    }

    string getPassword()
    {
        return password;
    }
    void setPassword(string passw)
    {
        password = passw;
    }
    

};

