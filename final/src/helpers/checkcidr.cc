#include "checkcidr.h"


bool checkCIDRORSubnet(std::string ip)
{




    // Check if CIDR is present in the IP Address
    if (ip.find("/") != std::string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }

}