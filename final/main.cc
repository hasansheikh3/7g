#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "includes/ipv4.h"


int main()
{
    IPV4 ip1;
    std::cout << "Please enter an IP Address: ";
    std::string ip;
    std::cin >> ip;
    ip1.setIPV4(ip);

    ip1.getIPV4();

    // Return Subnet Mask from CIDR
    std::string subnet = ip1.convertCIDRToSubnet(ip);
    std::cout << "Subnet Mask: " << subnet << std::endl;

    // Return the range of IP Addresses
    std::cout << "Please Enter a Range for which you want to find the IP Addresses: ";
    int range;
    std::cin >> range;
    std::vector<std::string> ipRange = ip1.generateRange(ip, range);
    std::cout << "IP Addresses in the range: " << std::endl;
    for(int i = 0; i < ipRange.size(); i++)
    {
        std::cout << ipRange[i] << std::endl;
    }

    return 0;
}