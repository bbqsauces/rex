#include <iostream>
#include <emscripten/emscripten.h>
#include <stdio.h>
//#include <string>

extern "C" {
EMSCRIPTEN_KEEPALIVE
char* printshit(){
    return "hello\n";
}

}