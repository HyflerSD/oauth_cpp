#include <string>
#include <iostream>
#include <fstream>
#include <vector>

typedef struct
{
	std::string access_token;
	std::string resource_name;
	bool is_valid;
}UserTokens;

typedef struct 
{
	//for now client and auth/reso struct same between all
	std::string email;
	std::string password;
	std::string id;

}User;

typedef struct
{
	std::string client_id;
	std::vector<std::string> scope;
	//std::string callBackUrl;
}AuthRequest;



/**
* request auth code (send id, and scope, type code)
* request acces token (send auth code, id, secret, callback url)
* store access token
* request resource (retrieve recourse owner stuff)
*
*/



//std::string get_auth_code(AuthRequest& payload)
//void print_user(OauthAccount account);
//void print_account(OauthAccount account)
//OauthAccount create_account(std::string creds[])
//void display_menu()
//void menu()
//void store_access_token(std::string a_token, UserToken user)
