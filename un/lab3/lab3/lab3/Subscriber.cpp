#include "Subscriber.h"

// Ініціалізація статичної змінної
int Subscriber::totalSubscribers = 0;

// Конструктори
Subscriber::Subscriber()
    : subscriberID(0), name("Unknown"), balance(0.0), phoneNumber("0000000"), status("active") {
    totalSubscribers++;
    generateRandomPhoneNumber();
    allocateAndSortRandomNumbers();
}

Subscriber::Subscriber(int id, const std::string& name, double balance, const std::string& phoneNumber, const std::string& status)
    : subscriberID(id), name(name), balance(balance), phoneNumber(phoneNumber), status(status) {
    totalSubscribers++;
    if (phoneNumber.empty()) {
        generateRandomPhoneNumber(); // Генерація випадкового номера
    }
    allocateAndSortRandomNumbers();
}

Subscriber::Subscriber(const Subscriber& other)
    : subscriberID(other.subscriberID), name(other.name), balance(other.balance),
    phoneNumber(other.phoneNumber), status(other.status), services(other.services), randomNumbers(other.randomNumbers) {
    totalSubscribers++;
}

// Деструктор
Subscriber::~Subscriber() {
    totalSubscribers--;
}

// Генерація випадкового номера телефону
void Subscriber::generateRandomPhoneNumber() {
    phoneNumber = std::to_string(rand() % 9000000 + 1000000); // Генерація випадкового 7-значного номера
}

// Відсортувати випадкові числа
void Subscriber::allocateAndSortRandomNumbers() {
    randomNumbers.resize(7); // Вектор для 7 чисел
    for (int& number : randomNumbers) {
        number = rand() % 101; // Випадкові числа від 0 до 100
    }
    std::sort(randomNumbers.begin(), randomNumbers.end());
}

// Відображення інформації про підписника
void Subscriber::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Service Package: Premium" << std::endl;
    std::cout << "Invoice Amount: " << balance << std::endl;
    std::cout << "Device Type: Mobile" << std::endl;
    std::cout << "Random Numbers: ";
    for (size_t i = 0; i < randomNumbers.size(); ++i) {
        std::cout << randomNumbers[i];
        if (i < randomNumbers.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Connection Status: " << status << std::endl;
}

// Геттери та сеттери
int Subscriber::getSubscriberID() const { return subscriberID; }
std::string Subscriber::getName() const { return name; }
void Subscriber::setBalance(double newBalance) { balance = newBalance; }
double Subscriber::getBalance() const { return balance; }

// Додати послуги
void Subscriber::addService(const std::string& service) {
    services.push_back(service);
}

void Subscriber::addService(const std::string& service, double serviceCost) {
    services.push_back(service);
    balance -= serviceCost;
}

// Статичні методи
int Subscriber::getTotalSubscribers() {
    return totalSubscribers;
}

// Запис даних підписника у файл
void Subscriber::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << subscriberID << " " << name << " " << balance << " " << phoneNumber << " " << status << "\n";
        file.close();
    }
}

// Читання даних підписника з файлу
void Subscriber::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> subscriberID >> name >> balance >> phoneNumber >> status;
        file.close();
    }
}

// Функція, що приймає об'єкт Subscriber і відображає його баланс
void displaySubscriberBalance(const Subscriber& subscriber) {
    std::cout << "Subscriber ID: " << subscriber.getSubscriberID()
        << " has a balance of " << subscriber.getBalance() << std::endl;
}

// Функція, що повертає об'єкт Subscriber
Subscriber createSubscriber(int id, const std::string& name, double balance) {
    return Subscriber(id, name, balance, "", "Active");
}
