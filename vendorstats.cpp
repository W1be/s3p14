#include "vendorstats.h"
#include <iostream>
#include <iomanip>
using namespace std;

int VendorStats::countDevicesByVendor(const vector<Peripheral*>& devices, 
                                      const string& vendorName) {
    int count = 0;
    for (const auto& device : devices) {
        if (device->getManufacturer() == vendorName) {
            count++;
        }
    }
    return count;
}

double VendorStats::calculateTotalInventoryValue(const vector<Peripheral*>& devices) {
    double total = 0.0;
    for (const auto& device : devices) {
        total += device->calculateTotalValue();
    }
    return total;
}

void VendorStats::displayVendorStatistics(const vector<Peripheral*>& devices) {
    map<string, int> vendorCount;
    map<string, double> vendorValue;
    
    for (const auto& device : devices) {
        string vendor = device->getManufacturer();
        vendorCount[vendor]++;
        vendorValue[vendor] += device->calculateTotalValue();
    }
    
    cout << "\n=== СТАТИСТИКА ПО ПРОИЗВОДИТЕЛЯМ ===" << endl;
    for (const auto& [vendor, count] : vendorCount) {
        cout << "Производитель: " << vendor 
             << ", Количество устройств: " << count
             << ", Общая стоимость: $" << fixed << setprecision(2) 
             << vendorValue[vendor] << endl;
    }
}