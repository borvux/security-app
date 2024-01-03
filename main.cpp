#include <iostream>
#include <iomanip>
#include <fstream>
#include "Functions.h"
#include "Product.h"
#include "LogIn.h"

#define space cout << "------------------------------------------------------" << endl;
using namespace std;

//global variables
//product temp attributes to show products
string productName;
int productNumber;
double price;
int quantity;

//initialize empty product
Product product;
//create login object
LogIn login;

//empty vector
vector<string> productNames;
vector<string> customerNames;

void welcome_menu() { //display welcome menu
    cout << "Would you like to: " << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
}
void customer_options() {
    cout << "Welcome!" << endl;
    cout << "What would you like to do today?" << endl;
    cout << "1. View Catalog" << endl;
    cout << "2. Edit Phone Number" << endl;
    cout << "3. Edit Address" << endl;
    cout << "4. Make an Order" << endl;
    cout << "5. Log Out" << endl;
    cout << "Enter choice number: ";
}

void salesPerson_options() {
    cout << "Welcome!" << endl <<
            "What would you like to do today?" << endl <<
            "1. View Catalog" << endl <<
            "2. Edit Customer Phone Number" << endl <<
            "3. Edit Customer Address" << endl <<
            "4. Make an Order For Customer" << endl <<
            "5. Log Out" << endl <<
            "Enter choice number: ";
}

void manager_options() {
    cout << "Welcome!" << endl <<
            "What would you like to do today?" << endl <<
            "1. View Catalog" << endl <<
            "2. Make an Order For Customer" << endl <<
            "3. Edit Customer Phone Number" << endl <<
            "4. Edit Customer Address" << endl <<
            "5. Edit Catalog" << endl <<
            "6. Log Out" << endl <<
            "Enter choice number: ";
}

void viewProduct() {
    //put the content into the vector
    string lines; //temp string

    ifstream productNamesFile("products.txt");

    //while reading the lines
    while (getline(productNamesFile, lines)) {
        //push the names of the txt file into vector
        productNames.push_back(lines);
    }
    productNamesFile.close();

    for (const string& filename : productNames) {
        product.loadFile(filename + ".txt");

        //printing out the data from each files
        product.showProduct(filename + ".txt");
        cout << endl;
    }
}

void getCustomersInfo(string customerUsername) {
    ifstream customerFile(customerUsername + ".txt");
    login.loadCustomerFiles(customerUsername + ".txt");
}

void viewAllCustomers() {
    //put the content into the vector
    string lines; //temp string

    ifstream customerNamesFile("customers.txt");

    //while reading the lines
    while (getline(customerNamesFile, lines)) {
        //push the names of the txt file into vector
        customerNames.push_back(lines);
    }
    customerNamesFile.close();

    for (const string& filename : customerNames) {
        string file = filename;
        login.loadCustomerFiles(file + ".txt");

        //printing out the data from each files
        login.showCustomers(file + ".txt");
        cout << endl;
    }
}

