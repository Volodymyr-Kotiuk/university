#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

enum class ConnectionStatus {
    Active,
    TemporarilyDisconnected,
    Blocked
};

class Subscriber {
protected:
    std::string name;
    std::string phoneNumber;
    std::string servicePackage;
    double invoiceAmount;
    ConnectionStatus connectionStatus;
    std::string email;
    std::string address;
    double balance;
    std::time_t registrationDate;

public:
    Subscriber(std::string n, std::string p, std::string s, double i, ConnectionStatus c,
        std::string e, std::string a, double b, std::time_t regDate);
    Subscriber();
    virtual ~Subscriber();

    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getServicePackage() const;
    ConnectionStatus getConnectionStatus() const;

    void setServicePackage(const std::string& newPackage);
    void setConnectionStatus(ConnectionStatus newStatus);

    virtual void printDetails() const;

    void saveToFile(const std::string& filename) const;
    void readFromFile(const std::string& filename);
};

#endif
