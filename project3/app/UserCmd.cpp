#include "UserCmd.hpp"
#include "HashMap.hpp"
#include <iostream>

void create(HashMap& hm, const std::string& username, 
                        const std::string& password)
{
    //create a new user with username and password
    if (hm.contains(username))
    {
        std::cout << "EXISTS" << std::endl;
    }
    else
    {
        hm.add(username, password);
        std::cout << "CREATED" << std::endl;
    }
}

void login(const HashMap& hm, const std::string& username,
                    const std::string& password)
{
    //login using username and password
    if (hm.contains(username) && hm.value(username) == password)
    {
        std::cout << "SUCCEEDED" << std::endl;
    }
    else
    {
        std::cout << "FAILED" << std::endl;
    }
}

void remove(HashMap& hm, const std::string& username)
{
    //remove a user from the hashmap
    if (hm.contains(username))
    {
        hm.remove(username);
        std::cout << "REMOVED" << std::endl;
    }
    else
    {
        std::cout << "NONEXISTENT" << std::endl;
    }
}

