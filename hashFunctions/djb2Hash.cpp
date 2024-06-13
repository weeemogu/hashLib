#include "djb2Hash.hpp"

size_t Djb2Hash::operator()(const std::string& key) const {
    size_t hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

std::string Djb2Hash::name() const {
    return "DJB2";
}