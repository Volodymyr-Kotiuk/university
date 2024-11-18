#include "basic_subscriber.h"
#include <iostream>

// Конструктор
BasicSubscriber::BasicSubscriber(std::string name, std::string phoneNumber, double balance)
    : Subscriber(name, phoneNumber, balance, "Active") {}

// Віртуальні функції
void BasicSubscriber::printDetails() const {
    std::cout << "Basic Subscriber:\n"
        << "Name: " << name << "\n"
        << "Phone: " << phoneNumber << "\n"
        << "Balance: $" << balance << "\n"
        << "Status: " << status << "\n";
}

void BasicSubscriber::applyDiscount() {
    std::cout << "Basic Subscriber: Applying no discount.\n";
}

void BasicSubscriber::sendNotification() {
    std::cout << "Basic Subscriber: Sending basic notification.\n";
}
