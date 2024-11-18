#include "subscriber.h"
#include "premium_subscriber.h"
#include "billing_and_support.h"
#include <iostream>
#include <vector>
#include <cstdlib> // ��� ������� rand()

int main() {
    // ����� ��'���� � �������� ���'��
    Subscriber staticSubscribers[5] = {
        Subscriber("Andriy", "123456", "Silver", 50.0, ConnectionStatus::Active, "Andriy@gmail.com", "Khmelnitsky, Ukraine", 100.0, std::time(nullptr)),
        Subscriber("Viktor", "234567", "Gold", 75.0, ConnectionStatus::Active, "Viktor@gmail.com", "Khmelnitsky, Ukraine", 100.0, std::time(nullptr)),
        Subscriber("Vitalik", "345678", "Basic", 30.0, ConnectionStatus::TemporarilyDisconnected, "Vitalik@gmail.com", "Khmelnitsky, Ukraine", 100.0, std::time(nullptr)),
        Subscriber("Vlad", "456789", "Platinum", 100.0, ConnectionStatus::Blocked, "Vlad@gmail.com", "Khmelnitsky, Ukraine", 100.0, std::time(nullptr)),
        Subscriber("Volodymyr", "567890", "Silver", 55.0, ConnectionStatus::Active, "Volodymyr@gmail.com", "Khmelnitsky, Ukraine", 100.0, std::time(nullptr))
    };

    // ������ � ���������� ��'������
    std::cout << "Static Subscribers:\n";
    for (int i = 0; i < 5; ++i) {
        staticSubscribers[i].printDetails();
        staticSubscribers[i].saveToFile("static_subscribers.txt");
    }

    // ��������� ��������� ���������
    Subscriber* dynamicSubscribers[5];
    for (int i = 0; i < 5; ++i) {
        dynamicSubscribers[i] = new Subscriber(
            "DynamicSub" + std::to_string(i + 1),                  // ��'�
            " " + std::to_string(100000 + rand() % 900000),       // ����� ��������
            (i % 2 == 0 ? "Gold" : "Silver"),                     // ����� ������ (����������)
            50.0 + (i * 10),                                      // ������� (������ � ������ ���������)
            (i % 3 == 0 ? ConnectionStatus::Active :              // ������ ����������
                i % 3 == 1 ? ConnectionStatus::TemporarilyDisconnected :
                ConnectionStatus::Blocked),
            "dynamic" + std::to_string(i + 1) + "@gmail.com",   // Email
            "City, Ukraine",                               // Address
            50.0 + (i * 5),                                       // ���� ���������� �������
            std::time(nullptr)                                    // ���� ���������� �������
        );
    }

    // ������ � ���������� ��'������
    std::cout << "\nDynamic Subscribers:\n";
    for (int i = 0; i < 5; ++i) {
        dynamicSubscribers[i]->printDetails();
        dynamicSubscribers[i]->saveToFile("dynamic_subscribers.txt");
    }

    // ��������� ��'���� �� �������� ���'��
    for (int i = 0; i < 5; ++i) {
        delete dynamicSubscribers[i];
    }

    // PremiumSubscriber
    PremiumSubscriber premiumSub("PremSub", "654321", "Platinum", 120.0, ConnectionStatus::Active,
        "PremSub@gmail.com", "kyiv, Ukraine", 200.0, std::time(nullptr),
        "VIP Rewards");
    premiumSub.showLoyaltyDetails();

    // MultiServiceSubscriber
    MultiServiceSubscriber multiSub("MultiServSub", "567890", "Gold", 90.0, ConnectionStatus::Active,
        "MultiServSub@gmail.com", "kyiv, Ukraine", 150.0, std::time(nullptr),
        150.0, "+380 44 123 4567");
    multiSub.showFullInfo();

    return 0;
}
