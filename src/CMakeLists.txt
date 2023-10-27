cmake_minimum_required(VERSION 3.10)

project( ip_filter_AND_test_lib_functions VERSION ${PROJECT_VERSION})

# исполняемые файлы собираются из следующих файлов
add_executable( ip_filter main.cpp )
add_executable( test_lib_functions test_lib_functions.cpp )

# исполняемые файлы использу библиотеку lib
target_link_libraries( ip_filter lib )
target_link_libraries( test_lib_functions   lib )
# директория заголовка библиотеки
target_include_directories(
    ip_filter 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
target_include_directories(
    test_lib_functions
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
# директория бинарника библиотеки
target_include_directories(
	ip_filter
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
)
target_include_directories(
	test_lib_functions
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
)


# один из исполняемых файлов использует библиотеки BOOST
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
target_link_libraries( test_lib_functions ${Boost_LIBRARIES} )
# директория заголовков библиотеки
target_include_directories(
    test_lib_functions
    PRIVATE
    ${Boost_INCLUDE_DIR}
)
set_target_properties(
	test_lib_functions PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
)

# поддержка станадарта языка
set_target_properties(
    ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
set_target_properties(
    test_lib_functions PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)


#
install(TARGETS ip_filter RUNTIME DESTINATION bin)
 
#
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)


add_custom_command(
    TARGET test_lib_functions POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_CURRENT_SOURCE_DIR}/../src/ip_filter.tsv
    ${CMAKE_CURRENT_BINARY_DIR}/ip_filter.tsv
)
add_test(test_lib_functions test_lib_functions)
