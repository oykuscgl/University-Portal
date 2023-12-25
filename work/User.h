class User {
protected:
    string userName;
    string password;
    string schoolMail;
    string phoneNum;
    string dateOfBirth;
    

public:
    User(string name,string pswrd){
    this-> userName = name;
    this->password = pswrd;
    };
    ~User();
    void login();
    void logout();
    
};
