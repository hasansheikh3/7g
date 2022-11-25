#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "includes/ipv4.h"
#include "src/helpers/convertcidrtosubnet.h"
#include "src/helpers/checkcidr.h"


int main()
{
   

    
    std::string ip;
    std::cout << "Please enter IP Address: " << std::endl;
    std::cin >> ip;

    IPV4 ipv4;

    ipv4.setIPV4(ip);

  
    if (checkCIDRORSubnet(ip) == true)
    {
        std::cout << "IP Address: " << ipv4.getIPV4() << std::endl;
    std::string subnet = ipv4.convertCIDRToSubnet(ip);
    

    // Generate Network Range
    // std::vector<std::string> range = ipv4.generateNetworkRange();
    // std::cout << "Network Range: " << range[0] << " - " << range[1] << std::endl;



    std::vector <std::string> IPrange = ipv4.generateRange(ip, 10);

    for (int i = 0; i < IPrange.size(); i++)
    {
        std::cout << IPrange[i] << std::endl;
    }

    //Add the IP Address by 1 using operator overriding
    std::cout << "IP Address After adding 1: " << ++ipv4<< std::endl;
    }
    else
    {
        std::cout << "CIDR is not present, do you want to enter Subnet Mask?" << std::endl;
        std::cout << "Enter Y or N" << std::endl;
        char choice;
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            std::string subnet;
            std::cout << "Please enter Subnet Mask: " << std::endl;
            std::cin >> subnet;
            ipv4.setSubnetMask(subnet);
            std::cout << "Subnet Mask: " << ipv4.getSubnetMask() << std::endl;

              int cidr = convertSubnetFromCIDR(ipv4.getSubnetMask());
                // convert int to string
                std::string cidrString = std::to_string(cidr);
                std::string ip = ipv4.getIPV4()+"/"+cidrString;

    // std::vector<std::string> range = ipv4.generateNetworkRange();
    // std::cout << "Network Range: " << range[0] << " - " << range[1] << std::endl;



    std::vector <std::string> IPrange = ipv4.generateRange(ip, 10);

    for (int i = 0; i < IPrange.size(); i++)
    {
        std::cout << IPrange[i] << std::endl;
    }

    //Add the IP Address by 1 using operator overriding
    std::cout << "IP Address After adding 1: " << ++ipv4<< std::endl;


            }
    

        else
        {
            std::cout << "Neither Subnet Mask nor CIDR is present" << std::endl;
        }
    }
    

    return 0;
}