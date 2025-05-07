#pragma once

#include <string>

/// Post is encapsulated in entities namespace
namespace entities {

using PostId = size_t;

/// Post class which modelizes a blog post
class Post {
public:
	/// Constructor
	/// \param title The title of the post
	/// \param content The content of the post
	Post(
		std::string title,
		std::string content);

	/// \brief The id of the post, calculated from the title and content
	/// guaranteeing uniqueness
	const PostId id;

	const std::string title;
	const std::string content;

	bool operator==(const Post& post) const;
};

}
