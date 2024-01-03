#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "PhoneNumber.h"
#include <vector>


class LogIn {
private:
    std::string username, password, firstName, lastName;
    std::string streetNum, street, city, state, zip;
    std::string phoneNumber;

    PhoneNumber phone;

    std::string user;
    std::string pass;

    std::string tempuser;
    std::string temppass;

public:
    bool LoggingIn();
    std::string LoggingInEmp();
    int Register();
    int Login();

    void setUsername(std::string);
    void setPassword(std::string);
    void setFirstName(std::string);
    void setLastName(std::string);
    void setStreetNum(std::string);
    void setStreet(std::string);
    void setCity(std::string);
    void setState(std::string);
    void setZip(std::string);
    void setPhone(std::string);

    std::string getUsername();
    std::string getFirstName();
    std::string getLastName();
    std::string getStreetNum();
    std::string getStreet();
    std::string getCity();
    std::string getState();
    std::string getZip();
    std::string getPhone();

    void saveCustomerNames(std::string); 
    void loadCustomerFiles(std::string);
    void saveFile(const std::string& filename);
    void showCustomers(std::string);
};

bool LogIn::LoggingIn() {

    //when account already exists
    std::cout << "Enter username: ";
    std::cin >> user;
    std::cout << "Enter password: ";
    std::cin >> pass;

    std::ifstream read(user + ".txt");
    std::getline(read, tempuser);
    std::getline(read, temppass);

    while (user != tempuser || pass != temppass) {
        std::cout << "Incorrect username or password. Try Again." << std::endl;
        LoggingIn();
        return false;
    }

    if (user == tempuser && pass == temppass) {
        //  Login();
        std::cout << "\nLogin successful!" << std::endl;

        return true;
    }
}

std::string LogIn::LoggingInEmp() {

    //when account already exists
    std::cout << "Enter username: ";
    std::cin >> user;
    std::cout << "Enter password: ";
    std::cin >> pass;

    std::ifstream read(user + ".txt");
    std::getline(read, tempuser);
    std::getline(read, temppass);

    while (user != tempuser || pass != temppass) {
        std::cout << "Incorrect username or password. Try Again." << std::endl;
        LoggingInEmp();
    }

    if (user == tempuser && pass == temppass) {
        //  Login();
        std::cout << "\nLogin successful!" << std::endl;

        return user;
    }
}

int LogIn::Register() {

    std::cout << "Please fill out the information below." << std::endl;
    std::cout << "Create a username: ";
    std::cin >> this->username;

    std::cout << "\nCreate a password: ";
    std::cin >> this->password;

    std::cin.ignore();
    std::cout << "\nEnter your first name: ";
    std::getline(std::cin, this->firstName);

    std::cout << "\nEnter your last name: ";
    std::getline(std::cin, this->lastName);

    std::cout << "\nEnter your address number: ";
    std::getline(std::cin, this->streetNum);

    std::cout << "\nEnter your street address: ";
    std::getline(std::cin, this->street);
    //acc.setStreetAddress(this->street);

    std::cout << "\nEnter your city: ";
    std::getline(std::cin, this->city);
    //acc.setCity(this->city);

    std::cout << "\nEnter your state: ";
    std::getline(std::cin, this->state);
    //acc.setState(this->state);

    std::cout << "\nEnter your zipcode: ";
    std::getline(std::cin, this->zip);
    //acc.setZipCode(this->zip);

    std::cout << "\nEnter your phone number: ";
    std::cin >> this->phoneNumber;
    //phone.setPhone(this->phoneNumber);

    std::ofstream file;
    file.open(username + ".txt");
    file << username << std::endl << password << std::endl << firstName << std::endl << lastName << std::endl << streetNum << std::endl << street << std::endl << city << std::endl
        << state << std::endl << zip << std::endl << phoneNumber << std::endl;

    file.close();

    saveCustomerNames(username);

    std::cout << "Account created successfully" << std::endl;
    LoggingIn();

    return 0;
}

//setters and getters defination, using inline for memory usage
inline void LogIn::setUsername(std::string username) {
    this->username = username;
}
inline void LogIn::setPassword(std::string password) {
    this->password = password;
}
inline void LogIn::setFirstName(std::string firstName) {
    this->firstName = firstName;
}
inline void LogIn::setLastName(std::string lastName) {
    this->lastName = lastName;
}
inline void LogIn::setStreetNum(std::string streetnum)
{
    this->streetNum = streetnum;
}
inline void LogIn::setStreet(std::string street) {
    this->street = street;
}
inline void LogIn::setCity(std::string city) {
    this->city = city;
}
inline void LogIn::setState(std::string state) {
    this->state = state;
}
inline void LogIn::setZip(std::string zip) {
    this->zip = zip;
}
inline void LogIn::setPhone(std::string phone) {
    this->phoneNumber = phone;
}

//getters
std::string LogIn::getUsername() {
    return username;
}
std::string LogIn::getFirstName() {
    return firstName;
}
std::string LogIn::getLastName() {
    return lastName;
}

std::string LogIn::getStreetNum()
{
    return streetNum;
}

std::string LogIn::getStreet() {
    return street;
}
std::string LogIn::getCity() {
    return city;
}
std::string LogIn::getState() {
    return state;
}
std::string LogIn::getZip() {
    return zip;
}
std::string LogIn::getPhone() {
    return phoneNumber;
}

inline void LogIn::saveCustomerNames(std::string filename)
{
    std::ofstream saveFileNames("customers.txt", std::ios::app);
    saveFileNames << filename << std::endl;
    saveFileNames.close();
}

void LogIn::loadCustomerFiles(std::string filename)
{

    std::ifstream loadFile(filename);
    loadFile >> username >> password >> firstName >> lastName >> streetNum >> street >> city >> state >> zip >> phoneNumber;
    loadFile.close();


}

void LogIn::saveFile(const std::string& filename) {
    std::ofstream file;
    file.open(filename + ".txt");
    file << username << std::endl << password << std::endl << firstName << std::endl << lastName << std::endl << streetNum << std::endl << street << std::endl << city << std::endl
        << state << std::endl << zip << std::endl << phoneNumber << std::endl;
}



void LogIn::showCustomers(std::string filename)
{
    loadCustomerFiles(filename);
    std::cout << "Customer Name: " << getFirstName() << " " << getLastName() << std::endl <<
                 "Customer Address: " << getStreetNum() << " " << getStreet() << ", " << getState() << ", " << getCity() << ", " << getState() << ", " << getZip() << std::endl <<
                 "Customer Phone: " << getPhone();
}
