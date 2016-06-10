#include "HashFunction.hpp"
#include <iostream>

unsigned int hash_func_0(const std::string& key)
{
    return key.length();
}

unsigned int hash_func_1(const std::string& key)
{
    unsigned int hash = 0;
    for (unsigned int i = 0; i < key.length(); i++)
    {
        hash = hash * 37 + key[i];
    }
    return hash;
}
