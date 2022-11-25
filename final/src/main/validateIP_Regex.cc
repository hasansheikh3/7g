#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <bits/stdc++.h>

// Create a C++ Program to validate the IP address using Regular Expression

bool validateIP(std::string ip)
{
   // Validate IP address using regex
    std::regex pattern("^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\."
                         "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\."
                         "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\."
                         "([01]?\\d\\d?|2[0-4]\\d|25[0-5])$");

    // Validate CIDR using regex
    std::regex pattern2("^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\."
                         "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\."
                         "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\."
                         "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\/(3[0-2]|[1-2]?\\d)$");

    // return true if IP address is valid and CIDR is valid
    return (std::regex_match(ip, pattern) || std::regex_match(ip, pattern2));

  
}

int main()
{
    std::cout << "Enter IP address: "; 
    std::string ip;
    std::cin >> ip;
    if (validateIP(ip))
    {
        std::cout << "Valid IP address" << std::endl;
    }
    else
    {
        std::cout << "Invalid IP address" << std::endl;
    }
    return 0;
}