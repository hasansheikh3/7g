#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../helpers/SplitIP.h"
#include "../helpers/SplitCIDR.h"
#include "../../includes/ipv4.h"

bool IPV4::validateIPV4(std::string ip)
{
    // Split IP Address into IP and CIDR
    std::vector<std::string> ipCIDR = splitCIDR(ip);

    // Save the IP Address and CIDR into their own variables
    std::string ipAddress = ipCIDR[0];
    int cidr = std::stoi(ipCIDR[1]);

    // Split IP Address into 4 octets
    std::vector<std::string> octets = splitIP(ipAddress);

    // Check if there are 4 octets
    if (octets.size() != 4)
    {
        return false;
    }

    // Check if each octet is between 0 and 255
    for (int i = 0; i < 4; i++)
    {
        int octet = std::stoi(octets[i]);
        if (octet < 0 || octet > 255)
        {
            return false;
        }
    }

    // Check if each octet is a number
    for (int i = 0; i < 4; i++)
    {
        if (!std::all_of(octets[i].begin(), octets[i].end(), ::isdigit))
        {
            return false;
        }
    }

    // Check if first character of each octet is not 0
    for (int i = 0; i < 4; i++)
    {
        if (octets[i][0] == '0')
        {
            return false;
        }
    }

    // Check if CIDR is between 0 and 32
    if (cidr < 0 || cidr > 32)
    {
        return false;
    }

    // Check if CIDR is a number
    if (!std::all_of(ipCIDR[1].begin(), ipCIDR[1].end(), ::isdigit))
    {
        return false;
    }

    return true;

}