enable_testing()
message(STATUS "Tests are enabled (PULSO_BUILD_TESTS=ON)")
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(test_types
    core/test_types.cpp
)
target_include_directories(test_types PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(test_types PRIVATE
    GTest::gtest
    GTest::gtest_main
)
gtest_discover_tests(test_types)
 
add_executable(test_config
    test_config.cpp
)
target_include_directories(test_config PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(test_config PRIVATE
    GTest::gtest
    GTest::gtest_main
)
gtest_discover_tests(test_config)

add_executable(test_storage
    storage/test_storage.cpp
)
target_include_directories(test_storage PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(test_storage PRIVATE
    GTest::gtest
    GTest::gtest_main
    SQLiteCpp
    sqlite3
    pthread
    dl
)
gtest_discover_tests(test_storage)
add_executable(test_disk_usage
    automatizados/test_disk_usage.cpp
)
target_include_directories(test_disk_usage PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(test_disk_usage PRIVATE
    GTest::gtest
    GTest::gtest_main
)
gtest_discover_tests(test_disk_usage)
add_executable(test_formatter_prometheus
    formatters/test_formatter_prometheus.cpp
    ${PROJECT_SOURCE_DIR}/src/formatters/formatter_prometheus.cpp
)
target_include_directories(test_formatter_prometheus PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(test_formatter_prometheus PRIVATE
    GTest::gtest
    GTest::gtest_main
)
gtest_discover_tests(test_formatter_prometheus)

add_executable(test_ram_usage
    automatizados/test_ram_usage.cpp
    ${PROJECT_SOURCE_DIR}/src/collectors/memory/ram_usage.cpp
)
target_include_directories(test_ram_usage PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(test_ram_usage PRIVATE
    GTest::gtest
    GTest::gtest_main
)
gtest_discover_tests(test_ram_usage)