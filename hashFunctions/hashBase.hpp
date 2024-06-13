#ifndef HASH_BASE_HPP
#define HASH_BASE_HPP

#include <string>

class HashFunction {
public:
    virtual ~HashFunction() = default;
    virtual size_t operator()(const std::string& key) const = 0;
    virtual std::string name() const = 0;
};

#endif // HASH_BASE_HPP