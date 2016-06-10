// HashMapTests.cpp
//
// ICS 45C Fall 2015
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided one test already,
// though I've commented it out, because it won't compile until you've implemented
// three things: the HashMap constructor, the HashMap destructor, and HashMap's
// size() member function.

#include <gtest/gtest.h>
#include "HashMap.hpp"


TEST(TestHashMap, sizeOfNewlyCreatedHashMapIsZero)
{
    HashMap empty;
    ASSERT_EQ(0, empty.size());
}

TEST(TestHashMap, sizeOfBucketOfNewlyCreatedHashMapIsTen)
{
    HashMap h;
    ASSERT_EQ(10, h.bucketCount());
}

TEST(TestHashMap, testCopy)
{
    HashMap h1;
    h1.add("boo", "123");
    h1.add("alex", "234");
    h1.add("ben", "345");

    HashMap h2 = h1;
    ASSERT_EQ(3, h2.size());
    ASSERT_EQ(true, h2.contains("boo"));
    ASSERT_EQ(true, h2.contains("alex"));
    ASSERT_EQ(true, h2.contains("ben"));
}

TEST(TestHashMap, testAssignment)
{
    HashMap h1, h2;
    h1.add("boo", "123");
    h1.add("alex", "234");
    h1.add("ben", "345");

    h2 = h1;
    ASSERT_EQ(3, h2.size());
    ASSERT_EQ(true, h2.contains("boo"));
    ASSERT_EQ(true, h2.contains("alex"));
    ASSERT_EQ(true, h2.contains("ben"));
}

TEST(TestHashMap, testAdd)
{
    HashMap h;
    h.add("boo", "123");
    ASSERT_EQ(true, h.contains("boo"));
    ASSERT_EQ("123", h.value("boo"));
    ASSERT_EQ(1, h.size());
}

TEST(TestHashMap, testAddDuplicate)
{
    HashMap h;
    h.add("boo", "123");
    h.add("boo", "234");
    ASSERT_EQ("123", h.value("boo"));
}

TEST(TestHashMap, testRemove)
{
    HashMap h;
    h.add("boo", "123");
    h.add("alex", "234");
    h.add("ben", "345");
    ASSERT_EQ(3, h.size());

    h.remove("boo");
    ASSERT_EQ(2, h.size());
    ASSERT_EQ(false, h.contains("boo"));
}

TEST(TestHashMap, testRemoveNonexist)
{
    HashMap h;
    h.add("boo", "123");
    h.add("alex", "234");
    h.add("ben", "345");
    ASSERT_EQ(3, h.size());

    h.remove("john");
    ASSERT_EQ(3, h.size());
}

TEST(TestHashMap, testRemoveDuplicate)
{
    HashMap h;
    h.add("boo", "123");
    h.add("alex", "234");
    h.add("ben", "345");
    ASSERT_EQ(3, h.size());

    h.remove("boo");
    ASSERT_EQ(2, h.size());
    h.remove("boo");
    ASSERT_EQ(2, h.size());
}

TEST(TestHashMap, testContains)
{
    HashMap h;
    h.add("boo", "123");
    h.add("alex", "234");
    h.add("ben", "345");
    
    ASSERT_EQ(true, h.contains("boo"));
    ASSERT_EQ(true, h.contains("alex"));
    ASSERT_EQ(true, h.contains("ben"));
}

TEST(TestHashMap, testContainsOfNonExist)
{
    HashMap h;

    ASSERT_EQ(false, h.contains("George"));
}

TEST(TestHashMap, testValue)
{
    HashMap h;
    h.add("boo", "123");

    ASSERT_EQ("123", h.value("boo"));
}

TEST(TestHashMap, testValueOfNonExist)
{
    HashMap h;
    
    ASSERT_EQ("", h.value("alex"));
}

TEST(TestHashMap, testSize)
{
    HashMap h;
    h.add("boo", "123");
    ASSERT_EQ(1, h.size());

    h.add("alex", "234");
    ASSERT_EQ(2, h.size());
    
    h.add("ben", "345");
    ASSERT_EQ(3, h.size());

    h.remove("ben");
    ASSERT_EQ(2, h.size());

    h.remove("ben");
    ASSERT_EQ(2, h.size());
}

TEST(TestHashMap, testBucketCount)
{
    HashMap h;
    ASSERT_EQ(10, h.bucketCount());
    
    h.add("boo", "123");
    h.add("alex", "234");
    h.add("ben", "345");
    h.add("john", "123");
    h.add("binh", "123");
    h.add("george", "567");
    h.add("mike", "789");
    ASSERT_EQ(10, h.bucketCount());

    h.add("lisa", "123");
    ASSERT_EQ(21, h.bucketCount());
}

TEST(TestHashMap, testLoadFactor)
{
    HashMap h;
    ASSERT_EQ(0, h.loadFactor());

    h.add("boo", "123");
    ASSERT_EQ(0.1, h.loadFactor());

    h.add("alex", "234");
    ASSERT_EQ(0.2, h.loadFactor());

    h.remove("boo");
    ASSERT_EQ(0.1, h.loadFactor());
}

TEST(TestHashMap, testReHash)
{
    HashMap h;
    h.add("boo", "123");
    h.add("alex", "234");
    h.add("ben", "345");
    h.add("john", "123");
    h.add("binh", "123");
    h.add("george", "567");
    h.add("mike", "789");
    
    ASSERT_EQ(0.7, h.loadFactor());

    h.add("lynn", "098");
    ASSERT_NE(0.8, h.loadFactor());
}
