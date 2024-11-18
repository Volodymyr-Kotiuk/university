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

    // Метод для отримання балансу
    virtual double getBalance() const { return balance; }

    // Перевантажені оператори
    virtual Subscriber& operator+(double amount);  // Поповнення балансу
    virtual Subscriber& operator-(double amount);  // Зняття коштів

    virtual Subscriber& operator*=(double multiplier); // Збільшення балансу
    virtual Subscriber& operator+=(double amount);     // Поповнення
    virtual Subscriber& operator-=(double amount);     // Зняття
    virtual double operator[](size_t index) const;     // Читання балансу по індексу

    // Статичний метод перегляду всіх абонентів
    static void ViewAllSubscribers();

    // Деструктор
    virtual ~Subscriber();
};


#endif // SUBSCRIBER_H
