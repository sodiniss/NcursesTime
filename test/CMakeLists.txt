add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR "./lib/googletest/")
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(TEST_SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/runAllTests.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CountdownTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DateTimeTest.cpp
        )

add_executable(progTests ${TEST_SOURCE_FILES})
target_link_libraries(progTests 
    gtest gtest_main 
    core
)