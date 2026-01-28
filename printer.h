#ifndef PRINTER_H
#define PRINTER_H

#include "peripheral.h"

class Printer : public Peripheral {
private:
    string technology;
    bool isColor;
    int pagesPerMinute;

public:
    Printer(const string& manufacturer, int year, double price, int stockQuantity,
            const string& technology, bool isColor, int pagesPerMinute);
    
    double calculateTotalValue() const override;
    string getDeviceType() const override;
    
    string getTechnology() const;
    bool getIsColor() const;
    int getPagesPerMinute() const;
    void setTechnology(const string& technology);
    void setIsColor(bool isColor);
    void setPagesPerMinute(int ppm);
    void printTestPage();
    void upgradeToColor();
    void displayPrinterInfo() const;
};

#endif