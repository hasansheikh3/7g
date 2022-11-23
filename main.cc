#include "ipv4.h"
#include <iostream>
#include <string>

int main()
{
    std::string ip;
    std::cout << "Please enter IP Address: " << std::endl;
    std::cin >> ip;

    IPV4 ipv4;
    ipv4.setIPV4(ip);

    std::cout << "IP Address: " << ipv4.getIPV4() << std::endl;
    std::string subnet = ipv4.convertCIDRToSubnet(ip);
    std::cout << "Subnet Mask: " << subnet << std::endl;
    
    // Set Subnet Mask
    ipv4.setSubnetMask(subnet);

    std::cout << "Subnet Mask: " << ipv4.getSubnetMask() << std::endl;

    // Generate Network Range
    std::vector<std::string> range = ipv4.generateNetworkRange();
    std::cout << "Network Range: " << range[0] << " - " << range[1] << std::endl;



    std::vector <std::string> IPrange = ipv4.generateRange(ip, 10);

    for (int i = 0; i < IPrange.size(); i++)
    {
        std::cout << IPrange[i] << std::endl;
    }

    //Add the IP Address by 1 using operator overriding
    std::cout << "IP Address After adding 1: " << ++ipv4<< std::endl;

    return 0;
}
