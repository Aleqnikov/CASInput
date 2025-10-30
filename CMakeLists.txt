cmake_minimum_required(VERSION 3.30)
project(input)

# Добавляем GoogleTest
add_subdirectory(googletest)

# Исходники
set(SOURCES
        main.cpp
        src/Lexer.cpp
        # Добавь другие исходники когда будут
)

# Главный исполняемый файл
add_executable(input ${SOURCES})

# Подключаем GoogleTest
target_link_libraries(input
        PRIVATE
        gtest_main
        gmock_main
)

# Включаем C++17 (или какой стандарт используешь)
target_compile_features(input PRIVATE cxx_std_17)

# Включаем тестирование
enable_testing()

# Добавляем тесты если будут
# add_test(NAME input_test COMMAND input)