add_executable(tests main.cpp)
target_link_libraries(tests PRIVATE Starfarm_lib)

add_test(NAME exec_tests COMMAND tests)
