#include "subscriber.h"

// Конструктори
Subscriber::Subscriber(std::string n, std::string p, std::string s, double i, ConnectionStatus c,
    std::string e, std::string a, double b, std::time_t regDate)
    : name(n), phoneNumber(p), servicePackage(s), invoiceAmount(i),
    connectionStatus(c), email(e), address(a), balance(b), registrationDate(regDate) {}

Subscriber::Subscriber()
    : name("Unknown"), phoneNumber("000-000"), servicePackage("Basic"),
    invoiceAmount(0.0), connectionStatus(ConnectionStatus::Active),
    email("unknown@example.com"), address("Unknown"), balance(0.0),
    registrationDate(std::time(nullptr)) {}

Subscriber::~Subscriber() = default;

// Методи
std::string Subscriber::getName() const { return name; }
std::string Subscriber::getPhoneNumber() const { return phoneNumber; }
std::string Subscriber::getServicePackage() const { return servicePackage; }
ConnectionStatus Subscriber::getConnectionStatus() const { return connectionStatus; }

void Subscriber::setServicePackage(const std::string& newPackage) { servicePackage = newPackage; }
void Subscriber::setConnectionStatus(ConnectionStatus newStatus) { connectionStatus = newStatus; }

void Subscriber::printDetails() const {
    char buffer[26];
    struct tm timeInfo;

    // Використовуємо localtime_s для отримання безпечного доступу до локального часу
    localtime_s(&timeInfo, &registrationDate);
    asctime_s(buffer, sizeof(buffer), &timeInfo);

    std::cout << "Name: " << name
        << "\nPhone Number: " << phoneNumber
        << "\nService Package: " << servicePackage
        << "\nInvoice Amount: $" << invoiceAmount
        << "\nConnection Status: " << (connectionStatus == ConnectionStatus::Active ? "Active" :
            connectionStatus == ConnectionStatus::TemporarilyDisconnected ? "Temporarily Disconnected" : "Blocked")
        << "\nEmail: " << email
        << "\nAddress: " << address
        << "\nBalance: $" << balance
        << "\nRegistration Date: " << buffer
        << "\n";
}


void Subscriber::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::app);
    if (outFile.is_open()) {
        outFile << name << "," << phoneNumber << "," << servicePackage << ","
            << invoiceAmount << "," << static_cast<int>(connectionStatus) << ","
            << email << "," << address << "," << balance << ","
            << registrationDate << "\n";
        outFile.close();
    }
}

void Subscriber::readFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            std::getline(inFile, name, ',');
            std::getline(inFile, phoneNumber, ',');
            std::getline(inFile, servicePackage, ',');
            inFile >> invoiceAmount;
            int status;
            inFile >> status;
            connectionStatus = static_cast<ConnectionStatus>(status);
            inFile.ignore(1, ',');
            std::getline(inFile, email, ',');
            std::getline(inFile, address, ',');
            inFile >> balance;
            inFile >> registrationDate;
            inFile.ignore(1, '\n');
            printDetails();
        }
        inFile.close();
    }
}
