#include <blog/infrastructure/repositories/InMemoryPostRepository.h>

namespace infrastructure {

bool InMemoryPostRepository::add(entities::Post post)
{
	if (m_posts.find(post.id) != m_posts.end()) {
		return false;
	}

	return m_posts.insert({post.id, post}).second;
}

std::optional<entities::Post> InMemoryPostRepository::get(entities::PostId id)
{
	auto it = m_posts.find(id);
	if (it == m_posts.end()) {
		return {};
	}
	return it->second;
}

std::vector<entities::Post> InMemoryPostRepository::getAll()
{
	std::vector<entities::Post> posts;
	for (const auto& [id, post] : m_posts) {
		posts.push_back(post);
	}
	return posts;
}

}
