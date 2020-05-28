#include "../include/Server.h"

Server::Server(string_t address, string_t port, string_t path):_uri(address, port),_listener(_uri.GetUri(path)){
    _listener;
}