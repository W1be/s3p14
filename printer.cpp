#include "printer.h"
#include <iostream>
#include <iomanip>
using namespace std;

Printer::Printer(const string& manufacturer, int year, double price, int stockQuantity,
                 const string& technology, bool isColor, int pagesPerMinute)
    : Peripheral(manufacturer, year, price, stockQuantity),
      technology(technology), isColor(isColor), pagesPerMinute(pagesPerMinute) {}

double Printer::calculateTotalValue() const {
    double baseValue = Peripheral::calculateTotalValue();
    double multiplier = isColor ? 1.3 : 1.0;
    return baseValue * multiplier;
}

string Printer::getDeviceType() const {
    return "Принтер";
}

string Printer::getTechnology() const {
    return technology;
}

bool Printer::getIsColor() const {
    return isColor;
}

int Printer::getPagesPerMinute() const {
    return pagesPerMinute;
}

void Printer::setTechnology(const string& technology) {
    this->technology = technology;
}

void Printer::setIsColor(bool isColor) {
    this->isColor = isColor;
}

void Printer::setPagesPerMinute(int ppm) {
    pagesPerMinute = ppm;
}

void Printer::printTestPage() {
    if (stockQuantity > 0) {
        cout << "Принтер " << manufacturer << " печатает тестовую страницу..." << endl;
        cout << "Технология: " << technology 
             << ", Цветной: " << (isColor ? "Да" : "Нет")
             << ", Скорость: " << pagesPerMinute << " стр/мин" << endl;
    } else {
        cout << "Нет принтеров на складе для тестирования!" << endl;
    }
}

void Printer::upgradeToColor() {
    if (!isColor) {
        isColor = true;
        price *= 1.25;
        cout << "Принтер " << manufacturer << " модернизирован до цветного." << endl;
        cout << "Новая цена: $" << fixed << setprecision(2) << price << endl;
    } else {
        cout << "Принтер уже цветной!" << endl;
    }
}

void Printer::displayPrinterInfo() const {
    displayInfo();
    cout << ", Тип: " << getDeviceType()
         << ", Технология: " << technology
         << ", Цветной: " << (isColor ? "Да" : "Нет")
         << ", Скорость печати: " << pagesPerMinute << " стр/мин"
         << ", Общая стоимость: $" << fixed << setprecision(2) 
         << calculateTotalValue() << endl;
}