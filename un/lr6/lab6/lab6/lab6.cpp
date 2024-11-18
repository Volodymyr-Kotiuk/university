#include "basic_subscriber.h"
#include "premium_subscriber.h"
#include "template_class.h"
#include <iostream>
#include <vector>

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Create Basic Subscriber\n";
    std::cout << "2. Create Premium Subscriber\n";
    std::cout << "3. View All Subscribers\n";
    std::cout << "4. Overloaded Operators\n";
    std::cout << "5. Template Class\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option (1-6): ";
}

int main() {
    int choice;
    std::string name, phoneNumber;
    double balance;

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
            subscribers.push_back(new PremiumSubscriber(name, phoneNumber, balance));
            break;
        }

        case 3: {
            for (auto* subscriber : subscribers) {
                subscriber->printDetails();
                std::cout << "-------------------------\n";
            }
            break;
        }

        case 4: {
            if (subscribers.empty()) {
                std::cout << "No subscribers available to test operators.\n";
                break;
            }

            auto* sub = subscribers.front();
            std::cout << "Testing operators on first subscriber...\n";
            (*sub) += 50; // Поповнення
            (*sub) -= 20; // Зняття
            (*sub) *= 1.1; // Збільшення балансу
            sub->printDetails();
            break;
        }

        case 5: {
            TemplateClass<int, double, float, long, short> templateObj(1, 2.5, 3.5f, 4L, 5);
            templateObj.printValues();
            std::cout << "Sum of values: " << templateObj.sumValues() << "\n";
            break;
        }

        case 6: {
            for (auto* subscriber : subscribers) {
                delete subscriber;
            }
            std::cout << "Exiting...\n";
            return 0;
        }

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}
