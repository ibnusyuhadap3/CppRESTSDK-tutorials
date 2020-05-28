#include "include/App.h"

using namespace std;

int main(int argc, char *argv[]){
    App run("http://localhost:","8080","json");
    cout << "Finish" << endl;
    return 0;
}
