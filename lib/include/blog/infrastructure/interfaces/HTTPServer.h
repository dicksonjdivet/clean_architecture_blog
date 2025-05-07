#pragma once

#include <blog/use_cases/UseCases.h>

/// In the infrastructure module, we can import
/// external dependencies like ohttp
#include <OHTTP/IHTTPServer.h>

#include <cstdint>
#include <memory>

namespace infrastructure {

class HTTPServer {
public:
	static std::unique_ptr<HTTPServer> create(
		uint16_t port,
		use_cases::UseCases& useCases);

	~HTTPServer();

	void start();

private:
	HTTPServer(std::unique_ptr<ohttp::IHTTPServer> server);

	std::unique_ptr<ohttp::IHTTPServer> server;
};

}
