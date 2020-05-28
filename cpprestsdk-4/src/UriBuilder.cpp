#include "../include/UriBuilder.h"

UriBuilder::UriBuilder(string_t address, string_t port):uri(address.append(port)){}
string_t UriBuilder::GetUri(string_t path){
    uri.set_path(path);
    return uri.to_uri().to_string();
}