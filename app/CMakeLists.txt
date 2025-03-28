project(blog_app)

add_executable(
	blog_app
	src/main.cpp
)

target_link_libraries(
	blog_app
	PRIVATE
	blog_lib
)
