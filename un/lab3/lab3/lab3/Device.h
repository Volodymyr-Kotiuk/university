#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
private:
    std::string deviceType;
    std::string deviceNumber;

public:
    Device();
    Device(const std::string& type, const std::string& number);
    Device(const Device& other);

    void setDeviceType(const std::string& type);
    std::string getDeviceType() const;

    void setDeviceNumber(const std::string& number);
    std::string getDeviceNumber() const;
};

#endif // DEVICE_H
