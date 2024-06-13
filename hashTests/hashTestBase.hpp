#ifndef HASH_TEST_HPP
#define HASH_TEST_HPP

#include <string>
#include "hashBase.hpp"

class HashTest {
public:
    virtual ~HashTest() = default;
    virtual void runTest(const HashFunction& hashFunc, std::ostream& output) const = 0;
    virtual std::string name() const = 0;
};

#endif // HASH_TEST_HPP