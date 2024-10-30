#include "Device.h"

Device::Device() : deviceType("Unknown"), deviceNumber("0000") {}

Device::Device(const std::string& type, const std::string& number) : deviceType(type), deviceNumber(number) {}

Device::Device(const Device& other) : deviceType(other.deviceType), deviceNumber(other.deviceNumber) {}

void Device::setDeviceType(const std::string& type) { deviceType = type; }
std::string Device::getDeviceType() const { return deviceType; }

void Device::setDeviceNumber(const std::string& number) { deviceNumber = number; }
std::string Device::getDeviceNumber() const { return deviceNumber; }
