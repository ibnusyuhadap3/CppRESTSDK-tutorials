#include <cpprest/filestream.h>
#include <cpprest/http_listener.h>

using namespace std;
using namespace utility;
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

HttpListener::HttpListener(uri address):hl(address){
    hl.support(std::bind(&HttpListener::GetHandler,this,std::placeholders::_1));
}

void HttpListener::GetHandler(http_request req){
    json::value obj;
    obj["Title"] = json::value::string(U("Build Server Application Class of C++ Rest SDK"));
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

class UriBuilder{
    public:
        UriBuilder(string_t address, string_t port);
        string_t GetUri(string_t path);
    private:
        uri_builder uri;
};

UriBuilder::UriBuilder(string_t address, string_t port):uri(address.append(port)){}
string_t UriBuilder::GetUri(string_t path){
    uri.set_path(path);
    return uri.to_uri().to_string();
}

int main(int argc, char *argv[]){
    UriBuilder uri(U("http://localhost:"),U("8080"));
    HttpListener listen(uri.GetUri("json"));
    listen.Open().wait();
    listen.Close().wait();

    cout << "Finish" << endl;
    return 0;
}
