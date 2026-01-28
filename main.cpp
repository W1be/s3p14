#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include "peripheral.h"
#include "printer.h"
#include "monitor.h"
#include "vendorstats.h"
using namespace std;

void displayMenu() {
    cout << "\n=== МЕНЮ УПРАВЛЕНИЯ ПЕРИФЕРИЙНЫМИ УСТРОЙСТВАМИ ===" << endl;
    cout << "1. Показать все устройства" << endl;
    cout << "2. Добавить принтер" << endl;
    cout << "3. Добавить монитор" << endl;
    cout << "4. Изменить устройство" << endl;
    cout << "5. Пополнить запасы устройства" << endl;
    cout << "6. Выполнить действие с устройством" << endl;
    cout << "7. Показать статистику по производителям" << endl;
    cout << "8. Вычислить общую стоимость инвентаря" << endl;
    cout << "9. Выход" << endl;
    cout << "Выберите действие: ";
}

void addPrinter(vector<Peripheral*>& devices) {
    string manufacturer;
    int year, stock, ppm;
    double price;
    string technology;
    bool isColor;
    
    cout << "Введите производителя: ";
    cin >> manufacturer;
    cout << "Введите год выпуска: ";
    cin >> year;
    cout << "Введите цену: ";
    cin >> price;
    cout << "Введите количество на складе: ";
    cin >> stock;
    cout << "Введите технологию (laser/inkjet/dotmatrix): ";
    cin >> technology;
    cout << "Цветной? (1 - да, 0 - нет): ";
    cin >> isColor;
    cout << "Введите скорость печати (стр/мин): ";
    cin >> ppm;
    
    devices.push_back(new Printer(manufacturer, year, price, stock, 
                                  technology, isColor, ppm));
    cout << "Принтер добавлен!" << endl;
}

void addMonitor(vector<Peripheral*>& devices) {
    string manufacturer, resolution;
    int year, stock;
    double price, size;
    bool isCurved;
    
    cout << "Введите производителя: ";
    cin >> manufacturer;
    cout << "Введите год выпуска: ";
    cin >> year;
    cout << "Введите цену: ";
    cin >> price;
    cout << "Введите количество на складе: ";
    cin >> stock;
    cout << "Введите размер диагонали (дюймы): ";
    cin >> size;
    cout << "Введите разрешение (например, 1920x1080): ";
    cin >> resolution;
    cout << "Изогнутый? (1 - да, 0 - нет): ";
    cin >> isCurved;
    
    devices.push_back(new Monitor(manufacturer, year, price, stock, 
                                  size, resolution, isCurved));
    cout << "Монитор добавлен!" << endl;
}

void modifyDevice(vector<Peripheral*>& devices) {
    if (devices.empty()) {
        cout << "Нет устройств для изменения!" << endl;
        return;
    }
    
    cout << "\nСписок устройств:" << endl;
    for (size_t i = 0; i < devices.size(); i++) {
        cout << i + 1 << ". ";
        devices[i]->displayInfo();
        cout << ", Тип: " << devices[i]->getDeviceType() << endl;
    }
    
    int index;
    cout << "Введите номер устройства для изменения (1-" << devices.size() << "): ";
    cin >> index;
    
    if (index < 1 || index > static_cast<int>(devices.size())) {
        cout << "Неверный номер!" << endl;
        return;
    }
    
    Peripheral* device = devices[index - 1];
    
    int choice;
    cout << "Что изменить?" << endl;
    cout << "1. Производитель" << endl;
    cout << "2. Год выпуска" << endl;
    cout << "3. Цена" << endl;
    cout << "4. Количество на складе" << endl;
    cout << "Выберите: ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            string manufacturer;
            cout << "Введите нового производителя: ";
            cin >> manufacturer;
            device->setManufacturer(manufacturer);
            break;
        }
        case 2: {
            int year;
            cout << "Введите новый год выпуска: ";
            cin >> year;
            device->setYear(year);
            break;
        }
        case 3: {
            double price;
            cout << "Введите новую цену: ";
            cin >> price;
            device->setPrice(price);
            break;
        }
        case 4: {
            int quantity;
            cout << "Введите новое количество: ";
            cin >> quantity;
            device->setStockQuantity(quantity);
            break;
        }
        default:
            cout << "Неверный выбор!" << endl;
    }
}

