#ifndef DISTRIBUTION_TEST_HPP
#define DISTRIBUTION_TEST_HPP

#include "hashTestBase.hpp"

class DistributionTest : public HashTest {
public:
    void runTest(const HashFunction& hashFunc, std::ostream& output) const override;
    std::string name() const override;
};


#endif // DISTRIBUTION_TEST_HPP