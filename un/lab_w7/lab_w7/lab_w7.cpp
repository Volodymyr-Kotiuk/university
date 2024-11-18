#include "basic_subscriber.h"
#include "premium_subscriber.h"
#include "template_class.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <random>
#include <iomanip>

// Функція для генерації випадкового числа в заданому діапазоні
double generateRandomBalance(double min, double max) {
    static std::random_device rd;  // Джерело випадкових чисел
    static std::mt19937 gen(rd()); // Генератор Mersenne Twister
    std::uniform_real_distribution<> dis(min, max); // Рівномірний розподіл
    return dis(gen);
}

// Функція для відображення меню
void displayMenu() {
    std::cout << "\n============================\n";
    std::cout << "Menu:\n";
    std::cout << "1. Use Vector\n";
    std::cout << "2. Use List\n";
    std::cout << "3. Use Deque\n";
    std::cout << "4. Use Set\n";
    std::cout << "5. Use Multiset\n";
    std::cout << "6. Use Map\n";
    std::cout << "7. Use Multimap\n";
    std::cout << "8. Use Stack\n";
    std::cout << "9. Use Queue\n";
    std::cout << "10. Use Priority Queue\n";
    std::cout << "11. Exit\n";
    std::cout << "============================\n";
    std::cout << "Choose an option (1-11): ";
}

// Основна програма
int main() {
    int choice;

    // Створення абонентів з випадковими балансами
    BasicSubscriber basic1("Viktor", "1234567890", generateRandomBalance(50.0, 500.0));
    BasicSubscriber basic2("Vitalik", "0987654321", generateRandomBalance(50.0, 500.0));
    PremiumSubscriber premium1("Andriy", "5678901234", generateRandomBalance(50.0, 500.0));
    PremiumSubscriber premium2("Volodymyr", "4321098765", generateRandomBalance(50.0, 500.0));

    // Контейнери для роботи
    std::vector<Subscriber*> vecSubscribers;
    std::list<Subscriber*> listSubscribers;
    std::deque<Subscriber*> dequeSubscribers;
    std::set<std::string> subscriberNames;
    std::multiset<std::string> multiSubscriberNames;
    std::map<std::string, double> subscriberBalances;
    std::multimap<std::string, double> multiSubscriberBalances;
    std::stack<Subscriber*> subscriberStack;
    std::queue<Subscriber*> subscriberQueue;
    std::priority_queue<double> balancePriorityQueue;

    while (true) {
        displayMenu();
        std::cin >> choice;

        std::cout << "\n"; // Додано пустий рядок перед виводом

        switch (choice) {
        case 1: {
            // Використання vector
            vecSubscribers.push_back(&basic1);
            vecSubscribers.push_back(&premium1);

            std::cout << "Vector contents:\n";
            for (const auto& subscriber : vecSubscribers) {
                subscriber->printDetails();
            }

            std::cout << "\nSorting Vector by balance...\n";

            // Сортування та повторний вивід
            std::sort(vecSubscribers.begin(), vecSubscribers.end(),
                [](Subscriber* a, Subscriber* b) {
                    return a->getBalance() < b->getBalance(); // Сортування за балансом
                });

            std::cout << "After sorting by balance:\n";
            for (const auto& subscriber : vecSubscribers) {
                subscriber->printDetails();
            }

            std::cout << "\nSearching for first subscriber with balance > 150...\n";
            auto found = std::find_if(vecSubscribers.begin(), vecSubscribers.end(),
                [](Subscriber* s) { return s->getBalance() > 150.0; }); // Пошук балансу > 150
            if (found != vecSubscribers.end()) {
                std::cout << "Found subscriber:\n";
                (*found)->printDetails();
            }
            else {
                std::cout << "No subscriber with balance > 150.\n";
            }
            break;
        }

        case 2: {
            // Використання list
            listSubscribers.push_back(&basic2);
            listSubscribers.push_front(&premium2);

            std::cout << "List contents:\n";
            for (const auto& subscriber : listSubscribers) {
                subscriber->printDetails();
            }

            std::cout << "\nRemoving the first element from the list...\n";
            listSubscribers.pop_front();

            std::cout << "After popping front:\n";
            for (const auto& subscriber : listSubscribers) {
                subscriber->printDetails();
            }
            break;
        }

        case 3: {
            // Використання deque
            dequeSubscribers.push_back(&basic1);
            dequeSubscribers.push_front(&premium1);

            std::cout << "Deque contents:\n";
            for (const auto& subscriber : dequeSubscribers) {
                subscriber->printDetails();
            }

            std::cout << "\nRemoving the last element from the deque...\n";
            dequeSubscribers.pop_back();

            std::cout << "After popping back:\n";
            for (const auto& subscriber : dequeSubscribers) {
                subscriber->printDetails();
            }
            break;
        }

        case 4: {
            // Використання set
            subscriberNames.insert("Viktor");
            subscriberNames.insert("Andriy");
            subscriberNames.insert("Viktor"); // Duplicate, не буде додано

            std::cout << "Set contents:\n";
            for (const auto& name : subscriberNames) {
                std::cout << name << "\n";
            }
            break;
        }

        case 5: {
            // Використання multiset
            multiSubscriberNames.insert("Vitalik");
            multiSubscriberNames.insert("Volodymyr");
            multiSubscriberNames.insert("Vitalik"); // Duplicate, буде додано

            std::cout << "Multiset contents:\n";
            for (const auto& name : multiSubscriberNames) {
                std::cout << name << "\n";
            }
            break;
        }

        case 6: {
            // Використання map
            subscriberBalances["Viktor"] = basic1[0];
            subscriberBalances["Andriy"] = premium1[0];

            std::cout << "Map contents:\n";
            for (const auto& pair : subscriberBalances) {
                std::cout << pair.first << ": $" << pair.second << "\n";
            }
            break;
        }

        case 7: {
            // Використання multimap
            multiSubscriberBalances.insert({ "Vitalik", basic2[0] });
            multiSubscriberBalances.insert({ "Volodymyr", premium2[0] });
            multiSubscriberBalances.insert({ "Vitalik", 175.0 }); // Duplicate key

            std::cout << "Multimap contents:\n";
            for (const auto& pair : multiSubscriberBalances) {
                std::cout << pair.first << ": $" << pair.second << "\n";
            }
            break;
        }

        case 8: {
            // Використання stack
            subscriberStack.push(&basic1);
            subscriberStack.push(&premium1);

            std::cout << "Stack contents:\n";
            while (!subscriberStack.empty()) {
                subscriberStack.top()->printDetails();
                subscriberStack.pop();
            }
            break;
        }

        case 9: {
            // Використання queue
            subscriberQueue.push(&basic2);
            subscriberQueue.push(&premium2);

            std::cout << "Queue contents:\n";
            while (!subscriberQueue.empty()) {
                subscriberQueue.front()->printDetails();
                subscriberQueue.pop();
            }
            break;
        }

        case 10: {
            // Використання priority_queue
            balancePriorityQueue.push(basic1[0]);
            balancePriorityQueue.push(premium1[0]);
            balancePriorityQueue.push(basic2[0]);

            std::cout << "Priority Queue contents:\n";
            while (!balancePriorityQueue.empty()) {
                std::cout << "Balance: $" << balancePriorityQueue.top() << "\n";
                balancePriorityQueue.pop();
            }
            break;
        }

        case 11: {
            std::cout << "Exiting...\n";
            return 0;
        }

        default:
            std::cout << "Invalid choice. Try again.\n";
        }

        std::cout << "\n============================\n"; // Додано роздільник між ітераціями меню
    }
}
