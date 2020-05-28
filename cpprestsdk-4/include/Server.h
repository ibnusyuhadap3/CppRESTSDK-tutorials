#pragma once

#include "UriBuilder.h"
#include "HttpListener.h"

class Server{
    public:
        Server(string_t address, string_t port, string_t path);
        HttpListener & listen(){return this->_listener;}
    private:
        UriBuilder _uri;
        HttpListener _listener;
};