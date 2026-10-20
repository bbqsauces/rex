#include <emscripten/emscripten.h> // ignore error
#include <cstring>
//#include "functions.cpp"
#include <string>

extern int add(int a, int b);
extern int subtract(int a, int b);
extern std::string hello();
extern std::string scramble(std::string inputstring);


extern "C"{
    EMSCRIPTEN_KEEPALIVE
    int bridge_add(int a, int b){
        return add(a,b);
    }
    EMSCRIPTEN_KEEPALIVE
    int bridge_sub(int a, int b){
        return subtract(a,b);
    }
    EMSCRIPTEN_KEEPALIVE
    char* bridge_hello(){
        return strdup(hello().c_str());
    }
    EMSCRIPTEN_KEEPALIVE
    const char* bridge_scramble(char* inputstring){
        static std::string result;
        result = scramble(inputstring);
        return result.c_str();
    }
}
