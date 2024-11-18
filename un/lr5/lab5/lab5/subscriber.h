#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Subscriber {
protected:
    std::string name;
    std::string phoneNumber;
    double balance;
    std::string status;

public:
    static std::vector<Subscriber*> allSubscribers;

    // Конструктор
    Subscriber(std::string name, std::string phoneNumber, double balance, std::string status);

    // Чисто віртуальні функції
    virtual void printDetails() const = 0;
    virtual void applyDiscount() = 0;
    virtual void sendNotification() = 0;

    // Статичний метод перегляду всіх абонентів
    static void ViewAllSubscribers();

    // Деструктор
    virtual ~Subscriber();
};

#endif // SUBSCRIBER_H
