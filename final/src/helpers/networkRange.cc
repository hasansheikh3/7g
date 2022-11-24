#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "SplitCIDR.h"
#include "SplitIP.h"

int networkRange(std::string ip)
{
    // Get the CIDR value
    std::vector<std::string> cidr = splitCIDR(ip);

    // Save the CIDR value
    int cidrValue = std::stoi(cidr[1]);

    // Subtract the CIDR value from 32
    int range = 32 - cidrValue;

    // Return the range
    return range;
}