#include "../includes/ipv4.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <cmath>

// Define Constructors
IPV4::IPV4()
{
    this->ip = "0.0.0.0/0";
    this->subnetMask = "0.0.0.0/0";
}

// Constructor with IP Address
IPV4::IPV4(std::string ip)
{
    this->ip = ip;
    this->subnetMask = "0.0.0.0/0";
}

// Constructor with IP Address and Subnet Mask
IPV4::IPV4(std::string ip, std::string subnetMask)
{
    this->ip = ip;
    this->subnetMask = subnetMask;
}

// Define Setters
//Check if IP Address is valid and then set it to the private variable
void IPV4::setIPV4(std::string ip)
{
    if(validateIPV4(ip))
    {
        this->ip = ip;
        std::cout << "IP Address set successfully" << std::endl;
    }
    else
    {
        std::cout << "Invalid IP Address" << std::endl;
    }
}

// Check if Subnet Mask is valid and then set it to the private variable
void IPV4::setSubnetMask(std::string subnetMask)
{
    if(validateIPV4(subnetMask))
    {
        this->subnetMask = subnetMask;
        
    }
    else
    {
        std::cout << "Invalid Subnet Mask" << std::endl;
    }
}

// Define Getters
// Return IP Address
std::string IPV4::getIPV4()
{
    return this->ip;
}

// Return Subnet Mask
std::string IPV4::getSubnetMask()
{
    return this->subnetMask;
}
