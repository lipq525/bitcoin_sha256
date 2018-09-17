
#include <string.h>
#include<iostream>
#include <sstream>
#include "bitcoin_sha256.h"

using namespace std;

string get_sha_256(const unsigned char *data, size_t len)
{
    unsigned char buf[CSHA256::OUTPUT_SIZE];
    CSHA256().Reset().Write(data,len).Finalize(buf);
    std::stringstream  str_stream;
    char buf2[3]= {0};
    for (int i = 0; i < 32; ++i) 
    {
    memset(buf2,0,sizeof(buf2)); 
    snprintf(buf2,sizeof(buf2),"%02X",buf[i]);
    str_stream<<buf2;
    }
    string hash_result  = str_stream.str();
    return hash_result;
}

void HexStrToByte(const char* source, unsigned char* dest, int sourceLen) 
{ 
    short i; 
    unsigned char highByte, lowByte; 
    for (i = 0; i < sourceLen; i += 2) 
    { 
        highByte = toupper(source[i]); 
        lowByte = toupper(source[i + 1]); 

        if (highByte > 0x39) 
            highByte -= 0x37; 
        else 
            highByte -= 0x30; 

        if (lowByte > 0x39) 
            lowByte -= 0x37; 
        else 
            lowByte -= 0x30; 

        dest[i / 2] = (highByte << 4) | lowByte; 
    } 
    return ; 
}

int main()
{
    string  add_input = "00010966776006953D5567439E5E39F86A0D273BEE";
    unsigned char temp[200]={0};
    HexStrToByte(add_input.data(), temp, add_input.size());
    string hash_result;
    hash_result = get_sha_256(temp, add_input.size() / 2);
    cout << "hash: " << hash_result << endl;
    return 0;
}