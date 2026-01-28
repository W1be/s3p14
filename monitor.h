#ifndef MONITOR_H
#define MONITOR_H

#include "peripheral.h"

class Monitor : public Peripheral {
private:
    double screenSize;
    string resolution;
    bool isCurved;

public:
    Monitor(const string& manufacturer, int year, double price, int stockQuantity,
            double screenSize, const string& resolution, bool isCurved);
    
    double calculateTotalValue() const override;
    string getDeviceType() const override;
    
    double getScreenSize() const;
    string getResolution() const;
    bool getIsCurved() const;
    void setScreenSize(double size);
    void setResolution(const string& resolution);
    void setIsCurved(bool curved);
    void calibrate();
    void upgradeResolution(const string& newResolution);
    void displayMonitorInfo() const;
};

#endif