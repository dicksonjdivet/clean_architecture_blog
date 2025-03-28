#pragma once

#include <blog/entities/Post.h>

#include <vector>

namespace entities {
class IPostRepository;
}

namespace use_cases {

class GetPosts {
public:
	GetPosts(entities::IPostRepository& repository);

	std::vector<entities::Post> execute();

private:
	entities::IPostRepository& m_repository;
};

}
