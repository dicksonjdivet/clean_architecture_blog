#include <gmock/gmock.h>

#include <blog/entities/IPostRepository.h>

namespace use_cases {

class IPostRepositoryMock : public entities::IPostRepository {
public:
	MOCK_METHOD(
		bool,
		add,
		(entities::Post post),
		(override));

	MOCK_METHOD(
		std::optional<entities::Post>,
		get,
		(entities::PostId id),
		(override));

	MOCK_METHOD(
		std::vector<entities::Post>,
		getAll,
		(),
		(override));
};

}
