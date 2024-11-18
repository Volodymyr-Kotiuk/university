#include "subscriber.h"

// ����������� ���������� �����
std::vector<Subscriber*> Subscriber::allSubscribers;

// �����������
Subscriber::Subscriber(std::string name, std::string phoneNumber, double balance, std::string status)
    : name(name), phoneNumber(phoneNumber), balance(balance), status(status) {
    allSubscribers.push_back(this);
}

// ����������
Subscriber::~Subscriber() {
    allSubscribers.erase(std::remove(allSubscribers.begin(), allSubscribers.end(), this), allSubscribers.end());
}

// ��������� ����� ��������� ��� ��������
void Subscriber::ViewAllSubscribers() {
    for (auto* subscriber : allSubscribers) {
        subscriber->printDetails();
    }
}

// �������������� ���������
Subscriber& Subscriber::operator+(double amount) {
    balance += amount;
    return *this;
}

Subscriber& Subscriber::operator-(double amount) {
    balance -= amount;
    return *this;
}

Subscriber& Subscriber::operator*=(double multiplier) {
    balance *= multiplier;
    return *this;
}

Subscriber& Subscriber::operator+=(double amount) {
    return *this + amount;
}

Subscriber& Subscriber::operator-=(double amount) {
    return *this - amount;
}

double Subscriber::operator[](size_t index) const {
    if (index == 0) return balance;
    throw std::out_of_range("Invalid index for Subscriber");
}
