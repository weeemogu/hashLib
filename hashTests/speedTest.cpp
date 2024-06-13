#include "speedTest.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <bitset>
#include <chrono>

void SpeedTest::runTest(const HashFunction& hashFunc, std::ostream& output) const {
    size_t numKeys = 100000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, numKeys * 10);

    std::vector<std::string> keys(numKeys);
    for (size_t i = 0; i < numKeys; ++i) {
        keys[i] = std::to_string(dist(gen));
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (const auto& key : keys) {
        hashFunc(key);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Speed Test:" << std::endl;
    std::cout << "Time taken to hash " << numKeys << " keys: " << elapsed.count() << " milliseconds" << std::endl;

    output <<  "Speed Test," << hashFunc.name() << "," << elapsed.count() << std::endl;
}

std::string SpeedTest::name() const {
    return "Speed Test";
}