void performDeviceAction(vector<Peripheral*>& devices) {
    if (devices.empty()) {
        cout << "Нет устройств!" << endl;
        return;
    }
    
    cout << "\nСписок устройств:" << endl;
    for (size_t i = 0; i < devices.size(); i++) {
        cout << i + 1 << ". ";
        devices[i]->displayInfo();
        cout << ", Тип: " << devices[i]->getDeviceType() << endl;
    }
    
    int index;
    cout << "Введите номер устройства (1-" << devices.size() << "): ";
    cin >> index;
    
    if (index < 1 || index > static_cast<int>(devices.size())) {
        cout << "Неверный номер!" << endl;
        return;
    }
    
    Peripheral* device = devices[index - 1];
    
    if (Printer* printer = dynamic_cast<Printer*>(device)) {
        int action;
        cout << "Выберите действие для принтера:" << endl;
        cout << "1. Распечатать тестовую страницу" << endl;
        cout << "2. Модернизировать до цветного" << endl;
        cout << "3. Показать информацию" << endl;
        cout << "Выберите: ";
        cin >> action;
        
        switch(action) {
            case 1:
                printer->printTestPage();
                break;
            case 2:
                printer->upgradeToColor();
                break;
            case 3:
                printer->displayPrinterInfo();
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } else if (Monitor* monitor = dynamic_cast<Monitor*>(device)) {
        int action;
        cout << "Выберите действие для монитора:" << endl;
        cout << "1. Откалибровать" << endl;
        cout << "2. Улучшить разрешение" << endl;
        cout << "3. Показать информацию" << endl;
        cout << "Выберите: ";
        cin >> action;
        
        switch(action) {
            case 1:
                monitor->calibrate();
                break;
            case 2: {
                string newRes;
                cout << "Введите новое разрешение: ";
                cin >> newRes;
                monitor->upgradeResolution(newRes);
                break;
            }
            case 3:
                monitor->displayMonitorInfo();
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    }
}

int main() {
    vector<Peripheral*> devices;
    
    devices.push_back(new Printer("HP", 2023, 299.99, 10, 
                                  "laser", true, 25));
    devices.push_back(new Printer("Epson", 2022, 149.99, 15, 
                                  "inkjet", false, 15));
    devices.push_back(new Monitor("Samsung", 2023, 399.99, 8, 
                                  27.0, "2560x1440", false));
    devices.push_back(new Monitor("LG", 2024, 599.99, 5, 
                                  34.0, "3440x1440", true));
    devices.push_back(new Monitor("Dell", 2023, 349.99, 12, 
                                  24.0, "1920x1080", false));
    
    int choice;
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\n=== ВСЕ УСТРОЙСТВА ===" << endl;
                for (size_t i = 0; i < devices.size(); i++) {
                    cout << i + 1 << ". ";
                    if (dynamic_cast<Printer*>(devices[i])) {
                        static_cast<Printer*>(devices[i])->displayPrinterInfo();
                    } else if (dynamic_cast<Monitor*>(devices[i])) {
                        static_cast<Monitor*>(devices[i])->displayMonitorInfo();
                    }
                }
                break;
                
            case 2:
                addPrinter(devices);
                break;
                
            case 3:
                addMonitor(devices);
                break;
                
            case 4:
                modifyDevice(devices);
                break;
                
            case 5:
                if (devices.empty()) {
                    cout << "Нет устройств!" << endl;
                    break;
                }
                int idx, amount;
                cout << "Введите номер устройства (1-" << devices.size() << "): ";
                cin >> idx;
                if (idx >= 1 && idx <= static_cast<int>(devices.size())) {
                    cout << "Введите количество для пополнения: ";
                    cin >> amount;
                    devices[idx-1]->restock(amount);
                } else {
                    cout << "Неверный номер!" << endl;
                }
                break;
                
            case 6:
                performDeviceAction(devices);
                break;
                
            case 7:
                VendorStats::displayVendorStatistics(devices);
                break;
                
            case 8:
                cout << "\nОбщая стоимость инвентаря: $" 
                     << fixed << setprecision(2)
                     << VendorStats::calculateTotalInventoryValue(devices) 
                     << endl;
                break;
                
            case 9:
                cout << "Выход из программы..." << endl;
                break;
                
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (choice != 9);
    
    for (auto device : devices) {
        delete device;
    }
    
    return 0;
}