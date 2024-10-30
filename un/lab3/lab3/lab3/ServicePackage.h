#ifndef SERVICEPACKAGE_H
#define SERVICEPACKAGE_H

#include <string>

class ServicePackage {
private:
    std::string packageName;
    bool mobileInternet;
    bool sms;
    bool internationalCalls;

public:
    ServicePackage();
    ServicePackage(const std::string& name, bool internet, bool sms, bool internationalCalls);
    ServicePackage(const ServicePackage& other);

    void setPackageName(const std::string& name);
    std::string getPackageName() const;

    void enableInternet();
    void disableInternet();
    void enableSMS();
    void disableSMS();
    void enableInternationalCalls();
    void disableInternationalCalls();
};

#endif // SERVICEPACKAGE_H
