cmake_minimum_required(VERSION 3.10)
project(OAuthCPP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
	auth_server.cpp
	client.cpp
)

add_executable(oauth_cpp ${SOURCES})
