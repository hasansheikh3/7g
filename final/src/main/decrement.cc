// Decrement IP Address by 1
// Same as increment IP Address by 1, but instead of adding 1, we subtract 1.
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../../includes/ipv4.h"
#include "../helpers/SplitIP.h"
#include "../helpers/SplitCIDR.h"
#include "../helpers/networkRange.h"

std::string IPV4::operator--()
{
    // Get the IP Address and split CIDR into IP and CIDR
    std::vector<std::string> ipCIDR = splitCIDR(this->ip);
    std::string ip = ipCIDR[0];
    std::string cidr = ipCIDR[1];

    // Get the number of possible hosts by subtracting CIDR from 32
    int hosts = networkRange(this->ip);

    // Subtract 2 from hosts because we need to exclude the network address and the broadcast address
    hosts -= 2;

    // Split the IP Address into 4 octets
    std::vector <std::string> octets;
    std::stringstream ss(ip);
    std::string octet;
    while(std::getline(ss, octet, '.'))
    {
        octets.push_back(octet);
    }

    // Convert the last octet to integer
    int lastOctet = std::stoi(octets[3]);

    // Check if the number of hosts allows us to decrement the last octet by 1
    if(hosts >= 0)
    {
        // Decrement the last octet by 1
        lastOctet -= 1;

        // Convert the last octet back to string
        octets[3] = std::to_string(lastOctet);

        // Join the octets back to form the IP Address
        std::string newIP = "";
        for(int i = 0; i < octets.size(); i++)
        {
            newIP += octets[i];
            if(i != octets.size() - 1)
            {
                newIP += ".";
            }
        }

        // Return the new IP Address
        return newIP;
    }
    else
    {
        return "Invalid IP Address";
    }
}