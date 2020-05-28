#include "../include/HttpListener.h"

using namespace utility;
using namespace std;

HttpListener::HttpListener(uri address):hl(address){
    hl.support(std::bind(&HttpListener::GetHandler,this,std::placeholders::_1));
}

void HttpListener::GetHandler(http_request req){
    json::value obj;
    obj["Title"] = json::value::string(U("Build Simple Server App C++ Rest SDK"));
    stringstream_t stream;
    obj.serialize(stream);
    req.reply(status_codes::OK, obj);
}

pplx::task<void> HttpListener::Open(){
    return hl.open();
}

pplx::task<void> HttpListener::Close(){
    cout << "Enter to exit" << endl;
    string line;
    getline(cin,line);
    return hl.close();
}
