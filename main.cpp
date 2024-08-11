#include <string>
#include <iostream>

#define C_LENGTH 6

typedef struct 
{
	std::string account_name;
	std::string account_id;
	std::string auth_code;
	std::string auth_secret;


}User;

void print_user(User user);
User create_user(std::string creds[]);

int main()
{
	std::string r[] = {"name", "123", "123456", "654321"};
	User user = create_user(r);
	print_user(user);
	return 0;
}

void print_user(User user)
{
	std::cout << "username=" << user.account_name << std::endl
		      << "account id=" << user.account_id << std::endl
		      << "auth code=" << user.auth_code << std::endl
		      << "auth secret=" << user.auth_secret << std::endl;
}

User create_user(std::string creds[])
{
	User user = {
		creds[0],
		creds[1],
		creds[2],
		creds[3]
	};

	return user;
}

void menu()
{
	whille(true)
	{

	}
}
