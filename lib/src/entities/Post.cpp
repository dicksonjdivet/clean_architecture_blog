#include <blog/entities/Post.h>

#include <hashtable.h>

namespace entities {

Post::Post(
	std::string title,
	std::string content)
	: id(std::hash<std::string> {}(title + content))
	, title(std::move(title))
	, content(std::move(content))
{
}

bool Post::operator==(const Post& post) const
{
	return id == post.id;
}

}
