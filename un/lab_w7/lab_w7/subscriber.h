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

    // �����������
    Subscriber(std::string name, std::string phoneNumber, double balance, std::string status);

    // ����� �������� �������
    virtual void printDetails() const = 0;
    virtual void applyDiscount() = 0;
    virtual void sendNotification() = 0;

    // ����� ��� ��������� �������
    virtual double getBalance() const { return balance; }

    // ������������ ���������
    virtual Subscriber& operator+(double amount);  // ���������� �������
    virtual Subscriber& operator-(double amount);  // ������ �����

    virtual Subscriber& operator*=(double multiplier); // ��������� �������
    virtual Subscriber& operator+=(double amount);     // ����������
    virtual Subscriber& operator-=(double amount);     // ������
    virtual double operator[](size_t index) const;     // ������� ������� �� �������

    // ��������� ����� ��������� ��� ��������
    static void ViewAllSubscribers();

    // ����������
    virtual ~Subscriber();
};


#endif // SUBSCRIBER_H
