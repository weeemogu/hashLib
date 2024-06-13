#include "avalancheTest.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <bitset>
#include <chrono>


void AvalancheTest::runTest(const HashFunction& hashFunc, std::ostream& output) const {
    std::string testKey = "test";
    size_t originalHash = hashFunc(testKey);
    size_t differentBits = 0;

    for (size_t i = 0; i < testKey.size() * 8; ++i) {
        std::string modifiedKey = testKey;
        modifiedKey[i / 8] ^= (1 << (i % 8));
        size_t modifiedHash = hashFunc(modifiedKey);
        differentBits += std::bitset<64>(originalHash ^ modifiedHash).count();
    }

    double averageDifferentBits = static_cast<double>(differentBits) / (testKey.size() * 8);

    std::cout << "Avalanche Test:" << std::endl;
    std::cout << "Average number of different bits: " << averageDifferentBits << std::endl;

    output <<  "Avalanche Test," << hashFunc.name() << "," << averageDifferentBits << std::endl;
}

std::string AvalancheTest::name() const {
    return "Avalanche Test";
}