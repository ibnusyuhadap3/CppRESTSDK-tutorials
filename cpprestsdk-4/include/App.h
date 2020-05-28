#pragma once

#include "Server.h"

class App{
    public:
        App(string_t address, string_t port, string_t path){
            Server serve(address,port,path);
            serve.listen().Open().wait();
            serve.listen().Close().wait();
        }
};