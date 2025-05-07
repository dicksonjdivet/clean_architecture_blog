#include <blog/infrastructure/repositories/InMemoryPostRepository.h>

#include <blog/use_cases/UseCases.h>

#include <blog/infrastructure/interfaces/Console.h>
#include <blog/infrastructure/interfaces/HTTPServer.h>

#include <iostream>

// Do all the dependency resolution wiring here...
int main()
{
	// Instanciate a RAM Blog post repository
	infrastructure::InMemoryPostRepository repository;

	// Inject it into the use cases to satisfy the dependency
	use_cases::UseCases useCases(repository);

	// Create the HTTP server and the console which are the user interfaces
	// that will use the use cases to satisfy the functional requirements
	infrastructure::Console console(useCases);

	// Start server and run console...
	auto server = infrastructure::HTTPServer::create(8080, useCases);

	if (!server) {
		std::cerr << "Failed to create server\n";
		return 1;
	}

	std::cout << "Starting server...\n";

	server->start();

	std::cout << "Welcome to the blog!\n";

	console.run();

	std::cout << "Goodbye!\n";

	return 0;
}
