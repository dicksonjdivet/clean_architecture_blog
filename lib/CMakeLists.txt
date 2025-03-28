project(blog_lib)


file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.h)

add_library(
	${PROJECT_NAME}
	${SOURCES}
	${HEADERS}
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	OHTTP
	OToolsC++
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
