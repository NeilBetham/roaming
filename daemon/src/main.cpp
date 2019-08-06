#include <oatpp/web/server/HttpConnectionHandler.hpp>

#include <oatpp/network/server/Server.hpp>
#include <oatpp/network/server/SimpleTCPConnectionProvider.hpp>

void run() {
	auto router = oatpp::web::server::HttpRouter::createShared();
	auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);
	auto connectionProvider = oatpp::network::server::SimpleTCPConnectionProvider::createShared(8000);

	oatpp::network::server::Server server(connectionProvider, connectionHandler);

	OATPP_LOGI("roaming", "Server running on port %s", connectionProvider->getProperty("port").getData());

	server.run();
}


int main() {
	oatpp::base::Environment::init();

	run();

	oatpp::base::Environment::destroy();

	return 0;
}
