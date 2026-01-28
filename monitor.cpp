#include "monitor.h"
#include <iostream>
#include <iomanip>
using namespace std;

Monitor::Monitor(const string& manufacturer, int year, double price, int stockQuantity,
                 double screenSize, const string& resolution, bool isCurved)
    : Peripheral(manufacturer, year, price, stockQuantity),
      screenSize(screenSize), resolution(resolution), isCurved(isCurved) {}

double Monitor::calculateTotalValue() const {
    double baseValue = Peripheral::calculateTotalValue();
    double multiplier = isCurved ? 1.5 : 1.0;
    multiplier *= (screenSize > 27.0 ? 1.2 : 1.0);
    return baseValue * multiplier;
}

string Monitor::getDeviceType() const {
    return "Монитор";
}

double Monitor::getScreenSize() const {
    return screenSize;
}

string Monitor::getResolution() const {
    return resolution;
}

bool Monitor::getIsCurved() const {
    return isCurved;
}

void Monitor::setScreenSize(double size) {
    screenSize = size;
}

void Monitor::setResolution(const string& resolution) {
    this->resolution = resolution;
}

void Monitor::setIsCurved(bool curved) {
    isCurved = curved;
}

void Monitor::calibrate() {
    if (stockQuantity > 0) {
        cout << "Монитор " << manufacturer << " калибруется..." << endl;
        cout << "Размер: " << screenSize << "\", Разрешение: " << resolution
             << ", Изогнутый: " << (isCurved ? "Да" : "Нет") << endl;
    } else {
        cout << "Нет мониторов на складе для калибровки!" << endl;
    }
}

void Monitor::upgradeResolution(const string& newResolution) {
    if (newResolution != resolution) {
        string oldResolution = resolution;
        resolution = newResolution;
        price *= 1.15;
        cout << "Монитор " << manufacturer << " обновлен с " 
             << oldResolution << " до " << newResolution << endl;
        cout << "Новая цена: $" << fixed << setprecision(2) << price << endl;
    } else {
        cout << "Монитор уже имеет это разрешение!" << endl;
    }
}

void Monitor::displayMonitorInfo() const {
    displayInfo();
    cout << ", Тип: " << getDeviceType()
         << ", Размер экрана: " << screenSize << "\""
         << ", Разрешение: " << resolution
         << ", Изогнутый: " << (isCurved ? "Да" : "Нет")
         << ", Общая стоимость: $" << fixed << setprecision(2) 
         << calculateTotalValue() << endl;
}