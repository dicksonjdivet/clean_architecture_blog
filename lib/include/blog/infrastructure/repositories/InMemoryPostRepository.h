#pragma once

#include <blog/entities/IPostRepository.h>

#include <map>

namespace entities {
using PostId = size_t;
class Post;
}

/// InMemoryPostRepository is encapsulated in the infrastructure
/// namespace (framework & driver layer)
namespace infrastructure {

/// In Memory repository (RAM persistance)
class InMemoryPostRepository : public entities::IPostRepository {
public:
	bool add(entities::Post post) override;

	std::optional<entities::Post> get(entities::PostId id) override;

	std::vector<entities::Post> getAll() override;

private:
	std::map<entities::PostId, entities::Post> m_posts;
};

}
