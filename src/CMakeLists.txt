add_library(cprimes cprimes.c cprimes.h)
target_include_directories(cprimes PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

#add_executable(cprime cprime.c CBricksLibConfig.h)
add_executable(cprime cprime.c)
target_include_directories(cprime PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}")
configure_file(CBricksLibConfig.h.in CBricksLibConfig.h)
target_link_libraries(cprime cprimes)

add_test(NAME VersionCheckShort COMMAND cprime -v)
set_tests_properties(VersionCheckShort PROPERTIES PASS_REGULAR_EXPRESSION ".*${CBricksLib_VERSION_MAJOR}\.${CBricksLib_VERSION_MINOR}")
add_test(NAME VersionCheckLong COMMAND cprime --version)
set_tests_properties(VersionCheckLong PROPERTIES PASS_REGULAR_EXPRESSION ".*${CBricksLib_VERSION_MAJOR}\.${CBricksLib_VERSION_MINOR}")
add_test(NAME PrimeCheck1 COMMAND cprime -c 1)
set_tests_properties(PrimeCheck1 PROPERTIES PASS_REGULAR_EXPRESSION "^1$")
