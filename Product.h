#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <vector>
#include <cstdio>

class Product
{
private:
    int product_number;
    std::string product_name;
    double price;
    int quantity;

public:
    Product() {
        product_number = 0;
        product_name = "";
        price = 0;
        quantity = 0;
    }
    Product(int number, std::string name, double prc, int qty) {
        product_number = number;
        product_name = name;
        price = prc;
        quantity = qty;
    }
    // Setter functions
    void setName(std::string name) { product_name = name; }
    void setNumber(int number) { product_number = number; }
    void setPrice(double price1) { price = price1; }
    void setQuantity(int qty) { quantity = qty; }

    // Getter functions
    std::string getName() const { return product_name; }
    int getNumber() const { return product_number; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    //save the attributes to a file
    void saveFile(const std::string& filename) const {
        std::ofstream saveFile(filename);
        saveFile << product_name << std::endl <<
            product_number << std::endl <<
            price << std::endl <<
            quantity << std::endl;
        saveFile.close();
    }

    //save the name of the txt in an another txt file called products
    void saveFileNames(const std::string& filename) const {
        std::ofstream saveFileNames("products.txt", std::ios::app);
        saveFileNames << filename << std::endl;
        saveFileNames.close();
    }

//    //load the content of the file into the attributes
//    void loadFile(const std::string& filename) {
//        std::ifstream loadFile(filename);
//        loadFile >> product_name >> product_number >> price >> quantity;
//        loadFile.close();
//    }
    
    //load the content of the file into the attributes
    void loadFile(const std::string& filename) {
        std::ifstream loadFile(filename);
        std::getline(loadFile, product_name);
        loadFile >> product_number >> price >> quantity;
        loadFile.close();
    }


    //delete the product file
    void deleteFile(const std::string& filename) {
        std::remove(filename.c_str());
    }

    //show the product info
    void showProduct(const std::string& filename) {
        loadFile(filename);
        std::cout << "Product Name: " << getName() << std::endl;
        std::cout << "Product Number: " << getNumber() << std::endl;
        std::cout << "Price: $" << getPrice() << std::endl;
        std::cout << "Quantity: " << getQuantity() << std::endl;
    }

    void deleteProductName(const std::string& filename) {
        // Open the original file in input mode
        std::ifstream inputFile("products.txt");

        // Open a temporary file in output mode
        std::ofstream tempFile("temp.txt");

        // Read each line from the original file
        std::string line;
        while (std::getline(inputFile, line)) {
            // If the line we want to delete is found, skip it
            if (line == filename) {
                continue;
            }

            // Write the line to the temporary file
            tempFile << line << std::endl;
        }

        // Close both files
        inputFile.close();
        tempFile.close();

        // Delete the original file
        std::remove("products.txt");

        // Rename the temporary file to the original file name
        std::rename("temp.txt", "products.txt");
    }
};
