#include <blog/use_cases/AddPost.h>

#include <mocks/IPostRepositoryMock.h>

#include <gtest/gtest.h>

TEST(
	AddPostTest,
	WhenCallingAddPostUseCaseWithValidTitleAndContent_ThenPostIsAdded)
{
	// Given
	auto repositoryMock = use_cases::IPostRepositoryMock {};
	auto addPost = use_cases::AddPost {repositoryMock};

	auto title = std::string {"title"};
	auto content = std::string {"content"};

	entities::Post post {title, content};

	EXPECT_CALL(repositoryMock, add(post)).WillOnce(testing::Return(true));

	auto postAdded = addPost.execute(title, content);

	EXPECT_TRUE(postAdded);
}
