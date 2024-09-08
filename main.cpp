#include <string>
#include <iostream>
#include <fstream>
#include "auth_server.h"


const std::string redirect_uri = "someurl";
const std::string oauth_uri = "oauthuri";

int main()
{
	AuthServer* server = new AuthServer;
	//server->showUsers();
	User u;
	u.email = "email";
	u.password = "pa";
	u.id = "k";

	User u2;
	u2.email = "user7@example.com";
	u2.password = "ZAt2f2d0scrc";
	u2.id = "7";

	std::cout << server->authorize_user(u) << std::endl;
	std::cout << server->authorize_user(u2) << std::endl;

	OauthClient c;
	c.client_id = "i";
	c.client_secret = "sec";
	c.status = "s";
	c.scopes = "scopes";
	c.redirect_uri = "redier.come";

	OauthClient c2;
	c2.client_id = "wwTIQj2SYDP0TDGV";
	c2.client_secret = "M3XYY8GFBSiuNCulQX8dSI8NTPeXqAui";
	c2.status = "true";
	c2.scopes = "read_contacts";
	c2.redirect_uri = "www.xyz.com";

	std::cout << server->authorize_client(c) << std::endl;
	std::cout << server->authorize_client(c2) << std::endl;
	server->showClients();
	delete server;
	return 0;
}

