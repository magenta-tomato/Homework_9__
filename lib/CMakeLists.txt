cmake_minimum_required(VERSION 3.10)

# библиотека

# проект
project( 
	library 
	VERSION 
	${PROJECT_VERSION}
)

# библиотека и исходники
add_library( lib STATIC async.cpp async.h Bulk.h Bulk.cpp WriteThreads.h WriteThreads.cpp Context.h Context.cpp  )

# исходники используют файл version.h
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