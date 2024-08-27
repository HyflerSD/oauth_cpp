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

std::string* generate_auth_code(const int payload);
void store_access_token(std::string a_token, int user);
bool v_auth_request(const void** user, std::string flag);
bool validate_client(const User& user);




