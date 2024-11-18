#include "billing_and_support.h"
#include <iostream>

Billing::Billing(double bal) : balance(bal) {}
void Billing::showBillingInfo() const {
    std::cout << "Balance: $" << balance << "\n";
}

Support::Support(std::string contact) : supportContact(contact) {}
void Support::showSupportInfo() const {
    std::cout << "Support Contact: " << supportContact << "\n";
}

MultiServiceSubscriber::MultiServiceSubscriber(std::string n, std::string p, std::string s, double i, ConnectionStatus c,
    std::string e, std::string a, double b, std::time_t regDate,
    double bal, std::string contact)
    : Subscriber(n, p, s, i, c, e, a, b, regDate), Billing(bal), Support(contact) {}

void MultiServiceSubscriber::showFullInfo() const {
    printDetails();
    showBillingInfo();
    showSupportInfo();
}
