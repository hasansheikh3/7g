#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;


int main()
{
    string ip;
    cout << "Enter IP Address: ";
    cin >> ip;

    int iprange;
    cout << "Enter Range: ";
    cin >> iprange;

    vector<string> range = generateRange(ip,iprange);

    for (int i = 0; i < range.size(); i++)
    {
        cout << range[i] << endl;
    }
}

vector<string> generateRange(string ip,int range)
{
    // Step 1 - SPlit the IP Address and CIDR notation
    vector<string> ipAndCIDR;
    stringstream ss(ip);
    string temp;

    while (getline(ss, temp, '/'))
    {
        ipAndCIDR.push_back(temp);
    }

    // Step - 2 Create a 32 Bit Binary String of 1's
    string binaryString = "";
    for (int i = 0; i < 32; i++)
    {
        binaryString += "1";
    }

    // Step - 3 Calculate the number of 1's to be replaced with 0's
    int numberOfOnes = 32 - stoi(ipAndCIDR[1]);

    // Step - 4 Replace the 1's with 0's from the right
    for (int i = 0; i < numberOfOnes; i++)
    {
        binaryString[binaryString.size() - 1 - i] = '0';
    }

    // Step - 5 Split the IP Address into 4 octets
    vector<string> octets;
    stringstream ss2(ipAndCIDR[0]);
    string temp2;

    while (getline(ss2, temp2, '.'))
    {
        octets.push_back(temp2);
    }

    // Step - 6 Convert the octets into binary
    vector<string> binaryOctets;
    for (int i = 0; i < octets.size(); i++)
    {
        int octet = stoi(octets[i]);
        string binaryOctet = "";
        while (octet > 0)
        {
            binaryOctet += to_string(octet % 2);
            octet /= 2;
        }
        reverse(binaryOctet.begin(), binaryOctet.end());
        binaryOctets.push_back(binaryOctet);
    }

    // Step - 7 Convert the binary octets into 8 bit binary strings
    vector<string> binaryOctets8Bit;
    for (int i = 0; i < binaryOctets.size(); i++)
    {
        string binaryOctet = binaryOctets[i];
        while (binaryOctet.size() < 8)
        {
            binaryOctet = "0" + binaryOctet;
        }
        binaryOctets8Bit.push_back(binaryOctet);
    }

    // Step -9 Perform the bitwise AND operation on the binary octets and the binary string
    vector<string> binaryOctetsAND;
    for (int i = 0; i < binaryOctets8Bit.size(); i++)
    {
        string binaryOctet = binaryOctets8Bit[i];
        string binaryOctetAND = "";
        for (int j = 0; j < binaryOctet.size(); j++)
        {
            if (binaryOctet[j] == '1' && binaryString[j] == '1')
            {
                binaryOctetAND += "1";
            }
            else
            {
                binaryOctetAND += "0";
            }
        }
        binaryOctetsAND.push_back(binaryOctetAND);
    }

    // Step - 10 Convert the binary octets into decimal
    vector<int> decimalOctets;
    for (int i = 0; i < binaryOctetsAND.size(); i++)
    {
        string binaryOctet = binaryOctetsAND[i];
        int decimalOctet = 0;
        for (int j = 0; j < binaryOctet.size(); j++)
        {
            if (binaryOctet[j] == '1')
            {
                decimalOctet += pow(2, binaryOctet.size() - 1 - j);
            }
        }
        decimalOctets.push_back(decimalOctet);
    }

   

    // Step - 11 Convert the decimal octets into IP Address
    string ipAddress = "";
    for (int i = 0; i < decimalOctets.size(); i++)
    {
        ipAddress += to_string(decimalOctets[i]);
        if (i != decimalOctets.size() - 1)
        {
            ipAddress += ".";
        }
    }

    // Step - 12 Calculate the number of IP Addresses in the range
    int numberOfIPAddresses = pow(2, numberOfOnes);

    // Step - 13 Create a vector of IP Addresses
    vector<string> ipAddresses;
    ipAddresses.push_back(ipAddress);
    for (int i = 1; i < numberOfIPAddresses; i++)
    {
        int lastOctet = decimalOctets[decimalOctets.size() - 1];
        lastOctet++;
        decimalOctets[decimalOctets.size() - 1] = lastOctet;
        for (int j = decimalOctets.size() - 1; j > 0; j--)
        {
            if (decimalOctets[j] == 256)
            {
                decimalOctets[j] = 0;
                decimalOctets[j - 1]++;
            }
        }
        string ipAddress = "";
        for (int k = 0; k < decimalOctets.size(); k++)
        {
            ipAddress += to_string(decimalOctets[k]);
            if (k != decimalOctets.size() - 1)
            {
                ipAddress += ".";
            }
        }
        ipAddresses.push_back(ipAddress);
    }

    // Print the possible number of IP Addresses based on the CIDR Notation
    cout << "Number of IP Addresses: " << numberOfIPAddresses << endl;

    // Check if the range entered is valid
    if (range > numberOfIPAddresses)
    {
        cout << "Invalid Range" << endl;
        exit(0);
    }



    return ipAddresses;


    

    // Print the Subnet Mask
    // cout << "Subnet Mask: " << subnetMask << endl;
}
