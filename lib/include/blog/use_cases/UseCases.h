#pragma once

#include <blog/use_cases/AddPost.h>
#include <blog/use_cases/GetPosts.h>

namespace entities {
class IPostRepository;
}

namespace use_cases {

class UseCases {
public:
	UseCases(entities::IPostRepository& repository);

	AddPost addPost;
	GetPosts getPosts;
};

}
