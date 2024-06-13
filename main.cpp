#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "hashBase.hpp"
#include "stdHash.hpp"
#include "djb2Hash.hpp"
#include "hashTestBase.hpp"
#include "distributionTest.hpp"
#include "distributionTest.hpp"
#include "avalancheTest.hpp"
#include "bitIndependenceTest.hpp"
#include "speedTest.hpp"


int main() {
    std::ofstream outputFile("hash_test_results.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the output file." << std::endl;
        return 1;
    }

    outputFile << "Test Type,Hash Function,Result1,Result2\n"; // Header for the CSV file

    std::vector<std::shared_ptr<HashFunction>> hashFunctions = {
        {std::make_shared<StdHash>()},
        {std::make_shared<Djb2Hash>()}
    };

    std::vector<std::shared_ptr<HashTest>> tests = {
        {std::make_shared<DistributionTest>()},
        {std::make_shared<AvalancheTest>()},
        {std::make_shared<BitIndependenceTest>()},
        {std::make_shared<SpeedTest>()}
    };
    for (const auto& testInfo : tests) {
        for (const auto& hashFuncInfo : hashFunctions) {
            std::cout << "Running " << testInfo->name() << " for " << hashFuncInfo->name() << std::endl;
            testInfo->runTest(*hashFuncInfo, outputFile);
        }
    }

    return 0;
}