#pragma once

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class HttpListener{
    public:
        HttpListener(uri address);
        void GetHandler(http_request req);
        pplx::task<void> Open();
        pplx::task<void> Close();
    private:
        http_listener hl;
};