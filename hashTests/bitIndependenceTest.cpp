#include "bitIndependenceTest.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <bitset>
#include <chrono>


void BitIndependenceTest::runTest(const HashFunction& hashFunc, std::ostream& output) const {
    std::string key1 = "key1";
    std::string key2 = "key2";
    size_t hash1 = hashFunc(key1);
    size_t hash2 = hashFunc(key2);

    size_t differentBits = std::bitset<64>(hash1 ^ hash2).count();
    double bitIndependenceScore = static_cast<double>(differentBits) / 64.0;

    std::cout << "Bit Independence Test:" << std::endl;
    std::cout << "Bit independence score: " << bitIndependenceScore << std::endl;

    output <<  "Bit Independence Test," << hashFunc.name() << "," << bitIndependenceScore << std::endl;
}

std::string BitIndependenceTest::name() const {
    return "Bit Independence Test";
}