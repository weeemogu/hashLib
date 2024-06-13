#ifndef SPEED_TEST_HPP
#define SPEED_TEST_HPP

#include "hashTestBase.hpp"

class SpeedTest : public HashTest {
public:
    void runTest(const HashFunction& hashFunc, std::ostream& output) const override;
    std::string name() const override;
};

#endif