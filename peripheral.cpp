#include "peripheral.h"
#include <iostream>
#include <iomanip>
using namespace std;

Peripheral::Peripheral(const string& manufacturer, int year, double price, int stockQuantity)
    : manufacturer(manufacturer), year(year), price(price), stockQuantity(stockQuantity) {}

string Peripheral::getManufacturer() const {
    return manufacturer;
}

int Peripheral::getYear() const {
    return year;
}

double Peripheral::getPrice() const {
    return price;
}

int Peripheral::getStockQuantity() const {
    return stockQuantity;
}

void Peripheral::setManufacturer(const string& manufacturer) {
    this->manufacturer = manufacturer;
}

void Peripheral::setYear(int year) {
    this->year = year;
}

void Peripheral::setPrice(double price) {
    this->price = price;
}

void Peripheral::setStockQuantity(int quantity) {
    stockQuantity = quantity;
}

void Peripheral::displayInfo() const {
    cout << "Производитель: " << manufacturer 
         << ", Год выпуска: " << year 
         << ", Цена: $" << fixed << setprecision(2) << price
         << ", На складе: " << stockQuantity << " шт.";
}

double Peripheral::calculateTotalValue() const {
    return price * stockQuantity;
}

void Peripheral::restock(int amount) {
    if (amount > 0) {
        stockQuantity += amount;
        cout << "Запасы пополнены на " << amount << " единиц. Теперь на складе: " 
             << stockQuantity << " шт." << endl;
    }
}