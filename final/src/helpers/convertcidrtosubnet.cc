#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "convertcidrtosubnet.h"

int convertSubnetFromCIDR(std::string subnet)
{
    // Convert the given subnet back to CIDR notation

    // Split the subnet into 4 octets
    std::vector<std::string> octets;
    std::stringstream ss(subnet);
    std::string octet;
    while (std::getline(ss, octet, '.'))
    {
        octets.push_back(octet);
    }

    // Convert each octet to binary
    std::vector<std::string> binaryOctets;
    for (int i = 0; i < octets.size(); i++)
    {
        std::string binaryOctet;
        int octet = std::stoi(octets[i]);
        while (octet > 0)
        {
            binaryOctet += std::to_string(octet % 2);
            octet /= 2;
        }
        std::reverse(binaryOctet.begin(), binaryOctet.end());
        binaryOctets.push_back(binaryOctet);
    }

    // Convert the binary octets to CIDR notation
    std::string binarySubnet;
    for (int i = 0; i < binaryOctets.size(); i++)
    {
        binarySubnet += binaryOctets[i];
    }

    int cidr = 0;
    for (int i = 0; i < binarySubnet.size(); i++)
    {
        if (binarySubnet[i] == '1')
        {
            cidr++;
        }
    }

    return cidr;
}