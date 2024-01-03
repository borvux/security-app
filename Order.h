#pragma once
#include <string>

#include <iostream>
#include "Product.h"
#include "Functions.h"
using namespace std;

class Order
{

private:

    std::string orderAccount;
    std::string order;
    int orderNumber;

public:
    Order() {}
    Order(std::string);
    void setOrderAccount(std::string);
    void setOrderNumber();

    std::string getOrder();
    std::string getOrderAccount();
    int getOrderNumber();
};

Order::Order(std::string order1) {
    order = order1;
}

std::string Order::getOrder() {
    return order;
}

void Order::setOrderAccount(std::string orderAcc) {
    orderAccount = orderAcc;
}

std::string Order::getOrderAccount()
{
    return orderAccount;
}

void Order::setOrderNumber()
{
    //create ordern number: ORDER00000
    orderNumber = orderID();
}


int Order::getOrderNumber()
{
    return orderNumber;
}
