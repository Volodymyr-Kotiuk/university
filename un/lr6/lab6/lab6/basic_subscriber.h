#ifndef BASIC_SUBSCRIBER_H
#define BASIC_SUBSCRIBER_H

#include "subscriber.h"

class BasicSubscriber : public Subscriber {
public:
    // �����������
    BasicSubscriber(std::string name, std::string phoneNumber, double balance);

    // ³������� �������
    void printDetails() const override;
    void applyDiscount() override;
    void sendNotification() override;
};

#endif // BASIC_SUBSCRIBER_H
