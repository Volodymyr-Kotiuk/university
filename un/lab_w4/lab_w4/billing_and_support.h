#ifndef BILLING_AND_SUPPORT_H
#define BILLING_AND_SUPPORT_H

#include "subscriber.h"

// Клас Billing
class Billing {
protected:
    double balance;
public:
    Billing(double bal);
    virtual void showBillingInfo() const;
};

// Клас Support
class Support {
protected:
    std::string supportContact;
public:
    Support(std::string contact);
    virtual void showSupportInfo() const;
};

// Клас для множинного наслідування
class MultiServiceSubscriber : public Subscriber, public Billing, public Support {
public:
    MultiServiceSubscriber(std::string n, std::string p, std::string s, double i, ConnectionStatus c,
        std::string e, std::string a, double b, std::time_t regDate,
        double bal, std::string contact);

    using Subscriber::printDetails;

    void showFullInfo() const;
};

#endif
