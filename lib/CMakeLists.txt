cmake_minimum_required(VERSION 3.10)

project( library VERSION ${PROJECT_VERSION})

# преобразование h.in в h файл
configure_file(
    version.h.in 
    ${CMAKE_CURRENT_BINARY_DIR}/version.h
)
# библиотека собирается из следующих файлов
add_library( lib STATIC lib.cpp lib.h )

# директория содержащая version.h
target_include_directories(
    lib 
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

# поддержка стандарта языка
set_target_properties(
    lib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

