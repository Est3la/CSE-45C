#include "HashMap.hpp"
#include "HashFunction.hpp"
#include <iostream>

void HashMap::HashMapCopy(Node** target, Node** source, unsigned int cap)
{
    // Copy elements of hashmap
    for (unsigned int i = 0; i < cap; i++)
    {
        Node* entry = source[i];
        Node** prev = &target[i];
        *prev = nullptr;
        while (entry != nullptr)
        {
            Node* newNode = new Node{entry->key, entry->value, nullptr};
            *prev = newNode;
            prev = &newNode->next;
            entry = entry->next;
        }
    }    
}

HashMap::HashMap()
    :hasher{hash_func_1}, table{new Node* [initialBucketCount]()}, 
        sz{0}, cap{initialBucketCount}    
{
}

HashMap::HashMap(HashFunction hasher)
    :hasher{hasher}, table{new Node* [initialBucketCount]()}, 
        sz{0}, cap{initialBucketCount}
{
}

HashMap::HashMap(const HashMap& hm)
    :hasher{hm.hasher}, table{new Node* [hm.cap]},
        sz{hm.sz}, cap{hm.cap}
{
    HashMapCopy(table, hm.table, cap);
}

HashMap::~HashMap()
{
    for(unsigned int i=0; i < cap; i++)
    {
        Node* entry = table[i];
        while (entry != nullptr)
        {
            Node* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] table;
}

HashMap& HashMap::operator=(const HashMap& hm)
{
    if (this != &hm)
    {
        Node** newtable = new Node* [hm.cap];
        HashMapCopy(newtable, hm.table, hm.cap);

        hasher = hm.hasher;
        sz = hm.sz;
        cap = hm.cap;

        delete[] table;
        table = newtable;
    }
    return *this;
}

void HashMap::reHash()
{
    //reHash when loadFactor() exceeds 0.8
    int oldcap = cap;
    cap = oldcap * 2 + 1;
    Node** newtable = new Node* [cap]();

    for (unsigned int i = 0; i < oldcap; i++)
    {
        Node* entry = table[i];
        while (entry != nullptr)
        {
            Node* t = entry;
            entry = entry-> next;

            Node*& bucket = newtable[hasher(t->key) % cap];
            t->next = bucket;
            bucket = t;
        }
    }
    delete[] table;
    table = newtable;
}


void HashMap::add(const std::string& key, const std::string& value)
{
    //ad new element to hashmap
    if (!contains(key))
    {
        unsigned int hashvalue = hasher(key) % cap;    
        Node* prev = nullptr;
        Node* entry = table[hashvalue];
   

        while (entry != nullptr)
        {
            prev = entry;
            entry = entry->next;
        }   

        if (entry == nullptr)
        {
            entry = new Node{key, value};
            if (prev == nullptr)
            {
                table[hashvalue] = entry;
                sz++;
            }
            else
            {
                prev->next = entry;
                sz++;
            }
        }
    }
    if (loadFactor() >= 0.8)
    {
        reHash();
    }
}

void HashMap::remove(const std::string& key)
{
    // remove element from hashmap
    if (contains(key))
    {
        unsigned int hashvalue = hasher(key) % cap;
        Node* prev = nullptr;
        Node* entry = table[hashvalue];

        while (entry != nullptr && entry->key != key)
        {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr)
        {
            return;
        }
    
        else
        {
            if (prev == nullptr)
            {
                table[hashvalue] = entry->next;
                sz--;
            }
            else
            {
                prev->next = entry->next;
                sz--;
            }
            delete entry;
        }
    }
}

bool HashMap::contains(const std::string& key) const
{
    //check if hashmap contains an element
    unsigned int hashvalue = hasher(key) % cap;
    Node* entry = table[hashvalue];

    while (entry != NULL)
    {
        if (entry->key == key)
        {
            return true;
        }
        entry = entry->next;
    }
    return false;
}

std::string HashMap::value(const std::string& key) const
{
    //get the value of an element of a hashmap
    if (contains(key))
    {
        unsigned int hashvalue = hasher(key) % cap;
        Node* entry = table[hashvalue];
        while (entry->key != key)
        {
            entry = entry->next;
        }
        return entry->value;
    }
    else
    {
        return "";
    }
}

unsigned int HashMap::size() const
{
    //get login count
    return sz;
}

unsigned int HashMap::bucketCount() const
{
    //get bucket count
    return cap;
}

double HashMap::loadFactor() const
{
    //get load factor
    return sz/static_cast<double>(cap);
}

unsigned int HashMap::maxBucketSize() const
{
    //get max bucket size
    unsigned int mbsz = 0;
    for (unsigned int i = 0; i < cap; i++)
    {
        int len = 0;
        Node* entry = table[i];
        while (entry != nullptr)
        {
            len++;
            entry = entry->next;
        }
        if (len > mbsz)
        {
            mbsz = len;
        }
    }
    return mbsz;
}

void HashMap::PrintAll()
{
    //print all element of hashmap
    std::cout << "Bucket\tkey\tvalue" << std::endl;
    for (unsigned int i = 0; i < cap; i++)
    {
        Node* entry = table[i];
        while (entry != nullptr)
        {
            std::cout << i << "\t" << entry->key <<
                    "\t" << entry->value << std::endl;
            entry = entry->next;
        }
    }
}

void HashMap::clear()
{
    //clear all element of hashmap, reset login count, preserve everything else
    for (unsigned int i = 0; i < cap; i++)
    {
        Node* entry = table[i];
        while (entry != nullptr)
        {
            Node* prev = entry;
            entry = entry->next;
            delete prev;
        }
        table[i] = nullptr;
    }
    sz = 0;
}
