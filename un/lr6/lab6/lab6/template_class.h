#ifndef TEMPLATE_CLASS_H
#define TEMPLATE_CLASS_H

#include <iostream>

// Шаблонний клас
template <typename T1, typename T2, typename T3, typename T4, typename T5>
class TemplateClass {
private:
    T1 value1;
    T2 value2;
    T3 value3;
    T4 value4;
    T5 value5;

public:
    // Конструктор
    TemplateClass(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5)
        : value1(v1), value2(v2), value3(v3), value4(v4), value5(v5) {}

    // Методи
    void printValues() const {
        std::cout << "Values: " << value1 << ", " << value2 << ", "
            << value3 << ", " << value4 << ", " << value5 << "\n";
    }

    T1 sumValues() const {
        return value1 + value2 + value3 + value4 + value5;
    }

    void setValues(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5) {
        value1 = v1;
        value2 = v2;
        value3 = v3;
        value4 = v4;
        value5 = v5;
    }
};

#endif // TEMPLATE_CLASS_H
