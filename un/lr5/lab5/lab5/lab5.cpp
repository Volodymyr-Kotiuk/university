#include "basic_subscriber.h"
#include "premium_subscriber.h"
#include <iostream>
#include <vector>

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Create Basic Subscriber\n";
    std::cout << "2. Create Premium Subscriber\n";
    std::cout << "3. View All Subscribers\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option (1-4): ";
}

int main() {
    int choice;
    std::string name, phoneNumber;
    double balance;

    // Створюємо вектор абонентів
    std::vector<Subscriber*> subscribers;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Enter details for Basic Subscriber:\n";
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Phone Number: ";
            std::cin >> phoneNumber;
            std::cout << "Balance: ";
            std::cin >> balance;

            // Створюємо BasicSubscriber і додаємо до вектору
            subscribers.push_back(new BasicSubscriber(name, phoneNumber, balance));
            break;
        }

        case 2: {
            std::cout << "Enter details for Premium Subscriber:\n";
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Phone Number: ";
            std::cin >> phoneNumber;
            std::cout << "Balance: ";
            std::cin >> balance;

            // Створюємо PremiumSubscriber і додаємо до вектору
            subscribers.push_back(new PremiumSubscriber(name, phoneNumber, balance));
            break;
        }

        case 3: {
            std::cout << "All Subscribers:\n";
            for (auto* subscriber : subscribers) {
                subscriber->printDetails();
                std::cout << "-------------------------\n";
            }

            // Поліморфні виклики
            std::cout << "\nDemonstrating polymorphic calls:\n";
            for (auto* subscriber : subscribers) {
                subscriber->applyDiscount();
                subscriber->sendNotification();
            }
            break;
        }

        case 4: {
            std::cout << "Exiting...\n";
            // Очищуємо пам'ять
            for (auto* subscriber : subscribers) {
                delete subscriber;
            }
            return 0;
        }

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
