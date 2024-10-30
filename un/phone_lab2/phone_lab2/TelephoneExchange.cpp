#include "TelephoneExchange.h"

using namespace std;

// імплементація конструктора
TelephoneExchange::TelephoneExchange(string name, string number)
    : subscriberName(name), phoneNumber(number), invoiceAmount(0.0), connectionStatus("active") {}

// метод додавання пакету послуг
void TelephoneExchange::addServicePackage(string service) {
    servicePackages.push_back(service);
}

// метод зміни номеру телефону
void TelephoneExchange::changePhoneNumber(string newNumber) {
    phoneNumber = newNumber;
}

// метод оплати рахунку
void TelephoneExchange::payInvoice(double amount) {
    invoiceAmount -= amount;
}

// Перевантажений метод відображення інформації про абонента
void TelephoneExchange::displayInfo() {
    cout << endl << endl << "Subscriber Name: " << subscriberName << endl
        << "Phone Number: " << phoneNumber << endl
        << "Invoice Amount: " << invoiceAmount << endl
        << "Connection Status: " << connectionStatus << endl;
}

void TelephoneExchange::displayInfo(bool detailed) {
    displayInfo();
    if (detailed) {
        cout << "Services: ";
        for (const auto& service : servicePackages) {
            cout << service << " ";
        }
        cout << " ";
    }
}

// Метод запису полів даних у файл
void TelephoneExchange::writeToFile(const string& filename) {
    ofstream outFile(filename);

    if (outFile.is_open()) {
        outFile << subscriberName << endl
            << phoneNumber << endl
            << invoiceAmount << endl
            << connectionStatus << endl;

            for (const auto& service : servicePackages) {
                outFile << service << " ";
            }

        outFile.close();
    }
}

// Метод читання з файлу
void TelephoneExchange::readFromFile(const string& filename) {
    ifstream inFile(filename);

    if (inFile.is_open()) {
        getline(inFile, subscriberName);
        getline(inFile, phoneNumber);
        inFile >> invoiceAmount;
        inFile.ignore();

        servicePackages.clear();
        std::string service;
        while (getline(inFile, service)) {
            if (!service.empty()) {
                servicePackages.push_back(service);
            }
        }

        inFile.close();
    }
}

// Метод розподілу випадкових значень у динамічній пам'яті та їх сортування
void TelephoneExchange::allocateAndSort() {
    int size = rand() % 10 + 1;  
    int* values = new int[size];

    for (int i = 0; i < size; ++i) {
        values[i] = rand() % 100; 
    }

    sort(values, values + size);

    cout << "Sorted Values: ";
    for (int i = 0; i < size; ++i) {
        cout << values[i] << " ";
    }

    delete[] values; // Вільна виділена пам'ять
}

// Спосіб отримання поточної суми рахунку
double TelephoneExchange::getInvoiceAmount() const {
    return invoiceAmount;
}





