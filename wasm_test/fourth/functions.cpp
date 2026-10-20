#include <string>
#include <stdlib.h>
#include <algorithm>
#include <random>

int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

std::string hello(){
    return "hello!";
}

std::string scramble(std::string inputstring){
    //std::random_device random;
    //std::mt19937 g(random());
    //std::shuffle(inputstring.begin(), inputstring.end(),g);
    return inputstring;
}

int main(){
    
    return 0;
}