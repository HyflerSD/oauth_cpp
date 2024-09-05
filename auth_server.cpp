#include <string>
#include <iostream>
#include <fstream>
#include "auth_server.h"

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

AuthSever();
//auth user first
bool authorize_user(const User& user)
{
	return false;
}
//then auth the client
bool authorize_client(const std::string client_id, const std::string client_secret, const std::string scopes)
{
	return false;
}

std::string generate_auth_code(const OauthClient client, const User user)
{
	return " ";
}
void store_access_token(std::map<std::string, std::string>& payload)
{
	return;
}
void revoke_access(int client_id)
{
	return;
}




