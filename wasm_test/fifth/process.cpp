#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <emscripten/bind.h>


std::vector<uint8_t> invertImageBuffer(std::vector<uint8_t>& imageBytes) {
    std::vector<uint8_t> invertedBytes = imageBytes;
    for (size_t i = 0; i < imageBytes.size(); ++i) {
        // Option A: Direct Math
        invertedBytes[i] = 255 - invertedBytes[i];
    }
    return invertedBytes;
}

EMSCRIPTEN_BINDINGS(module){
    emscripten::register_vector<uint8_t>("VectorBytes");
    emscripten::function("invertImageBuffer",&invertImageBuffer);
}