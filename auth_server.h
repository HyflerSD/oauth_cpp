#include <string>
#include <iostream>
#include <fstream>

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
	std::string access_token;
	std::string resource_name;
	bool is_valid;
}UserTokens;

typedef struct 
{
	std::string account_id;
	std::string status;
	std::string account_name;
	std::string auth_code; // don't need this here bro 
	std::string auth_secret;

}OauthAccount;

typedef struct 
{
	std::string user_email;
	std::string account_id;
	std::string access_token;
	std::string scope;
	std::string expiry;

}OauthUserTokens;

std::string* generate_auth_code(const int payload);
void store_access_token(std::string a_token, int user);
bool v_auth_request(const void** user, std::string flag);
bool validate_client(const User& user);




