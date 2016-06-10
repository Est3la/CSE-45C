#include <iostream>
#include <sstream>
#include "HashMap.hpp"
#include "UserCmd.hpp"
#include "HashFunction.hpp"
namespace
{
    HashMap h;
    bool debug = false;
    std::string cmd;
    std::string user;
    std::string pwd;

    void get_inputs(std::string& cmd, std::string& user, std::string& pwd)
    {
        // get and parse the inputs
        std::string line;

        std::getline(std::cin, line);
        cmd = ""; user = ""; pwd = "";

        std::istringstream parse_input(line);
        parse_input >> cmd >> user >> pwd;
    }
}

int main()
{
    do
    {
        get_inputs(cmd, user, pwd);

        if (cmd == "CREATE" && user != "" && pwd != "")
        {
            create(h, user, pwd);
        }
        else if (cmd == "LOGIN" && user != "" && pwd != "")
        {
            login(h, user, pwd);
        }
        else if (cmd == "REMOVE" && user != "" && pwd == "")
        {
            remove(h, user);
        }
        else if (cmd == "CLEAR" && user == "" && pwd == "")
        {
            h.clear();
        }
        else if (cmd == "DEBUG" && user == "ON" && pwd == "")
        {
            if (debug)
            {
                std::cout << "ON ALREADY" << std::endl;
            }
            else
            {
                debug = true;
                std::cout << "ON NOW" << std::endl;
            }
        }
        else if (cmd == "DEBUG" && user == "OFF" & pwd == "")
        {
            if (debug)
            {
                debug = false;
                std::cout << "OFF NOW" << std::endl;
            }
            else
            {
                std::cout << "OFF ALREADY" << std::endl;
            }
        }
        else if (debug)
        {
            if (cmd == "LOGIN" && user == "COUNT" && pwd == "")
            {
                std::cout << h.size() << std::endl;
            }
            else if (cmd == "BUCKET" && user == "COUNT" && pwd == "")
            {
                std::cout << h.bucketCount() << std::endl;
            }
            else if (cmd == "LOAD" && user == "FACTOR" && pwd == "")
            {
                std::cout << h.loadFactor() << std::endl;
            }
            else if (cmd == "MAX" && user == "BUCKET" && pwd == "SIZE")
            {
                std::cout << h.maxBucketSize() << std::endl;
            }
            else
            {
                std::cout << "INVALID" << std::endl;
            }
        }
        else if (cmd == "QUIT")
        {
            continue;
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
    }
    while (cmd != "QUIT");
    
    std::cout << "GOODBYE" << std::endl;
    
    return 0;
}
