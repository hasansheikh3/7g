#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../../includes/ipv4.h"
#include "../helpers/SplitIP.h"
#include "../helpers/SplitCIDR.h"
#include "../helpers/networkRange.h"

// INcrement the IP Address by 1
std::string IPV4::operator++()
{
    // Get the IP Address and split CIDR into IP and CIDR
    std::vector<std::string> ipCIDR = splitCIDR(this->ip);
    std::string ip = ipCIDR[0];
    std::string cidr = ipCIDR[1];

    // Get the number of possible hosts by subtracting CIDR from 32
    int hosts = networkRange(this->ip);

    // SUbtract 2 from hosts because we need to exclude the network address and the broadcast address
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

    // Check if the number of hosts allows us to increment the last octet by 1
    if(hosts >= 0)
    {
        // Increment the last octet by 1
        lastOctet += 1;

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
        // If the number of hosts does not allow us to increment the last octet by 1, then we need to increment the second last octet by 1
        int secondLastOctet = std::stoi(octets[2]);

        // Increment the second last octet by 1
        secondLastOctet += 1;

        // Convert the second last octet back to string
        octets[2] = std::to_string(secondLastOctet);

        // Set the last octet to 0
        octets[3] = "0";

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
}
