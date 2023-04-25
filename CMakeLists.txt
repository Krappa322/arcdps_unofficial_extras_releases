cmake_minimum_required(VERSION 3.23)

project(ArcdpsUnofficialExtras CXX)
set(CMAKE_CXX_STANDARD 20)

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

find_package(magic_enum CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::UnofficialExtras ALIAS ${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

add_compile_definitions(
	NOMINMAX
	MAGIC_ENUM_RANGE_MAX=256
	IMGUI_DEFINE_MATH_OPERATORS
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

target_link_libraries(${PROJECT_NAME} PRIVATE magic_enum::magic_enum)

install(TARGETS ${PROJECT_NAME}
	EXPORT ArcdpsUnofficialExtrasExport 
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

install(EXPORT ArcdpsUnofficialExtrasExport
	FILE ArcdpsUnofficialExtrasExport.cmake
	DESTINATION share/${PROJECT_NAME}
)
