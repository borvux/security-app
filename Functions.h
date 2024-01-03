#pragma once
#include <iostream>
#include <functional>
#include <string>

//to create a unique order ID 
//to create a unique order ID
std::size_t orderID()
{
    //gernerate a random number
    int orderNumber = rand();

    //convert the number to a string
    std::string randomOrderString = std::to_string(orderNumber);

    //generate a unique order ID using the random number
    std::size_t orderID = std::hash<std::string>{}(randomOrderString);

    //return the random ID
    return orderID;
}


//to create a unique 5 digits random ID
std::size_t accountID()
{
    //gernerate a random number
    int randomNumber = rand();

    //convert the number to a string
    std::string randomNumberString = std::to_string(randomNumber);

    //generate a unique 5 digits ID using the random number
    std::size_t accountID = std::hash<std::string>{}(randomNumberString);

    //return the random ID
    return accountID;
}


//integar validation 
int intChecker(int input)
{
	std::cin >> input;

	//while its not a number
	while (std::cin.fail())
	{
		std::cout << "Error! Enter a number!" << std::endl;
		//clear the input and ignore new line
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Reenter: ";
		std::cin >> input;
	}
	return input;
}

//double validation 
double doubleChecker(double input)
{
	std::cin >> input;

	//while its not a double
	while (std::cin.fail())
	{
		std::cout << "Error! Enter a number!" << std::endl;
		//clear the input and ignore new line
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Reenter: ";
		std::cin >> input;
	}
	return input;
}

//string validation
std::string stringChecker(std::string input)
{
	std::getline(std::cin, input);

	//while its not a string
	while (std::cin.fail())
	{
		std::cout << "Error! Enter an alphabet!" << std::endl;
		//clear remainding characters from input and new line
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Reenter: ";
		std::getline(std::cin, input);
	}
	return input;
}
