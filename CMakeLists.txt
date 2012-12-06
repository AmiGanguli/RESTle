cmake_minimum_required (VERSION 2.6)

project (restle)
set (restle_VERSION_MAJOR 0)
set (restle_VERSION_MINOR 0)
set (LOG_LEVEL 9)
set (CMAKE_CXX_FLAGS -g)
set (SERVER_ADDRESS 127.0.0.1:8081)

configure_file(
	"${PROJECT_SOURCE_DIR}/Configure.h.in"
	"${PROJECT_BINARY_DIR}/Configure.h"
)

add_definitions(-DBOOST_PARAMETER_MAX_ARITY=10)

include_directories(
	${PROJECT_SOURCE_DIR}/lib
	${PROJECT_BINARY_DIR}
)

add_executable(restled
	src/restled.C
	lib/Server.C
#	lib/Handlers.C
)

target_link_libraries(restled
	PocoFoundation
	PocoUtil
	PocoNet
)

add_executable(testle
	unit_tests/main.C
)

target_link_libraries(testle
	boost_unit_test_framework
	PocoFoundation
	PocoUtil
	PocoNet
)

add_executable(test_v8
	src/test_v8.C
)

target_link_libraries(test_v8
	v8
)

