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
     // SPlit the given IP Address into ip and CIDR using substring
    std::string ipAddr = ip.substr(0, ip.find("/"));
    std::string cidr = ip.substr(ip.find("/") + 1, ip.length());

    // Check#1 : SPlit IP Address into 4 octets
    std::vector <std::string> octets;
    std::stringstream ss(ipAddr);
    std::string octet;
    while(std::getline(ss, octet, '.'))
    {
        octets.push_back(octet);
    }


   

    // Check#2 : Check if IP Address has 4 octets
    if(octets.size() != 4)
    {
        return false;
    }
    

    // Check#3 : Check if each octet is a number
    for(int i = 0; i < octets.size(); i++)
    {
        for(int j = 0; j < octets[i].length(); j++)
        {
            if(!isdigit(octets[i][j]))
            {
                return false;
            }
        }
    }

    // Check#4 : Check if each octet is between 0 and 255
    for(int i = 0; i < octets.size(); i++)
    {
        if(std::stoi(octets[i]) < 0 || std::stoi(octets[i]) > 255)
        {
            return false;
        }
    }

    // Check if CIDR is valid
    if(ip.find("/") != std::string::npos)
    {
        std::string cidr = ip.substr(ip.find("/") + 1);
        if(std::stoi(cidr) < 0 || std::stoi(cidr) > 32)
        {
            return false;
        }
    }

    return true;

}