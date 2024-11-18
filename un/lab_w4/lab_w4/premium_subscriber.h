#ifndef PREMIUM_SUBSCRIBER_H
#define PREMIUM_SUBSCRIBER_H

#include "subscriber.h"

class PremiumSubscriber : private Subscriber {
    std::string loyaltyProgram;

public:
    PremiumSubscriber(std::string n, std::string p, std::string s, double i, ConnectionStatus c,
        std::string e, std::string a, double b, std::time_t regDate,
        std::string loyalty);

    using Subscriber::printDetails;

    void showLoyaltyDetails() const;
};

#endif
