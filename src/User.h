#ifndef User_H
#define User_H
#include <iostream>
#include <string>

using namespace std;

#include <string>
#include <iostream>
using namespace std;


class User {
protected:
    string userName;
    string password;
    
public:
    
    User(){
        
        userName = "";
        password = "";
    }
    
    User(User&);
    ~User();
   
    string getUsername(){
        return this->userName;
    }
    void setUsername(string userName){
        this -> userName = userName;
    }

    string getPassword(){
        return this->password;
    }
    void setPassword(string password){
        this -> password = password;
    }
    
};



#endif
