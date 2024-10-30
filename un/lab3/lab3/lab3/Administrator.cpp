#include "Administrator.h"
#include <iostream>

void Administrator::changePhoneNumber(Subscriber& subscriber, const std::string& newNumber) {
    std::cout << "Changing phone number to: " << newNumber << std::endl;
    // Logic for changing the subscriber's number
}

void Administrator::disconnectForNonPayment(Subscriber& subscriber) {
    std::cout << "Disconnecting subscriber due to non-payment." << std::endl;
    // Logic to mark subscriber as disconnected
    subscriber.setBalance(0); // Example action
}

void Administrator::changeServicePackage(Subscriber& subscriber, const std::string& newPackage) {
    std::cout << "Changing service package to " << newPackage << std::endl;
    // Logic to update the service package
}
