#pragma once

#include <blog/entities/IPostRepository.h>
#include <blog/use_cases/AddPost.h>
#include <blog/use_cases/GetPosts.h>

namespace use_cases {

/// Collection of use cases
/// Usable by higher level layers
class UseCases {
public:
	UseCases(entities::IPostRepository& repository);

	AddPost addPost;
	GetPosts getPosts;
};

}
