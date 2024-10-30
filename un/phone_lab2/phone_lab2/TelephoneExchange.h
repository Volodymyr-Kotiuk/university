#ifndef TELEPHONE_EXCHANGE_H
#define TELEPHONE_EXCHANGE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
class TelephoneExchange {
private:
    string subscriberName; 
    string phoneNumber;     
    vector<string> servicePackages; 
    double invoiceAmount;        
    string connectionStatus; 

public:
    // конструктор
    TelephoneExchange(string name, string number);

    // метод додавання пакету послуг
    void addServicePackage(string service);

    // метод зміни номеру телефону
    //void changePhoneNumber(string newNumber);

    // метод оплати рахунку
    //void payInvoice(double amount);

    // Перевантажений метод відображення інформації про абонента
    void displayInfo();
    void displayInfo(bool detailed);

    //  Метод запису полів даних у файл
    void writeToFile(const string& filename);

    //  Метод читання з файлу
    void readFromFile(const string& filename);

    void allocateAndSort();

    double getInvoiceAmount() const;

};

#endif



