#include <string>
#include <iostream>

#define C_LENGTH 6

/**
 * CLIENT
*/
typedef struct 
{
	//for now client and auth/reso struct same between all
	std::string email;
	std::string password;
	std::string id;

}User;

typedef struct
{
	std::string access_token;
	std::string resource_name;
	std::string expiry;
}UserTokens;

/**
 * AUTH SERVER
*/
typedef struct 
{
	std::string account_name;
	std::string account_id;
	std::string auth_code;
	std::string auth_secret;

}OauthAccount;

typedef struct 
{
	std::string account_id;
	std::string access_token;
	std::string scope;
	std::string expiry;

}OauthUserTokens;

/**
 * RESOURCE SERVER
*/




void menu();
void print_user(OauthAccount account);
User create_user(std::string creds[]);

void print_account(OauthAccount account)
{
	std::cout << "accountname=" << account.account_name << std::endl
		      << "account id=" << account.account_id << std::endl
		      << "auth code=" << account.auth_code << std::endl
		      << "auth secret=" << account.auth_secret << std::endl;
}

 OauthAccount create_account(std::string creds[])
{
	OauthAccount userAccount = {
		creds[0],
		creds[1],
		creds[2],
		creds[3]
	};

	return userAccount;
}

void display_menu()
{
	std::cout << "1)\n"
				 "2)\n"
				 "3)\n"
				 "4)\n"
				 "5)\n"
				 "6)\n"
				 "7)\n";
}

void menu()
{
	std::string input;
	std::cout << "Please Select an option";
	display_menu();
	std::cin >> input;
	do
	{
	}while(input != "7");
}

bool validate_user(const User& user)
{
	//check if user exits in users file
	return true;
}






int main()
{
	std::string r[] = {"name", "123", "123456", "654321"};
	menu();
	return 0;
}

