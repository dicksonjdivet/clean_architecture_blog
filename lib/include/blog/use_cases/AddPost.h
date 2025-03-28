#pragma once

#include <blog/entities/Post.h>

namespace entities {
class IPostRepository;
}

namespace use_cases {

class AddPost {
public:
	AddPost(entities::IPostRepository& repository);

	bool execute(
		std::string title,
		std::string content);

private:
	entities::IPostRepository& m_repository;
};

}
