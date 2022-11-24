// Split IP Address into 4 octets
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "SplitIP.h"

std::vector<std::string> splitIP(std::string ip)
{
    std::vector<std::string> octets;
    std::stringstream ss(ip);
    std::string temp;

    while (getline(ss, temp, '.'))
    {
        octets.push_back(temp);
    }

    return octets;
}