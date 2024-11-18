#include "subscriber.h"

// ����������� ���������� �����
std::vector<Subscriber*> Subscriber::allSubscribers;

// �����������
Subscriber::Subscriber(std::string name, std::string phoneNumber, double balance, std::string status)
    : name(name), phoneNumber(phoneNumber), balance(balance), status(status) {
    allSubscribers.push_back(this);
}

// ��������� ����� ��������� ��� ��������
void Subscriber::ViewAllSubscribers() {
    for (auto* subscriber : allSubscribers) {
        subscriber->printDetails();
    }
}

// ����������
Subscriber::~Subscriber() {
    allSubscribers.erase(std::remove(allSubscribers.begin(), allSubscribers.end(), this), allSubscribers.end());
}
