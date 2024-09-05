#include <string>
#include <iostream>
#include <fstream>
#include "auth_server.h"


const std::string redirect_uri = "someurl";
const std::string oauth_uri = "oauthuri";

int main()
{
	AuthServer* server = new AuthServer;
	delete server;
	return 0;
}

