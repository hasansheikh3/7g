#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../../includes/ipv4.h"
#include "SplitCIDR.h"
#include "SplitIP.h"


std::string IPV4::convertCIDRToSubnet(std::string ip)
{
    // Split IP Address into IP and CIDR
    std::vector<std::string> ipCIDR = splitCIDR(ip);

    // Save the CIDR value
    int cidr = std::stoi(ipCIDR[1]);

    // Create a 32 Bit Binary String of 1's
    std::string binaryString = "";
    for (int i = 0; i < 32; i++)
    {
        binaryString += "1";
    }

    // Calculate the number of 1's to be replaced with 0's
    int numberOfOnes = 32 - cidr;

    // Replace the 1's with 0's from the right
    for (int i = 0; i < numberOfOnes; i++)
    {
        binaryString[binaryString.size() - 1 - i] = '0';
    }

    // Convert the Binary String to Decimal
    std::vector<std::string> octets;
    for (int i = 0; i < 4; i++)
    {
        std::string octet = binaryString.substr(i * 8, 8);
        octets.push_back(std::to_string(std::stoi(octet, 0, 2)));
    }

    // Return the Subnet Mask
    return octets[0] + "." + octets[1] + "." + octets[2] + "." + octets[3];

    
}