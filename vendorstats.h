#ifndef VENDORSTATS_H
#define VENDORSTATS_H

#include "peripheral.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

class VendorStats {
public:
    static int countDevicesByVendor(const vector<Peripheral*>& devices, 
                                    const string& vendorName);
    static double calculateTotalInventoryValue(const vector<Peripheral*>& devices);
    static void displayVendorStatistics(const vector<Peripheral*>& devices);
};

#endif