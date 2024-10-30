#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "Subscriber.h"

class Administrator {
public:
    void changePhoneNumber(Subscriber& subscriber, const std::string& newNumber);
    void disconnectForNonPayment(Subscriber& subscriber);
    void changeServicePackage(Subscriber& subscriber, const std::string& newPackage);
};

#endif // ADMINISTRATOR_H
