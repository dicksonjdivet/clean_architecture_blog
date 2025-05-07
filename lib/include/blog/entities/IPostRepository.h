#pragma once

#include <blog/entities/Post.h>

#include <optional>
#include <vector>

namespace entities {

/// Interface for the Post repository
/// This interface is used to abstract the storage of posts
class IPostRepository {
public:
	/// Ugly C++ way of dealing with polymorphism
	/// virtual destructor to prevent memory leaks when destroying instances
	virtual ~IPostRepository() = default;

	/// \brief Add a post to the repository
	virtual bool add(Post post) = 0;

	/// \brief Get a post by its ID
	virtual std::optional<Post> get(PostId id) = 0;

	/// \brief Get all the posts from the repository
	virtual std::vector<Post> getAll() = 0;
};

}
