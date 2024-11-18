#include "premium_subscriber.h"
#include <iostream>

// Конструктор
PremiumSubscriber::PremiumSubscriber(std::string name, std::string phoneNumber, double balance)
    : Subscriber(name, phoneNumber, balance, "Active") {}

// Віртуальні функції
void PremiumSubscriber::printDetails() const {
    std::cout << "Premium Subscriber:\n"
        << "Name: " << name << "\n"
        << "Phone: " << phoneNumber << "\n"
        << "Balance: $" << balance << "\n"
        << "Status: " << status << "\n";
}

void PremiumSubscriber::applyDiscount() {
    std::cout << "Premium Subscriber: Applying 20% discount.\n";
}

void PremiumSubscriber::sendNotification() {
    std::cout << "Premium Subscriber: Sending premium notification.\n";
}
