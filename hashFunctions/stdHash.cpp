#include "stdHash.hpp"

size_t StdHash::operator()(const std::string& key) const {
    return std::hash<std::string>{}(key);
}

std::string StdHash::name() const {
    return "std::hash";
}