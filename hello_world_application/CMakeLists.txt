add_executable(hello_world hello_world.cpp)

target_include_directories(hello_world PRIVATE
  ${PROJECT_SOURCE_DIR}/formatter_ex_lib
)

target_link_libraries(hello_world PRIVATE formatter_ex)
