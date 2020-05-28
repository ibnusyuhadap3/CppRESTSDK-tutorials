#include <cpprest/filestream.h>
#include <cpprest/http_listener.h>

using namespace std;
using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handler(http_request req){
    json::value obj;
    obj["Title"] = json::value::string(U("Basic C++ Rest SDK: Handler HTTP Support"));
    stringstream_t stream;
    obj.serialize(stream);
    req.reply(status_codes::OK, obj);
}

int main(int argc, char *argv[]){
    string_t port = U("8080");
    string_t address = U("http://localhost:");
    address.append(port);
    uri_builder uri(address);
    uri.set_path("json"); // http://localhost:8080/json
    auto addr = uri.to_uri().to_string();
    http_listener listen(addr);
    listen.support(handler);
    listen.open().wait();
    cout << "Enter to exit" << endl;
    string line;
    getline(cin,line);
    listen.close().wait();
    cout << "Finish" << endl;
    return 0;
}
