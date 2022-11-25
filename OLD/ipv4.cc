#include "ipv4.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <cmath>

// Define Constructors
IPV4::IPV4()
{
    this->ip = "0.0.0.0/0";
    this->subnetMask = "0.0.0.0/0";
}

// Constructor with IP Address
IPV4::IPV4(std::string ip)
{
    this->ip = ip;
    this->subnetMask = "0.0.0.0/0";
}

// Constructor with IP Address and Subnet Mask
IPV4::IPV4(std::string ip, std::string subnetMask)
{
    this->ip = ip;
    this->subnetMask = subnetMask;
}

// Define Setters
//Check if IP Address is valid and then set it to the private variable
void IPV4::setIPV4(std::string ip)
{
    if(validateIPV4(ip))
    {
        this->ip = ip;
        std::cout << "IP Address set successfully" << std::endl;
    }
    else
    {
        std::cout << "Invalid IP Address" << std::endl;
    }
}

// Check if Subnet Mask is valid and then set it to the private variable
void IPV4::setSubnetMask(std::string subnetMask)
{
    if(validateIPV4(subnetMask))
    {
        this->subnetMask = subnetMask;
        std::cout << "Subnet Mask set successfully" << std::endl;
    }
    else
    {
        std::cout << "Invalid Subnet Mask" << std::endl;
    }
}

// Define Getters
// Return IP Address
std::string IPV4::getIPV4()
{
    return this->ip;
}

// Return Subnet Mask
std::string IPV4::getSubnetMask()
{
    return this->subnetMask;
}

// Define Static Functions
// COnvert CIDR to Subnet Mask

// Validate IP Address
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

    /*
      std::cout << "Octets : " << std::endl;
      for (int i = 0; i < octets.size(); i++)
    {
        std::cout << octets[i] << std::endl;
        // Print Octets length
        std::cout << "Octet Length : " << octets[i].length() << std::endl;
    }

    // Print Octets size
    std::cout << "Octets Size : " << octets.size() << std::endl; // 4

    // Print Octet[0][0]
    std::cout << "Octet[0][0] : " << octets[0][0] << std::endl; // 1

    
    */
}

// Convert CIDR To Subnet Mask
std::string IPV4::convertCIDRToSubnet(std::string ip)
{

    // SPlit the given IP Address into ip and CIDR using substring
    std::string ipAddr = ip.substr(0, ip.find("/"));
    std::string cidr = ip.substr(ip.find("/") + 1, ip.length());

    // Convert CIDR to Integer
    int cidrInt = std::stoi(cidr);

    // Convert CIDR to Binary
    std::string binary = "";
    for(int i = 0; i < cidrInt; i++)
    {
        binary += "1";
    }
    for(int i = 0; i < 32 - cidrInt; i++)
    {
        binary += "0";
    }

    // Print Binary
    std::cout << "Binary : " << binary << std::endl;

    // Convert Binary to Subnet Mask
    std::string subnetMask = "";
    for(int i = 0; i < 4; i++)
    {
        std::string octet = binary.substr(i * 8, 8);
        // std::cout << "Octet : " << octet << "at "<< i << std::endl;

        int octetInt = std::stoi(octet, 0, 2);
        // std::cout << "Octet Int : " << octetInt << std::endl;

        subnetMask += std::to_string(octetInt);
        if(i != 3)
        {
            subnetMask += ".";
        }
    }

    

    return subnetMask;
}

// get the Network Range
std::vector<std::string> IPV4::generateNetworkRange()
{

    // Get the values of IP Address and Subnet Mask
    std::string ipAddr_cidr = getIPV4();
    std::string subnetMask_cidr = getSubnetMask();

    // SPlit the given IP Address into ip and CIDR using substring
    std::string ipAddr = ipAddr_cidr.substr(0, ipAddr_cidr.find("/"));

    //Find the IP Range by ANDing the IP Address and Subnet Mask
    std::vector <std::string> ipAddrOctets;
    std::stringstream ss(ipAddr);
    std::string octet;
    while(std::getline(ss, octet, '.'))
    {
        ipAddrOctets.push_back(octet);
    }

    std::vector <std::string> subnetMaskOctets;
    std::stringstream ss2(subnetMask_cidr);
    std::string octet2;
    while(std::getline(ss2, octet2, '.'))
    {
        subnetMaskOctets.push_back(octet2);
    }

    std::vector<std::string> networkRange;
    for(int i = 0; i < 4; i++)
    {
        int ipAddrOctet = std::stoi(ipAddrOctets[i]);
        int subnetMaskOctet = std::stoi(subnetMaskOctets[i]);
        int networkRangeOctet = ipAddrOctet & subnetMaskOctet;
        networkRange.push_back(std::to_string(networkRangeOctet));
    }

    // get the first and last IP Address in the Network Range
    std::string firstIP = networkRange[0] + "." + networkRange[1] + "." + networkRange[2] + "." + "1";
    std::string lastIP = networkRange[0] + "." + networkRange[1] + "." + networkRange[2] + "." + "254";

    // Wrap the first and last IP Address in a vector
    std::vector <std::string> networkRangeIPs;
    networkRangeIPs.push_back(firstIP);
    networkRangeIPs.push_back(lastIP);

    return networkRangeIPs;
   
}

