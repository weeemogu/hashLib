set(SOURCE_FILES
    hashBase.hpp
    stdHash.hpp
    stdHash.cpp
    djb2Hash.hpp
    djb2Hash.cpp
)

add_library(hashFunctions ${SOURCE_FILES})