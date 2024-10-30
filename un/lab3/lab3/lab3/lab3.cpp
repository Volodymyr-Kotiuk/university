#include "Subscriber.h"
#include "Administrator.h"
#include "ServicePackage.h"
#include "Device.h"
#include <iostream>

int main() {
    srand(static_cast<unsigned int>(time(0))); // Початкова ініціалізація генератора випадкових чисел

    // Створення статичних підписників
    Subscriber staticSubscribers[] = {
        Subscriber(1, "Andriy", 0, "", "Disconnected (due to non-payment)"),
        Subscriber(2, "Viktor", 0, "", "Disconnected (due to non-payment)"),
        Subscriber(3, "Vitalik", 0, "", "Disconnected (due to non-payment)"),
        Subscriber(4, "Vlad", 0, "", "Disconnected (due to non-payment)"),
        Subscriber(5, "Volodymyr", 0, "", "Disconnected (due to non-payment)")
    };

    // Створення динамічних підписників
    Subscriber* dynamicSubscribers[5];
    for (int i = 0; i < 5; ++i) {
        dynamicSubscribers[i] = new Subscriber(6 + i, "Sub" + std::to_string(i + 1), 0, "", "Disconnected (due to non-payment)");
    }

    // Відображення інформації про всіх підписників
    for (const auto& subscriber : staticSubscribers) {
        subscriber.displayInfo();
        std::cout << std::endl;
    }

    for (int i = 0; i < 5; ++i) {
        dynamicSubscribers[i]->displayInfo();
        std::cout << std::endl;
    }

    // Виклик функції для відображення балансу підписника
    displaySubscriberBalance(staticSubscribers[0]);

    // Виклик функції, що повертає об'єкт Subscriber
    Subscriber newSub = createSubscriber(7, "Ivan", 50);
    newSub.displayInfo(); // Відображення інформації про нового підписника

    // Очищення динамічної пам'яті
    for (int i = 0; i < 5; ++i) {
        delete dynamicSubscribers[i];
    }

    return 0;
}
