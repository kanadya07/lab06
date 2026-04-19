add_executable(solver equation.cpp)

target_include_directories(solver PRIVATE
  ${PROJECT_SOURCE_DIR}/formatter_ex_lib
  ${PROJECT_SOURCE_DIR}/solver_lib
)

target_link_libraries(solver PRIVATE formatter_ex solver)

install(TARGETS solver
  RUNTIME DESTINATION bin
)