int main()
{
    bool menuCustomer = true;
    int user = 0;

    cout << "Welcome to Surveillance Industries!" << endl;
    cout << "\nAre you a customer or an employee?" << endl;
    cout << "1.Customer" << endl;
    cout << "2.Employee" << endl;

    cout << "Enter option: ";

    user = intChecker(user); //save choice customer or employee

    while (user < 1 or user > 2) {
        cout << "You entered an incorrect input value!" << endl <<
                "Reenter option: ";
        user = intChecker(user);
    }

    if (user == 1) { //if customer
        space;
        welcome_menu();//call display welcome menu
        int choice = 0;
        cout << "Enter your choice: ";
        choice = intChecker(choice);//save choice register or login

        //check for valid user input
        while (choice < 1 or choice > 2) {
            cout << "You entered an incorrect input value!" << endl << 
                    "Reenter option: ";
            space;
            welcome_menu();
            choice = intChecker(choice);
        }

        space;

        if (choice == 1) {
            login.Register();
        }
        else if (choice == 2) {
            login.LoggingIn();
        }
        
        while (menuCustomer) {
            space;
            //customer options menu
            customer_options();

            int customerChoice = 0;
            customerChoice = intChecker(customerChoice);

            while (customerChoice < 1 or customerChoice > 5) {
                cout << "You entered an incorrect input value!" << endl <<
                    "Reenter option: ";
                customer_options();
                cin >> customerChoice;
            }

            if (customerChoice == 1) {//view catalog
                space;
                viewProduct();
            }
            else if (customerChoice == 2) {//change phone number
                space;
                string tempuser;
                string username;
                string number;
                cout << "Enter you username for verification: ";
                cin >> tempuser;
                getCustomersInfo(tempuser);
                username = login.getUsername();
                cout << "Your current phone number: " + login.getPhone() << endl;
                login.loadCustomerFiles(username + ".txt");
                cout << "Enter the new phone number: ";
                cin >> number;
                login.setPhone(number);
                login.saveFile(username);
                cout << "Your new phone number is " + login.getPhone() << endl;

            }
            else if (customerChoice == 3) {//change address
                space;
                string tempuser;
                string username;
                string streetNumber;
                string street;
                string city;
                string state;
                string zip;
                cout << "Enter you username for verification: ";
                cin >> tempuser;
                getCustomersInfo(tempuser);
                username = login.getUsername();
                cout << "Your current address: " << login.getStreetNum() << " " << login.getStreet() << ", " << login.getCity() << ", " << login.getState() << ", " << login.getZip();
                login.loadCustomerFiles(username + ".txt");
                cout << "Enter the new address number: ";
                cin >> streetNumber;
                login.setStreetNum(streetNumber);
                cout << "Enter the new street ";
                cin >> street;
                login.setStreet(streetNumber);
                cout << "Enter the new city: ";
                cin >> city;
                login.setCity(city);
                cout << "Enter the new state: ";
                cin >> state;
                login.setState(state);
                cout << "Enter the new zipcode: ";
                cin >> zip;
                login.setZip(zip);

                login.saveFile(username);

                cout << "Your new address: " << login.getStreetNum() << " " << login.getStreet() << ", " << login.getCity() << ", " << login.getState() << ", " << login.getZip();
            }
            else if (customerChoice == 4) {//make order
                cout << "To make an order with one of our agents, please call this number:" << endl;
                cout << "(787)600-6850" << endl;
                cout << "We appreciate your interest in Surveillence Industries!" << endl;
                //insert sales person number

                space;
            }
            else if (customerChoice == 5) {
                menuCustomer = false;
                cout << "You have been logged out." << endl;
                exit(0);
            }
        }
    }

    if (user == 2) {

        space;
        string username = login.LoggingInEmp();

        bool menuManager = true;

        if (username == "mikel") {

            

            cout << "You have logged in as Manager" << endl;
            //call manager class
            while (menuManager) {
                space;
                manager_options();
                int managerChoice = 0;
                managerChoice = intChecker(managerChoice);

                while (managerChoice < 1 or managerChoice >6) {
                    cout << "You entered an incorrect input value!" << endl <<
                        "Reenter option: ";
                    space;
                    manager_options();
                    managerChoice = intChecker(managerChoice);
                }


                if (managerChoice == 1) { //view catalog
                    space;
                    viewProduct();
                }
                else if (managerChoice == 2) { //make order
                    space;
                    viewAllCustomers();

                    cout << "Enter the name of the cutomer that wants to order: ";
                    string name;
                    cin >> name;

                    space;
                    viewProduct();

                    cout << "Enter the product the customer wants to order: ";
                    string product;
                    cin >> product;

                    cout << "Would you like to place the order?" << endl;
                    cout << "1. Yes" << endl;
                    cout << "2. No" << endl;
                    cout << "Enter option: ";
                    int place = 0;
                    place = intChecker(place);
                    if (place == 1) {
                        cout << "Your order has been placed." << endl;
                        int orderNumber = orderID();
                        cout << "The order number is " << orderNumber;

                    }
                    else if (place == 2) {
                        cout << "Your order has been saved." << endl;
                    }


                }
                else if (managerChoice == 3) { //edit customer phone
                    space;
                    string tempuser;
                    string username;
                    string number;
                    viewAllCustomers();
                    cout << "Enter the customer username for verification: ";
                    cin >> tempuser;
                    getCustomersInfo(tempuser);
                    username = login.getUsername();
                    cout << "The customer current phone number: " + login.getPhone() << endl;
                    login.loadCustomerFiles(username + ".txt");
                    cout << "Enter the new phone number: ";
                    cin >> number;
                    login.setPhone(number);
                    login.saveFile(username);
                    cout << "The customer new phone number is " + login.getPhone() << endl;
                }
                else if (managerChoice == 4) { //edit customer address
                    space;
                    string tempuser;
                    string username;
                    string streetNumber;
                    string street;
                    string city;
                    string state;
                    string zip;
                    viewAllCustomers();
                    cout << "Enter the customer username for verification: ";
                    cin >> tempuser;
                    getCustomersInfo(tempuser);
                    username = login.getUsername();
                    cout << "The customer current address: " << login.getStreetNum() << " " << login.getStreet() << ", " << login.getCity() << ", " << login.getState() << ", " << login.getZip();
                    login.loadCustomerFiles(username + ".txt");
                    cout << "Enter the new address number: ";
                    cin >> streetNumber;
                    login.setStreetNum(streetNumber);
                    cout << "Enter the new street ";
                    cin >> street;
                    login.setStreet(streetNumber);
                    cout << "Enter the new city: ";
                    cin >> city;
                    login.setCity(city);
                    cout << "Enter the new state: ";
                    cin >> state;
                    login.setState(state);
                    cout << "Enter the new zipcode: ";
                    cin >> zip;
                    login.setZip(zip);

                    login.saveFile(username);

                    cout << "The customer new address: " << login.getStreetNum() << " " << login.getStreet() << ", " << login.getCity() << ", " << login.getState() << ", " << login.getZip();
                }
                else if (managerChoice == 5) { //edit catalog
                    space;
                    int option = 0;
                    cout << "What would you like to do?" << endl <<
                        "1) Enter a product" << endl <<
                        "2) Update a prodcut" << endl <<
                        "3) Delete a product" << endl <<
                        "4) Exit" << endl <<
                        "Enter your option (1-4): ";

                    option = intChecker(option);

                    cout << endl;

                    switch (option) {
                    case 1:
                        space;
                        cout << "\nEnter the product name: ";
                        cin >> productName;
                        product.setName(productName);

                        cout << "\nEnter the product number: ";
                        cin >> productNumber;
                        product.setNumber(productNumber);

                        cout << "\nEnter the product price: ";
                        cin >> price;
                        product.setPrice(price);

                        cout << "\nEnter the quantity: ";
                        cin >> quantity;
                        product.setQuantity(quantity);

                        product.saveFile(productName + ".txt");
                        product.saveFileNames(productName);

                        cout << "\nYou have created a new product called: " + productName;
                        break;

                    case 2:
                        space;
                        cout << "\nEnter the name of the product you want to edit: ";
                        cin >> productName;
                        product.loadFile(productName + ".txt");

                        cout << "\nEnter the new product number: ";
                        cin >> productNumber;
                        product.setNumber(productNumber);

                        cout << "\nEnter the new price: ";
                        cin >> price;
                        product.setPrice(price);

                        cout << "\nEnter the new quantity: ";
                        cin >> quantity;
                        product.setQuantity(quantity);

                        product.saveFile(productName + ".txt");

                        cout << "\nYou have updated the product: " + productName;
                        break;

                    case 3:
                        space;
                        cout << "\nEnter the name of the product you want to delete: ";
                        cin >> productName;

                        product.deleteFile(productName + ".txt");

                        /*
                        while (getline(productNamesFile, lines)) {
                            // Remove the word from the line
                            lines.erase(remove(lines.begin(), lines.end(), productName), lines.end());
                        }
                        */
                        product.deleteProductName(productName);

                        cout << "\nYou have deleted a product: " + productName;
                        break;

                    default:
                        cout << endl;
                    }
                }
                else if (managerChoice == 6) { //exit
                    space;
                    menuManager = false;
                    cout << "You have been logged out." << endl;
                    exit(0);
                }
            }
            

        }
        else if (username == "abril" || username == "benny" || username == "guille") {
            space;

            bool menuSales = true;
            //call sales person class
            cout << "You have logged in as Sales Person" << endl;
            while (menuSales) {
                space;
                salesPerson_options();
                int SPchoice = 0;
                SPchoice = intChecker(SPchoice);

                while (SPchoice < 1 or SPchoice > 5) {
                    cout << "You entered an incorrect input value!" << endl <<
                        "Reenter option: ";
                    salesPerson_options();
                    cin >> SPchoice;
                }

                if (SPchoice == 1) {//view catalog
                    space;
                    viewProduct();
                }
                else if (SPchoice == 2) {//change customer's phone number
                    space;
                    string tempuser;
                    string username;
                    string number;
                    viewAllCustomers();
                    cout << "Enter the customer username for verification: ";
                    cin >> tempuser;
                    getCustomersInfo(tempuser);
                    username = login.getUsername();
                    cout << "The customer current phone number: " + login.getPhone() << endl;
                    login.loadCustomerFiles(username + ".txt");
                    cout << "Enter the new phone number: ";
                    cin >> number;
                    login.setPhone(number);
                    login.saveFile(username);
                    cout << "The customer new phone number is " + login.getPhone() << endl;
                }
                else if (SPchoice == 3) {//change customer's address
                    space;
                    string tempuser;
                    string username;
                    string streetNumber;
                    string street;
                    string city;
                    string state;
                    string zip;
                    viewAllCustomers();
                    cout << "Enter the customer username for verification: ";
                    cin >> tempuser;
                    getCustomersInfo(tempuser);
                    username = login.getUsername();
                    cout << "The customer current address: " << login.getStreetNum() << " " << login.getStreet() << ", " << login.getCity() << ", " << login.getState() << ", " << login.getZip();
                    login.loadCustomerFiles(username + ".txt");
                    cout << "Enter the new address number: ";
                    cin >> streetNumber;
                    login.setStreetNum(streetNumber);
                    cout << "Enter the new street ";
                    cin >> street;
                    login.setStreet(streetNumber);
                    cout << "Enter the new city: ";
                    cin >> city;
                    login.setCity(city);
                    cout << "Enter the new state: ";
                    cin >> state;
                    login.setState(state);
                    cout << "Enter the new zipcode: ";
                    cin >> zip;
                    login.setZip(zip);

                    login.saveFile(username);

                    cout << "The customer new address: " << login.getStreetNum() << " " << login.getStreet() << ", " << login.getCity() << ", " << login.getState() << ", " << login.getZip();
                }
                else if (SPchoice == 4) {//make order for customer
                    space;
                    viewAllCustomers();

                    cout << "Enter the name of the cutomer that wants to order: ";
                    string name;
                    cin >> name;

                    space;
                    viewProduct();

                    cout << "Enter the product the customer wants to order: ";
                    string product;
                    cin >> product;

                    cout << "Would you like to place the order?" << endl;
                    cout << "1. Yes" << endl;
                    cout << "2. No" << endl;
                    cout << "Enter option: ";
                    int place = 0;
                    place = intChecker(place);
                    if (place == 1) {
                        cout << "Your order has been placed." << endl;
                        int orderNumber = orderID();
                        cout << "The order number is " << orderNumber;

                    }
                    else if (place == 2) {
                        cout << "Your order has been saved." << endl;
                    }

                }
                else if (SPchoice == 5) { //log out
                    space;
                    menuSales = false;
                    cout << "You have been logged out." << endl;
                    exit(0);
                }
            }
        }
    }
}
