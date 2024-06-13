#ifndef STD_HASH_HPP
#define STD_HASH_HPP

#include "hashBase.hpp"
#include <functional>

class StdHash : public HashFunction {
public:
    size_t operator()(const std::string& key) const override;
    std::string name() const override;
};

#endif // STD_HASH_HPP