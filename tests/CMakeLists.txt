project(TimeLibTests LANGUAGES CXX)

file(GLOB_RECURSE TEST_SRC "${PROJECT_SOURCE_DIR}/*.cpp")
add_executable(timelib-tests ${TEST_SRC})

find_package(GTest CONFIG REQUIRED)
target_link_libraries(timelib-tests PRIVATE timelib GTest::gtest GTest::gtest_main)

add_test(NAME TimeLibTests COMMAND TimeLibTests)

include(GoogleTest)
gtest_discover_tests(timelib-tests)