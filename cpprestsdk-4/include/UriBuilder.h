#pragma once

#include <cpprest/filestream.h>
#include <cpprest/uri_builder.h>

using namespace utility;
using namespace web;

class UriBuilder{
    public:
        UriBuilder(string_t address, string_t port);
        string_t GetUri(string_t path);
    private:
        uri_builder uri;
};