#include "premium_subscriber.h"

PremiumSubscriber::PremiumSubscriber(std::string n, std::string p, std::string s, double i, ConnectionStatus c,
    std::string e, std::string a, double b, std::time_t regDate,
    std::string loyalty)
    : Subscriber(n, p, s, i, c, e, a, b, regDate), loyaltyProgram(loyalty) {}

void PremiumSubscriber::showLoyaltyDetails() const {
    printDetails();
    std::cout << "Loyalty Program: " << loyaltyProgram << "\n";
}
