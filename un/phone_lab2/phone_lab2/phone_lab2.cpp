#include "TelephoneExchange.h"

using namespace std;

int main() {

    // обєкти статичної памяті
    TelephoneExchange staticSubscribers[5] = {
        {"Andriy", "123-456-7890"},
        {"Viktor", "234-567-8901"},
        {"Vitalik", "345-678-9012"},
        {"Vlad", "456-789-0123"},
        {"Volodymyr", "567-890-1234"}
    };

    // обєкти динамічної памяті
    TelephoneExchange* dynamicSubscribers[5];
    for (int i = 0; i < 5; ++i) {
        dynamicSubscribers[i] = new TelephoneExchange("Sub" + to_string(i + 1), "000-000-000" + to_string(i));
    }

    
    const int numStatic = sizeof(staticSubscribers) / sizeof(staticSubscribers[0]);
    const int numDynamic = sizeof(dynamicSubscribers) / sizeof(dynamicSubscribers[0]);

    
    for (int i = 0; i < numStatic; ++i) {
        staticSubscribers[i].addServicePackage("Basic Plan");
        staticSubscribers[i].displayInfo(true);
    }

    
    for (int i = 0; i < numDynamic; ++i) {
        dynamicSubscribers[i]->addServicePackage("Premium Plan");
        dynamicSubscribers[i]->displayInfo(true);

        dynamicSubscribers[i]->writeToFile("subscriber" + to_string(i + 1) + ".txt");

        dynamicSubscribers[i]->allocateAndSort(); // сортує рандомні значення
    }

    // чистить динамічну память
    for (int i = 0; i < 5; ++i) {
        delete dynamicSubscribers[i];
    }

    return 0;
}


