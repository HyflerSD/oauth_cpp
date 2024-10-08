#ifndef _AUTH_SERVER_
#define _AUTH_SERVER_
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

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

typedef struct 
{
	std::string email;
	std::string password;
	std::string id;

}User;

typedef struct
{
	std::string client_id;
	std::string user_id;
	std::string scopes;
	std::string auth_code;
	std::string expires;
}TempAuthCodes;

typedef struct 
{
	std::string client_id;
	std::string client_secret;
	std::string status;
	std::string scopes;
	std::string redirect_uri;

}OauthClient;

typedef struct 
{
	std::string user_id;
	std::string client_id;
	std::string access_token;
	std::string scope;
	std::string expires;

}OauthUserTokens;

class AuthServer
{

public:
	std::map<std::string, OauthClient> oauth_clients;
	std::map<std::string, User> users;
	std::map<std::string, std::vector<TempAuthCodes>> temp_auth_codes;
	std::vector<OauthUserTokens> oauth_users;
	std::string host;

	AuthServer();
	//auth user first
	void createUsers();
	void showUsers();
	void createOauthClients();
	void showClients();
	bool authorize_user(const User& user);
	void createOauthClients(std::ifstream* file);
	//then auth the client
	bool authorize_client(const OauthClient& client);
	std::string generate_auth_code(const OauthClient client, const User user);
	void store_access_token(std::map<std::string, std::string>& payload);
	void revoke_access(int client_id);
	~AuthServer(){};

};

#endif
