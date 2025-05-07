#include <blog/use_cases/AddPost.h>

#include <mocks/IPostRepositoryMock.h>

#include <gtest/gtest.h>

TEST(
	AddPostTest,
	WhenCallingAddPostUseCaseWithValidTitleAndContent_ThenPostIsAdded)
{
	auto repositoryMock = use_cases::IPostRepositoryMock {};
	auto addPost = use_cases::AddPost {repositoryMock};

	auto title = std::string {"title"};
	auto content = std::string {"content"};

	entities::Post post {title, content};

	/// Here we use the gmock library to set up the expectation
	/// We expect that the add method will be called on the repository
	/// with post as the parameter
	EXPECT_CALL(repositoryMock, add(post)).WillOnce(testing::Return(true));

	auto postAdded = addPost.execute(title, content);

	/// Here we verify that the post was added
	EXPECT_TRUE(postAdded);
}
