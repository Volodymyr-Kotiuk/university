#include "subscriber.h"

// Ініціалізація статичного члена
std::vector<Subscriber*> Subscriber::allSubscribers;

// Конструктор
Subscriber::Subscriber(std::string name, std::string phoneNumber, double balance, std::string status)
    : name(name), phoneNumber(phoneNumber), balance(balance), status(status) {
    allSubscribers.push_back(this);
}

// Статичний метод перегляду всіх абонентів
void Subscriber::ViewAllSubscribers() {
    for (auto* subscriber : allSubscribers) {
        subscriber->printDetails();
    }
}

// Деструктор
Subscriber::~Subscriber() {
    allSubscribers.erase(std::remove(allSubscribers.begin(), allSubscribers.end(), this), allSubscribers.end());
}
