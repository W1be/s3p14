#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include “peripheral.h”
#include “printer.h”
#include “monitor.h”
#include “vendorstats.h”
Using namespace std;
Void displayAllDevicesAsTable(const vector<Peripheral*>& devices) {
If (devices.empty()) {
Cout << “\n┌─────────────────────────────────────────────┐” << endl;
Cout << “│ Нет доступных устройств │” << endl;
Cout << “└─────────────────────────────────────────────┘” << endl;
Return;
}
Const int totalWidth = 110;
// Верх таблицы
Cout << “\n┌”;
For (int i = 0; i < totalWidth – 2; i++) cout << “─”;
Cout << “┐” << endl;
// Заголовок
String title = “СПИСОК ПЕРИФЕРИЙНЫХ УСТРОЙСТВ”;
Int padding = (totalWidth – title.length() – 2) / 2;
Cout << “│” << setw(padding) << “” << title << setw(padding) << “” << “│” << endl;
// Разделитель
Cout << “├”;
For (int i = 0; i < totalWidth – 2; i++) cout << “─”;
Cout << “┤” << endl;
// Заголовки столбцов
Cout << left;
Cout << “│ “ << setw(4) << “№”
<< “│ “ << setw(12) << “Тип”
<< “│ “ << setw(18) << “Производитель”
<< “│ “ << setw(6) << “Год”
<< “│ “ << setw(10) << “Цена,$”
<< “│ “ << setw(8) << “Кол-во”
<< “│ “ << setw(25) << “Характеристики”
<< “│ “ << setw(12) << “Общ.стоимость”
<< “│” << endl;
Cout << “├”;
For (int i = 0; i < totalWidth – 2; i++) cout << “─”;
Cout << “┤” << endl;
// Данные
Double totalValue = 0;
For (size_t i = 0; i < devices.size(); i++) {
Cout << “│ “ << setw(4) << (i + 1);
Cout << “│ “ << setw(12) << devices[i]->getDeviceType();
Cout << “│ “ << setw(18) << devices[i]->getManufacturer();
Cout << “│ “ << setw(6) << devices[i]->getYear();
Cout << “│ $” << setw(9) << fixed << setprecision(2) << devices[i]->getPrice();
Cout << “│ “ << setw(8) << devices[i]->getStockQuantity();
// Характеристики
String specs;
If (Printer* printer = dynamic_cast<Printer*>(devices[i])) {
Specs = printer->getTechnology() + “, “ +
(printer->getIsColor() ? “Цвет” : “Ч/б”) + “, “ +
To_string(printer->getPagesPerMinute()) + “ стр/мин”;
} else if (Monitor* monitor = dynamic_cast<Monitor*>(devices[i])) {
Specs = to_string((int)monitor->getScreenSize()) + “\”, “ +
Monitor->getResolution() + “, “ +
(monitor->getIsCurved() ? “Изогн.” : “Плоский”);
}
Cout << “│ “ << setw(25) << specs;
Double deviceValue = devices[i]->calculateTotalValue();
Cout << “│ $” << setw(11) << fixed << setprecision(2) << deviceValue << “│”;
Cout << endl;
totalValue += deviceValue;
// Разделитель строк
If (i < devices.size() – 1) {
Cout << “├”;
For (int j = 0; j < 4 + 1; j++) cout << “─”; cout << “┼”;
For (int j = 0; j < 12 + 1; j++) cout << “─”; cout << “┼”;
For (int j = 0; j < 18 + 1; j++) cout << “─”; cout << “┼”;
For (int j = 0; j < 6 + 1; j++) cout << “─”; cout << “┼”;
For (int j = 0; j < 10 + 1; j++) cout << “─”; cout << “┼”;
For (int j = 0; j < 8 + 1; j++) cout << “─”; cout << “┼”;
For (int j = 0; j < 25 + 1; j++) cout << “─”; cout << “┼”;
For (int j = 0; j < 12 + 1; j++) cout << “─”; cout << “┤” << endl;
}
}
// Низ таблицы
Cout << “└”;
For (int i = 0; i < totalWidth – 2; i++) cout << “─”;
Cout << “┘” << endl;
// Итоги
Cout << “\n📊 Статистика:” << endl;
Cout << “├─────────────────────────────────────” << endl;
Cout << “│ • Всего устройств: “ << devices.size() << endl;
Cout << “│ • Общая стоимость: $” << fixed << setprecision(2) << totalValue << endl;
Cout << “└─────────────────────────────────────” << endl;
}
Void displayDevicesSimpleList(const vector<Peripheral*>& devices) {
If (devices.empty()) {
Cout << “Нет доступных устройств” << endl;
Return;
}
Cout << “\nСписок устройств:” << endl;
For (size_t i = 0; i < devices.size(); i++) {
Cout << i + 1 << “. “;
Devices[i]->displayInfo();
Cout << “, Тип: “ << devices[i]->getDeviceType() << endl;
}
}
Void addPrinter(vector<Peripheral*>& devices) {
String manufacturer, technology;
Int year, stock, ppm;
Double price;
Bool isColor;
Char colorChoice;
Cout << “\n=== ДОБАВЛЕНИЕ ПРИНТЕРА ===” << endl;
Cout << “Введите производителя: “;
Cin.ignore();
Getline(cin, manufacturer);
Cout << “Введите год выпуска: “;
Cin >> year;
Cout << “Введите цену: “;
Cin >> price;
Cout << “Введите количество на складе: “;
Cin >> stock;
Cout << “Введите технологию (laser/inkjet/dotmatrix): “;
Cin >> technology;
Cout << “Цветной? (1 – да, 0 – нет): “;
Cin >> isColor;
Cout << “Введите скорость печати (стр/мин): “;
Cin >> ppm;
Devices.push_back(new Printer(manufacturer, year, price, stock, technology, isColor, ppm));
Cout << “Принтер добавлен!” << endl;
}
Void addMonitor(vector<Peripheral*>& devices) {
String manufacturer, resolution;
Int year, stock;
Double price, size;
Bool isCurved;
Cout << “\n=== ДОБАВЛЕНИЕ МОНИТОРА ===” << endl;
Cout << “Введите производителя: “;
Cin.ignore();
Getline(cin, manufacturer);
Cout << “Введите год выпуска: “;
Cin >> year;
Cout << “Введите цену: “;
Cin >> price;
Cout << “Введите количество на складе: “;
Cin >> stock;
Cout << “Введите размер диагонали (дюймы): “;
Cin >> size;
Cout << “Введите разрешение (например, 1920x1080): “;
Cin >> resolution;
Cout << “Изогнутый? (1 – да, 0 – нет): “;
Cin >> isCurved;
Devices.push_back(new Monitor(manufacturer, year, price, stock, size, resolution, isCurved));
Cout << “Монитор добавлен!” << endl;
}
Void modifyDevice(vector<Peripheral*>& devices) {
If (devices.empty()) {
Cout << “Нет устройств для изменения!” << endl;
Return;
}
displayDevicesSimpleList(devices);
int index;
cout << “Введите номер устройства для изменения (1-“ << devices.size() << “): “;
cin >> index;
if (index < 1 || index > (int)devices.size()) {
cout << “Неверный номер!” << endl;
return;
}
Peripheral* device = devices[index – 1];
Int choice;
Cout << “Что изменить?” << endl;
Cout << “1. Производитель” << endl;
Cout << “2. Год выпуска” << endl;
Cout << “3. Цена” << endl;
Cout << “4. Количество на складе” << endl;
Cout << “Выберите: “;
Cin >> choice;
Switch(choice) {
Case 1: {
String manufacturer;
Cout << “Введите нового производителя: “;
Cin.ignore();
Getline(cin, manufacturer);
Device->setManufacturer(manufacturer);
Break;
}
Case 2: {
Int year;
Cout << “Введите новый год выпуска: “;
Cin >> year;
Device->setYear(year);
Break;
}
Case 3: {
Double price;
Cout << “Введите новую цену: “;
Cin >> price;
Device->setPrice(price);
Break;
}
Case 4: {
Int quantity;
Cout << “Введите новое количество: “;
Cin >> quantity;
Device->setStockQuantity(quantity);
Break;
}
Default:
Cout << “Неверный выбор!” << endl;
}
}
Void performDeviceAction(vector<Peripheral*>& devices) {
If (devices.empty()) {
Cout << “Нет устройств!” << endl;
Return;
}
displayDevicesSimpleList(devices);
int index;
cout << “Введите номер устройства (1-“ << devices.size() << “): “;
cin >> index;
if (index < 1 || index > (int)devices.size()) {
cout << “Неверный номер!” << endl;
return;
}
Peripheral* device = devices[index – 1];
If (Printer* printer = dynamic_cast<Printer*>(device)) {
Int action;
Cout << “Выберите действие для принтера:” << endl;
Cout << “1. Распечатать тестовую страницу” << endl;
Cout << “2. Модернизировать до цветного” << endl;
Cout << “Выберите: “;
Cin >> action;
If (action == 1) {
Printer->printTestPage();
} else if (action == 2) {
Printer->upgradeToColor();
} else {
Cout << “Неверный выбор!” << endl;
}
} else if (Monitor* monitor = dynamic_cast<Monitor*>(device)) {
Int action;
Cout << “Выберите действие для монитора:” << endl;
Cout << “1. Откалибровать” << endl;
Cout << “2. Улучшить разрешение” << endl;
Cout << “Выберите: “;
Cin >> action;
If (action == 1) {
Monitor->calibrate();
} else if (action == 2) {
String newRes;
Cout << “Введите новое разрешение: “;
Cin >> newRes;
Monitor->upgradeResolution(newRes);
} else {
Cout << “Неверный выбор!” << endl;
}
}
}
Void displayMenu() {
Cout << “\n╔══════════════════════════════════════════════════════════╗” << endl;
Cout << “║ СИСТЕМА УПРАВЛЕНИЯ ПЕРИФЕРИЕЙ ║” << endl;
Cout << “╠══════════════════════════════════════════════════════════╣” << endl;
Cout << “║ 1. Показать все устройства (ТАБЛИЦА) ║” << endl;
Cout << “║ 2. Добавить принтер ║” << endl;
Cout << “║ 3. Добавить монитор ║” << endl;
Cout << “║ 4. Изменить устройство ║” << endl;
Cout << “║ 5. Пополнить запасы устройства ║” << endl;
Cout << “║ 6. Выполнить действие с устройством ║” << endl;
Cout << “║ 7. Показать статистику по производителям ║” << endl;
Cout << “║ 8. Вычислить общую стоимость инвентаря ║” << endl;
Cout << “║ 9. Выход из программы ║” << endl;
Cout << “╚══════════════════════════════════════════════════════════╝” << endl;
Cout << “Выберите действие (1-9): “;
}
Int main() {
Vector<Peripheral*> devices;
// Начальные данные
Devices.push_back(new Printer(“HP”, 2023, 299.99, 10, “laser”, true, 25));
Devices.push_back(new Printer(“Epson”, 2022, 149.99, 15, “inkjet”, false, 15));
Devices.push_back(new Monitor(“Samsung”, 2023, 399.99, 8, 27.0, “2560x1440”, false));
Devices.push_back(new Monitor(“LG”, 2024, 599.99, 5, 34.0, “3440x1440”, true));
Devices.push_back(new Monitor(“Dell”, 2023, 349.99, 12, 24.0, “1920x1080”, false));
Int choice;
Do {
displayMenu();
cin >> choice;
switch(choice) {
case 1: // ТАБЛИЦА – только здесь!
displayAllDevicesAsTable(devices);
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
cout << “Нет устройств!” << endl;
break;
}
displayDevicesSimpleList(devices);
int idx, amount;
cout << “Введите номер устройства (1-“ << devices.size() << “): “;
cin >> idx;
if (idx >= 1 && idx <= (int)devices.size()) {
cout << “Введите количество для пополнения: “;
cin >> amount;
devices[idx-1]->restock(amount);
} else {
Cout << “Неверный номер!” << endl;
}
Break;
Case 6:
performDeviceAction(devices);
break;
case 7:
VendorStats::displayVendorStatistics(devices);
Break;
Case 8:
Cout << “\nОбщая стоимость инвентаря: $”
<< fixed << setprecision(2)
<< VendorStats::calculateTotalInventoryValue(devices)
<< endl;
Break;
Case 9:
Cout << “Выход из программы...” << endl;
Break;
Default:
Cout << “Неверный выбор!” << endl;
}
If (choice != 9) {
Cout << “\nНажмите Enter для продолжения...”;
Cin.ignore();
Cin.get();
}
} while (choice != 9);
// Очистка памяти
For (auto device : devices) {
Delete device;
}
Return 0;
}
