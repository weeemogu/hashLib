set(SOURCE_FILES
    hashTestBase.hpp
    distributionTest.hpp
    distributionTest.cpp
    avalancheTest.hpp
    avalancheTest.cpp
    bitIndependenceTest.hpp
    bitIndependenceTest.cpp
    speedTest.hpp
    speedTest.cpp
)

add_library(hashTests ${SOURCE_FILES})

target_include_directories(hashTests PUBLIC ${PROJECT_SOURCE_DIR}/hashFunctions)