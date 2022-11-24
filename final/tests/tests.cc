// Include catch.hpp from github.com/philsquared/Catch

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../includes/ipv4.h"
#include "../src/helpers/SplitIP.cc"
#include "../src/helpers/SplitCIDR.cc"
#include "../src/main/validateIP.cc"
#include "../src/helpers/CidrToSubnet.cc"
#include "../src/main.cc"

// Test 1: Check if the IP Address is valid
TEST_CASE("Test 1: Check if the IP Address is valid", "[IPV4]")
{
    IPV4 ip;
    REQUIRE(ip.validateIPV4("198.101.10.2/24") == true);
    REQUIRE(ip.validateIPV4("257.101.10.2/24") == false);
    REQUIRE(ip.validateIPV4("256.101.10.2/33") == true);
}

// Test 2: Check if generated Subnet is valid and matches the CIDR
TEST_CASE("Test 2: Check if generated Subnet is valid and matches the CIDR", "[IPV4]")
{
    IPV4 ip;
    REQUIRE(ip.convertCIDRToSubnet("192.168.101.10/25") == "255.255.255.128");
    REQUIRE(ip.convertCIDRToSubnet("192.168.101.255/33") == "255.255.255.255");
    
}
