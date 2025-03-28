project(blog_test)

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")

add_executable(
	${PROJECT_NAME}
	${SOURCES}
	${HEADERS}
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	GTest::gtest
	GTest::gmock
	blog_lib
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src
)
