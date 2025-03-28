#pragma once

#include <cstdint>

#include <memory>

namespace use_cases {
class UseCases;
}

namespace ohttp {
class IHTTPServer;
}

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
