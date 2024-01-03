#pragma once
#include <string>

class PhoneNumber
{
private:
    std::string  phone;
public:
    void setPhone(std::string);
    void editPhone(std::string);
    std::string getPhone();
};

void PhoneNumber::setPhone(std::string phone_num)
{
    phone = phone_num;
}

void PhoneNumber::editPhone(std::string phone_num2) {

    phone = phone_num2;
}

std::string PhoneNumber::getPhone()
{
    return phone;
}


