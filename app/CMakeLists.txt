cmake_minimum_required(VERSION 3.10)

# приложение

# проект
project( 
	mvc 
	VERSION 
	${PROJECT_VERSION}
)

# исполняемый файлы и исходники
add_executable( 
	mvc
	main.cpp 
)

# исполняемый файл использует библиотеку lib
target_link_libraries( 
	mvc 
	lib 
)

# исходники используют заголовок библиотеки lib
target_include_directories(
    mvc 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

# директория бинарника библиотеки
target_include_directories(
	mvc
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
)

# поддержка станадарта языка
set_target_properties(
    mvc PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

#
install(TARGETS mvc RUNTIME DESTINATION bin)
 
#
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
