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
	std::ifstream file("../users.txt");
	if(!file.is_open())
	{
		std::cerr << "User file does not exit";
	}

	createUsers(&file);
	file.close();

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

void AuthServer::createUsers(std::ifstream* file)
{
	std::string line;
	std::istringstream iss;
	std::string token;

	std::vector<std::string> wv;

	while(!file->eof())
	{
		getline(*file, line);
		if(file->good())
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

}

bool AuthServer::authorize_user(const User& user)
{
	std::ifstream file("users.txt");
	if(!file.is_open())
	{
		std::cerr << "File does not exist!";
		return false;
	}

	std::string line;
	while(getline(file, line))
	{
		std::cout << line;
	}
	return true;

}

bool AuthServer::authorize_client(const std::string client_id, const std::string client_secret, const std::string scopes)
{
	return false;
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




