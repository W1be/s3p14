#ifndef PERIPHERAL_H
#define PERIPHERAL_H

#include <string>
using namespace std;

class Peripheral {
protected:
    string manufacturer;
    int year;
    double price;
    int stockQuantity;

public:
    Peripheral(const string& manufacturer, int year, double price, int stockQuantity);
    virtual ~Peripheral() = default;

    string getManufacturer() const;
    int getYear() const;
    double getPrice() const;
    int getStockQuantity() const;

    void setManufacturer(const string& manufacturer);
    void setYear(int year);
    void setPrice(double price);
    void setStockQuantity(int quantity);

    void displayInfo() const;
    virtual double calculateTotalValue() const;
    virtual string getDeviceType() const = 0;
    
    void restock(int amount);
};

#endif