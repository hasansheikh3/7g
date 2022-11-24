#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "SplitCIDR.h"

std::vector<std::string> splitCIDR(std::string ip)
{
    std::vector<std::string> octets;
    std::stringstream ss(ip);
    std::string temp;

    while (getline(ss, temp, '/'))
    {
        octets.push_back(temp);
    }

    return octets;
}