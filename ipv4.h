

#ifndef IPV4_H
#define IPV4_H

#include <iostream>
#include <string>
#include <vector>

class IPV4
{
private:
    std::string ip;
    std::string subnetMask;

public:

    //Define Constructors
    IPV4();   // Default Constructor
    IPV4(std::string ip);    // Constructor with IP Address
    IPV4(std::string ip, std::string subnetMask);   // Constructor with IP Address and Subnet Mask

    //Define Setters
    void setIPV4(std::string ip);    // Set IP Address
    void setSubnetMask(std::string subnetMask);    // Set Subnet Mask


    //Define Getters
    std::string getIPV4();     // Get IP Address
    std::string getSubnetMask();     // Get Subnet Mask

    //Define Static Functions
    static bool validateIPV4(std::string ip);
     std::string convertCIDRToSubnet(std::string ip);
     std::vector<std::string> generateNetworkRange();



    //Define Member Functions
    std::vector <std::string> generateRange(std::string ip, int range);

    //Add the IP Address by 1 using operator overriding
    std::string operator++();

};



#endif
