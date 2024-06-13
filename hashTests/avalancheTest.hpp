#ifndef AVALANCHE_TEST_HPP
#define AVALANCHE_TEST_HPP

#include "hashTestBase.hpp"

class AvalancheTest : public HashTest {
public:
    void runTest(const HashFunction& hashFunc, std::ostream& output) const override;
    std::string name() const override;
};

#endif