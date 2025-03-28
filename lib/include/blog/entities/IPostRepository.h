#pragma once

#include <blog/entities/Post.h>

#include <optional>
#include <vector>

namespace entities {

class IPostRepository {
public:
	virtual ~IPostRepository() = default;

	virtual bool add(Post post) = 0;
	virtual std::optional<Post> get(PostId id) = 0;
	virtual std::vector<Post> getAll() = 0;
};

}
