cmake_minimum_required(VERSION 3.23)

option(ARCPDS_UNOFFICIAL_EXTRAS_MAGIC_ENUM "Compile with magic-enum as dependency" ON)
option(ARCPDS_UNOFFICIAL_EXTRAS_CPP_11 "Activate compatibility for C++11, will disable magic-enum" OFF)

project(ArcdpsUnofficialExtras CXX)

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

add_compile_definitions(
	NOMINMAX
	MAGIC_ENUM_RANGE_MAX=256
)

target_sources(${PROJECT_NAME} INTERFACE
	FILE_SET HEADERS
	FILES
		Definitions.h
		KeyBindHelper.h
		KeyBindsTranslation.h
		KeyBindStructs.h
)

target_sources(${PROJECT_NAME}
	PRIVATE
		KeyBindHelper.cpp
		KeyBindsTranslation.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	target_compile_options(${PROJECT_NAME} PUBLIC "/Zc:__cplusplus")
endif ()

if (ARCPDS_UNOFFICIAL_EXTRAS_MAGIC_ENUM AND NOT ARCPDS_UNOFFICIAL_EXTRAS_CPP_11)
	include(cmake/magic-enum-dep.cmake)
endif ()

if (ARCPDS_UNOFFICIAL_EXTRAS_CPP_11)
	target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
else ()
	target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
endif ()

install(TARGETS ${PROJECT_NAME}
	EXPORT ArcdpsUnofficialExtrasTargets
	FILE_SET HEADERS
	DESTINATION include/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/ArcdpsUnofficialExtrasConfig.cmake
	INSTALL_DESTINATION share/${PROJECT_NAME}
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ArcdpsUnofficialExtrasConfig.cmake
	DESTINATION share/${PROJECT_NAME}
)

install(EXPORT ArcdpsUnofficialExtrasTargets
	FILE ArcdpsUnofficialExtrasTargets.cmake
	DESTINATION share/${PROJECT_NAME}
)
