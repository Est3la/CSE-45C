#ifndef USERCMD_HPP
#define USERCMD_HPP
#include "HashMap.hpp"
#include <iostream>

void create(HashMap& hm, const std::string& username, 
                const std::string& password);

void login(const HashMap& hm, const std::string& username, 
                const std::string& password);

void remove(HashMap& hm, const std::string& username);


#endif // USERCMD_HPP
