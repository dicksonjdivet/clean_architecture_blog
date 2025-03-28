#include <blog/infrastructure/interfaces/HTTPServer.h>

#include <blog/use_cases/UseCases.h>

#include <OHTTP/HTTPFactory.h>
#include <OHTTP/HTTPRequestInfo.h>
#include <OHTTP/HTTPRouteRequestHandler.h>
#include <OHTTP/HTTPServerConfig.h>
#include <OHTTP/HTTPServerResponse.h>
#include <OHTTP/IHTTPServer.h>

#include <OTools/C++/StringFormat.hpp>
#include <optional>

static const std::string HTML_TEMPLATE =
	R"(
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Blog List</title>
	<style>
		body {
			font-family: Arial, sans-serif;
			margin: 0;
			padding: 20px;
			background-color: #f4f4f4;
		}
		.container {
			max-width: 800px;
			margin: auto;
			background: white;
			padding: 20px;
			border-radius: 10px;
			box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
		}
		.blog {
			padding: 15px;
			border-bottom: 1px solid #ddd;
		}
		.blog:last-child {
			border-bottom: none;
		}
		.blog h2 {
			margin: 0 0 10px;
			color: #333;
		}
		.blog p {
			color: #666;
		}
		.blog a {
			color: #007BFF;
			text-decoration: none;
		}
		.blog a:hover {
			text-decoration: underline;
		}
	</style>
</head>
<body>
	<div class="container">
		<h1>All Blogs</h1>
		{}
		</div>
	</div>
</body>
</html>
)";

constexpr auto BLOG_TEMPLATE =
	R"(
		<div class="blog">
			<h2><a href="#">{}</a></h2>
			<p>{}</p>
		</div>
)";

namespace infrastructure {

HTTPServer::~HTTPServer() = default;

std::unique_ptr<HTTPServer> HTTPServer::create(
	uint16_t port,
	use_cases::UseCases& use_cases)
{
	const ohttp::HTTPServerConfig config {port, "0.0.0.0", 10, 10};

	auto route_request_handler = std::make_unique<ohttp::HTTPRouteRequestHandler>();

	route_request_handler->addRouteHandler(
		{ohttp::HTTPRequestType::Get, "/list"}, [&use_cases](const ohttp::IHTTPRequest& request) {
			auto blogs = use_cases.getPosts.execute();

			std::string blog_entries;
			for (const auto& blog : blogs) {
				blog_entries +=
					otools::StringFormat::format(BLOG_TEMPLATE, blog.title, blog.content);
			}

			return ohttp::HTTPServerResponse::createSingleBodyResponse(
				ohttp::HTTPStatus::OK,
				"plain/text",
				otools::StringFormat::format(HTML_TEMPLATE, blog_entries));
		});

	auto server = ohttp::HTTPFactory().createServer(std::move(route_request_handler), config);

	if (!server) {
		return {};
	}

	return std::unique_ptr<HTTPServer>(new HTTPServer {std::move(server)});
}

HTTPServer::HTTPServer(std::unique_ptr<ohttp::IHTTPServer> server)
	: server {std::move(server)}
{
}

void HTTPServer::start()
{
	server->start();
}

}
