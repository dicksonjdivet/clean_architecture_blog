#include <blog/infrastructure/repositories/InMemoryPostRepository.h>

#include <blog/use_cases/UseCases.h>

namespace use_cases {

GetPosts::GetPosts(entities::IPostRepository& repository)
	: m_repository(repository)
{
}

std::vector<entities::Post> GetPosts::execute()
{
	return m_repository.getAll();
}

}
