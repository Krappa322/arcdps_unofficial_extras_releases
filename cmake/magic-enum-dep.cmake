find_package(magic_enum CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE magic_enum::magic_enum)
