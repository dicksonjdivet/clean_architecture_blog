#pragma once

#include <string>

namespace entities {

using PostId = size_t;

class Post {
public:
	Post(
		std::string title,
		std::string content);

	const PostId id;
	const std::string title;
	const std::string content;

	bool operator==(const Post& post) const;
};

}
