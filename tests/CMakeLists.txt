enable_testing()
message(STATUS "Tests are enabled (PULSO_BUILD_TESTS=ON)")

find_package(GTest REQUIRED)
include(GoogleTest)

if(BUILD_WITH_ASAN)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message(STATUS "Building tests with AddressSanitizer and UndefinedBehaviorSanitizer")

        add_library(pulso_test_sanitizers INTERFACE)
        target_compile_options(pulso_test_sanitizers INTERFACE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
        )
        target_link_options(pulso_test_sanitizers INTERFACE
            -fsanitize=address,undefined
        )
    else()
        message(FATAL_ERROR "BUILD_WITH_ASAN requires GCC or Clang")
    endif()
endif()

function(pulso_enable_asan_for_test target_name)
    if(BUILD_WITH_ASAN)
        target_link_libraries(${target_name} PRIVATE pulso_test_sanitizers)
    endif()
endfunction()

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
pulso_enable_asan_for_test(test_types)
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
pulso_enable_asan_for_test(test_config)
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
pulso_enable_asan_for_test(test_storage)
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
pulso_enable_asan_for_test(test_disk_usage)
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
pulso_enable_asan_for_test(test_formatter_prometheus)
gtest_discover_tests(test_formatter_prometheus)