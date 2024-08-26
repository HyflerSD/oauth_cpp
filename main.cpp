#include <string>
#include <iostream>
#include <fstream>
#define C_LENGTH 6



const redirect_uri = "someurl";
const oauth_uri = "oauthuri";

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
	bool is_valid;
}UserTokens;

/**
 * AUTH SERVER
*/
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


typedef struct
{
	std::string client_id;
	vector<std::string> scope;
	//std::string callBackUrl;
}AuthRequest;


/**
 * RESOURCE SERVER
*/



std::string get_auth_code(AuthRequest& payload)
{
	//Generate url to send
	std::string* response = generate_auth_code(payload);
	if(!response)
	{
		std::cout << "Error occurred somehow" << std::endl;
	}
	return *response;
}



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
		creds[3],
		creds[4]
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


std::string* generate_auth_code(const AuthRequest& payload)
{
	if(v_auth_request(payload))
	{
	}
}

void store_access_token(std::string a_token, UserToken user)
{
	//open user file and store token
	std::fstream file("user_tokens.txt", std::ios::in);
	if(!file.is_open())
	{
		std::cerr << "need to create user tokens files or something " << std::endl;
	}

	while(file >> token)
	{
		if(token == user.user_id)
		{
			//here update the file and return
			return;
		}
	}
	//add new user to file if you don't find them

	file << user.user_id << " " << a_token << std::endl;
	file.close();
}


//Maybe use a void** to take in either a ouathAccount or a request and like that stufff..
bool v_auth_request(const void** user, std::string flag)
{

	switch(flag)
	{
		case "code":
		break;
		case "account":
		break;
		default:
			return false;
	}
	std::fstream file("a_account.txt", std::ios::in);
	if(!file.is_open())
	{
		std::cerr << "Error opening file!";
		return false;
	}

	std::string token;
	int c = 0;
	std::string arr[2];
	while(file >> token)
	{
		if(c > 1)
		{
			c = 0;
			std::cout << arr[0] << arr[1] << std::endl;
			if(user.account_id == arr[0] && user.status == "true")
			{
				break;
			}
		}

		arr[c] = token;
		c++;
	}
	file.close();
	return (user.account_id == arr[0] && user.status == "true");
}


bool validate_user(const User& user)
{
	std::fstream file("a_users.txt", std::ios::in);
	if(!file.is_open())
	{
		std::cerr << "Error opening file!";
		return false;
	}

	std::string token;
	int c = 0;
	std::string arr[2];
	while(file >> token)
	{
		if(c > 1)
		{
			c = 0;
			std::cout << arr[0] << arr[1] << std::endl;
			if(user.email == arr[0] && user.password == arr[1])
			{
				break;
			}
		}

		arr[c] = token;
		c++;
	}
	file.close();
	return (user.email == arr[0] && user.password == arr[1]);
}






int main()
{
	User user;
	user.email = "michael@gmail.com";
	user.password = "12345";
	user.id = "5";
	std::cout << validate_user(user) << std::endl;
	return 0;
}

