#include <blog/use_cases/AddPost.h>

#include <blog/entities/IPostRepository.h>

namespace use_cases {

AddPost::AddPost(entities::IPostRepository& repository)
	: m_repository(repository)
{
}

bool AddPost::execute(
	std::string title,
	std::string content)
{
	auto post = entities::Post {title, content};

	return m_repository.add(post);
}

}
