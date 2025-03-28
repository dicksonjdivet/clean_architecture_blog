#include <blog/infrastructure/interfaces/Console.h>

#include <blog/use_cases/UseCases.h>

#include <iostream>

namespace infrastructure {

static void printCommands()
{
	std::cout << "Commands:\n";
	std::cout << "add <title> <content>: Add a new post\n";
	std::cout << "list: List all posts\n";
	std::cout << "exit: Exit the program\n";
}

Console::Console(use_cases::UseCases& useCases)
	: m_useCases(useCases)
{
}

void Console::run()
{
	std::string command;

	printCommands();

	while (true) {
		std::cout << "> ";
		std::cin >> command;

		if (command == "add") {
			std::string title;
			std::string content;

			std::cout << "Enter Title: \n";
			std::cin.ignore();
			std::getline(std::cin, title);

			std::cout << "\nEnter Content: \n";
			std::getline(std::cin, content);

			m_useCases.addPost.execute(title, content);
		} else if (command == "list") {
			auto posts = m_useCases.getPosts.execute();

			for (const auto& post : posts) {
				std::cout << post.id << ": " << post.title << "\n";
				std::cout << post.content << "\n\n";
			}
		} else if (command == "exit") {
			break;
		} else {
			std::cerr << "Unknown command: " << command << "\n";
		}
	}
}

}
