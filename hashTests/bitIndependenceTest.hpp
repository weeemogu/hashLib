#ifndef BITINDEPENDENCE_TEST_HPP
#define BITINDEPENDENCE_TEST_HPP

#include "hashTestBase.hpp"

class BitIndependenceTest : public HashTest {
public:
    void runTest(const HashFunction& hashFunc, std::ostream& output) const override;
    std::string name() const override;
};

#endif