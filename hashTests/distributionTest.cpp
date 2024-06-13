#include "distributionTest.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <bitset>
#include <chrono>


void DistributionTest::runTest(const HashFunction& hashFunc, std::ostream& output) const {
    size_t numKeys = 100000;
    size_t numBuckets = 1000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, numKeys * 10);

    std::vector<size_t> bucketCounts(numBuckets, 0);

    for (size_t i = 0; i < numKeys; ++i) {
        std::string key = std::to_string(dist(gen));
        size_t bucket = hashFunc(key) % numBuckets;
        bucketCounts[bucket]++;
    }

    double mean = static_cast<double>(numKeys) / numBuckets;
    double variance = 0.0;

    for (size_t count : bucketCounts) {
        variance += (count - mean) * (count - mean);
    }
    variance /= numBuckets;
    double stdDev = std::sqrt(variance);

    std::cout << "Distribution Test:" << std::endl;
    std::cout << "Mean number of keys per bucket: " << mean << std::endl;
    std::cout << "Standard deviation: " << stdDev << std::endl;

    output << "Distribution Test," << hashFunc.name() << "," << mean << "," << stdDev << std::endl;
}

std::string DistributionTest::name() const {
    return "Distribution Test";
}