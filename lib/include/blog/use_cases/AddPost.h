#pragma once

// We import IPostRepository from the entities namespace
#include <blog/entities/IPostRepository.h>

#include <string>

/// AddPost is encapsulated into the use_cases namespace
namespace use_cases {

/// AddPost use case
class AddPost {
public:
	/// AddPost takes a reference to a Post repository
	/// It does not care about the implementation of the repository
	AddPost(entities::IPostRepository& repository);

	/// \brief Execute the use case
	/// \param title The title of the post
	/// \param content The content of the post
	bool execute(
		std::string title,
		std::string content);

private:
	entities::IPostRepository& m_repository;
};

}
