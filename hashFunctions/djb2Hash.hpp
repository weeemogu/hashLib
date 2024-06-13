#ifndef DJB2_HASH_HPP
#define DJB2_HASH_HPP

#include "hashBase.hpp"

class Djb2Hash : public HashFunction {
public:
    size_t operator()(const std::string& key) const override;
    std::string name() const override;
};

#endif // DJB2_HASH_HPP