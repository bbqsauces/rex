em++ functions-bridge.cpp functions.cpp -o module.js -O3 -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]'
python3 -m http.server 8000