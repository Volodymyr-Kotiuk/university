#include "ServicePackage.h"

ServicePackage::ServicePackage() : packageName("Basic"), mobileInternet(false), sms(false), internationalCalls(false) {}

ServicePackage::ServicePackage(const std::string& name, bool internet, bool sms, bool internationalCalls)
    : packageName(name), mobileInternet(internet), sms(sms), internationalCalls(internationalCalls) {}

ServicePackage::ServicePackage(const ServicePackage& other)
    : packageName(other.packageName), mobileInternet(other.mobileInternet), sms(other.sms), internationalCalls(other.internationalCalls) {}

void ServicePackage::setPackageName(const std::string& name) { packageName = name; }
std::string ServicePackage::getPackageName() const { return packageName; }

void ServicePackage::enableInternet() { mobileInternet = true; }
void ServicePackage::disableInternet() { mobileInternet = false; }
void ServicePackage::enableSMS() { sms = true; }
void ServicePackage::disableSMS() { sms = false; }
void ServicePackage::enableInternationalCalls() { internationalCalls = true; }
void ServicePackage::disableInternationalCalls() { internationalCalls = false; }
