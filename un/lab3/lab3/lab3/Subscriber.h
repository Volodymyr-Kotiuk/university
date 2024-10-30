#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream> // ������ ��� ������ � �������

class Subscriber {
private:
    int subscriberID;
    std::string name;
    double balance;
    std::string phoneNumber;
    std::string status;
    std::vector<std::string> services;
    std::vector<int> randomNumbers; // ��������� ������������ ���������� �����
    static int totalSubscribers;

public:
    Subscriber();
    Subscriber(int id, const std::string& name, double balance, const std::string& phoneNumber, const std::string& status);
    Subscriber(const Subscriber& other);

    int getSubscriberID() const;
    std::string getName() const;
    void setBalance(double newBalance);
    double getBalance() const;

    void addService(const std::string& service);
    void addService(const std::string& service, double serviceCost);

    void generateRandomPhoneNumber(); // ���������� �����
    void allocateAndSortRandomNumbers();

    void displayInfo() const;

    static int getTotalSubscribers();

    void writeToFile(const std::string& filename) const; // ����������
    void readFromFile(const std::string& filename);

    ~Subscriber();
};

// ���������� ������� ���� ������ ����� �� ������� �� ������� ���� �����
void displaySubscriberBalance(const Subscriber& subscriber);
Subscriber createSubscriber(int id, const std::string& name, double balance);

#endif // SUBSCRIBER_H