// Generate the User Defined Network Range IP Addresses
std::vector<std::string> IPV4::generateRange(std::string ip, int range)
{
    // First get the Network Range
    std::vector<std::string> networkRange = generateNetworkRange();

    // Get the first and last IP Address in the Network Range
    std::string firstIP = networkRange[0];
    std::string lastIP = networkRange[1];

    // Add the user defined range to the first IP Address in the Network Range
    std::vector <std::string> firstIPOctets;
    std::stringstream ss(firstIP);
    std::string octet;
    while(std::getline(ss, octet, '.'))
    {
        firstIPOctets.push_back(octet);
    }

    int firstIPOctet = std::stoi(firstIPOctets[3]);
    int lastIPOctet = firstIPOctet + range;

    // check if the generated range is not greater than the last IP Address in the Network Range
    std::vector <std::string> lastIPOctets;
    std::stringstream ss2(lastIP);
    std::string octet2;
    while(std::getline(ss2, octet2, '.'))
    {
        lastIPOctets.push_back(octet2);
    }

    int lastIPOctet2 = std::stoi(lastIPOctets[3]);
    if(lastIPOctet > lastIPOctet2)
    {
        std::cout << "The range is too large for the given IP Address" << std::endl;
        exit(0);
    }

    // Generate the IP Addresses in the range
    std::vector<std::string> rangeIPs;
    for(int i = firstIPOctet; i < lastIPOctet; i++)
    {
        std::string rangeIP = firstIPOctets[0] + "." + firstIPOctets[1] + "." + firstIPOctets[2] + "." + std::to_string(i);
        rangeIPs.push_back(rangeIP);
    }

    return rangeIPs;

}

// INcrement the IP Address by 1
std::string IPV4::operator++()
{
    // First get the Network Range
    std::vector<std::string> networkRange = generateNetworkRange();

    // Get the first and last IP Address in the Network Range
    std::string firstIP = networkRange[0];
    std::string lastIP = networkRange[1];

    // Increment the first IP Address in the Network Range by 1
    std::vector <std::string> firstIPOctets;
    std::stringstream ss(firstIP);
    std::string octet;
    while(std::getline(ss, octet, '.'))
    {
        firstIPOctets.push_back(octet);
    }

    int firstIPOctet = std::stoi(firstIPOctets[3]);
    int lastIPOctet = firstIPOctet + 1;

    // check if the generated range is not greater than the last IP Address in the Network Range
    std::vector <std::string> lastIPOctets;
    std::stringstream ss2(lastIP);
    std::string octet2;
    while(std::getline(ss2, octet2, '.'))
    {
        lastIPOctets.push_back(octet2);
    }

    int lastIPOctet2 = std::stoi(lastIPOctets[3]);
    if(lastIPOctet > lastIPOctet2)
    {
        std::cout << "The range is too large for the given IP Address" << std::endl;
        exit(0);
    }

    // Generate the IP Addresses in the range
    std::string incrementedIP = firstIPOctets[0] + "." + firstIPOctets[1] + "." + firstIPOctets[2] + "." + std::to_string(lastIPOctet);

    return incrementedIP;
}

// Decrement the IP Address by 1
std::string IPV4::operator--()
{
    // First get the Network Range
    // std::vector<std::string> networkRange = generateNetworkRange();

    // Get the first and last IP Address in the Network Range
    std::string firstIP = networkRange[0];
    std::string lastIP = networkRange[1];

    // Increment the first IP Address in the Network Range by 1
    std::vector <std::string> firstIPOctets;
    std::stringstream ss(firstIP);
    std::string octet;
    while(std::getline(ss, octet, '.'))
    {
        firstIPOctets.push_back(octet);
    }

    int firstIPOctet = std::stoi(firstIPOctets[3]);
    int lastIPOctet = firstIPOctet - 1;

    // check if the generated range is not greater than the last IP Address in the Network Range
    std::vector <std::string> lastIPOctets;
    std::stringstream ss2(lastIP);
    std::string octet2;
    while(std::getline(ss2, octet2, '.'))
    {
        lastIPOctets.push_back(octet2);
    }

    int lastIPOctet2 = std::stoi(lastIPOctets[3]);
    if(lastIPOctet < lastIPOctet2)
    {
        std::cout << "The range is too large for the given IP Address" << std::endl;
        exit(0);
    }

    // Generate the IP Addresses in the range
    std::string decrementedIP = firstIPOctets[0] + "." + firstIPOctets[1] + "." + firstIPOctets[2] + "." + std::to_string(lastIPOctet);

    return decrementedIP;
}