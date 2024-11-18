#ifndef PREMIUM_SUBSCRIBER_H
#define PREMIUM_SUBSCRIBER_H

#include "subscriber.h"

class PremiumSubscriber : public Subscriber {
public:
    // Конструктор
    PremiumSubscriber(std::string name, std::string phoneNumber, double balance);

    // Віртуальні функції
    void printDetails() const override;
    void applyDiscount() override;
    void sendNotification() override;
};

#endif // PREMIUM_SUBSCRIBER_H
