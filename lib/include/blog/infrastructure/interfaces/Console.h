#pragma once

namespace use_cases {
class UseCases;
}

/// Console is encapsulated into the infrastructure namespace
namespace infrastructure {

/// Console is the way for a user to interact with the application
/// via a command line interface.
/// It can be used to add posts and list them.
class Console {
public:
	/// Constructor
	/// We give the use cases to the Console
	Console(use_cases::UseCases& useCases);

	void run();

private:
	use_cases::UseCases& m_useCases;
};

}
