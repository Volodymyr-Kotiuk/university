#ifndef TELEPHONE_EXCHANGE_H
#define TELEPHONE_EXCHANGE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
class TelephoneExchange {
private:
    string subscriberName; 
    string phoneNumber;     
    vector<string> servicePackages; 
    double invoiceAmount;        
    string connectionStatus; 

public:
    // �����������
    TelephoneExchange(string name, string number);

    // ����� ��������� ������ ������
    void addServicePackage(string service);

    // ����� ���� ������ ��������
    //void changePhoneNumber(string newNumber);

    // ����� ������ �������
    //void payInvoice(double amount);

    // �������������� ����� ����������� ���������� ��� ��������
    void displayInfo();
    void displayInfo(bool detailed);

    //  ����� ������ ���� ����� � ����
    void writeToFile(const string& filename);

    //  ����� ������� � �����
    void readFromFile(const string& filename);

    void allocateAndSort();

    double getInvoiceAmount() const;

};

#endif



