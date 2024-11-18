#ifndef PREMIUM_SUBSCRIBER_H
#define PREMIUM_SUBSCRIBER_H

#include "subscriber.h"

class PremiumSubscriber : public Subscriber {
public:
    // �����������
    PremiumSubscriber(std::string name, std::string phoneNumber, double balance);

    // ³������� �������
    void printDetails() const override;
    void applyDiscount() override;
    void sendNotification() override;
};

#endif // PREMIUM_SUBSCRIBER_H
