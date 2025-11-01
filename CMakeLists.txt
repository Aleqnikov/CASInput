cmake_minimum_required(VERSION 3.30)
project(input)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------
# Основная программа
# ---------------------------
set(APP_SOURCES
        main.cpp
        src/Lexer.cpp
        src/Token.cpp
)

add_executable(input ${APP_SOURCES})

# ---------------------------
# Google Test
# ---------------------------
# Подключаем googletest
add_subdirectory(googletest)

set(TEST_SOURCES
        tests/main.cpp
        tests/LexerTests.cpp
        src/Lexer.cpp
        src/Token.cpp
)

add_executable(Tests ${TEST_SOURCES})

target_link_libraries(Tests
        PRIVATE
        gtest
        gtest_main
        gmock
        gmock_main
)

enable_testing()
add_test(NAME AllTests COMMAND Tests)
