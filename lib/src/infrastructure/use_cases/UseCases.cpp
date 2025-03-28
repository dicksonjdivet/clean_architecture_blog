#include <blog/use_cases/UseCases.h>

namespace use_cases {

UseCases::UseCases(entities::IPostRepository& repository)
	: addPost(repository)
	, getPosts(repository)
{
}

}
