#include <string>
#include <iostream>
#include <fstream>
#include "auth_server.h"
#include <sstream>

/**
 * validate request for auth code (check client id and scope (maybe later))
 * generate authcode (check for duplicates)
 * send authcode back to callback url
 * validate access token request
 * generate access token
 * store access token
 * send access token
 *
*/

AuthServer::AuthServer()
{
	createUsers();
	createOauthClients();
}

void AuthServer::showUsers()
{
	for(auto& user: users)
	{
		std::cout << user.second.email << " ";
		std::cout << user.second.password << " ";
		std::cout << user.second.id << std::endl;
	}
}

void AuthServer::createUsers()
{
	std::ifstream file("../users.txt");
	if(!file.is_open())
	{
		std::cerr << "User file does not exit";
		exit(1);
	}

	std::string line;
	std::istringstream iss;
	std::string token;

	std::vector<std::string> wv;

	while(!file.eof())
	{
		getline(file, line);
		if(file.good())
		{
			iss.clear();
			iss.str(line);

			while(iss.good())
			{
				iss >> token;
				wv.push_back(token);
			}
			User u;
			u.id = wv[0];
			u.email = wv[1];
			u.password = wv[2];
			users[wv[0]] = u;
		wv.clear();
		}
	}
	file.close();
}

bool AuthServer::authorize_user(const User& user)
{
	if(users.find(user.id) == users.end())
	{
		return false;
	}
	return (user.password == users[user.id].password);
}

void AuthServer::createOauthClients()
{
	std::ifstream file("../oauth_clients.txt");

	if(!file.is_open())
	{
		std::cerr << "Error creating clients";
		exit(1);
	}
	std::string line;
	std::istringstream iss;
	std::string token;

	std::vector<std::string> wv;

	while(!file.eof())
	{
		getline(file, line);
		if(file.good())
		{
			iss.clear();
			iss.str(line);

			while(iss.good())
			{
				iss >> token;
				wv.push_back(token);
			}
			OauthClient c;
			c.client_id = wv[0];
			c.client_secret = wv[1];
			c.status = wv[2];
			c.scopes = wv[3];
			c.redirect_uri = wv[4];
			oauth_clients[wv[0]] = c;
			wv.clear();
		}
	}
	file.close();

}

bool AuthServer::authorize_client(const OauthClient& client)
{
	if(oauth_clients.find(client.client_id) == oauth_clients.end())
	{
		return false;
	}
	return (client.client_secret == oauth_clients[client.client_id].client_secret);
}


void AuthServer::showClients()
{
	for(auto& client: oauth_clients)
	{
		std::cout << client.second.client_id << " ";
		std::cout << client.second.client_secret << " ";
		std::cout << client.second.status << " ";
		std::cout << client.second.scopes<< " ";
		std::cout << client.second.redirect_uri << " " << std::endl;
	}
}

std::string AuthServer::generate_auth_code(const OauthClient client, const User user)
{
	return " ";
}

void AuthServer::store_access_token(std::map<std::string, std::string>& payload)
{
	return;
}

void AuthServer::revoke_access(int client_id)
{
	return;
}




