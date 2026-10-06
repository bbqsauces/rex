#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <variant>

enum class Type{
    Operator,
    Number,
    Dummy
};

struct Token{
    Type type;
    std::variant<float, char> content;
    Token(Type _type, std::variant<float, char> _content){
        type = _type; // OPERATOR or NUMBER
        content = _content;
    }
    Token();
};

void addToken(std::vector<Token>& _tokens, std::string& _token){
    Type temp;
    Token newtoken = Token(Type::Dummy, 'b');
    std::variant<float, char> content;

    // need to fix this try catch because its wrong and broken and stupid
    try{
        float d = std::stod(_token);
        temp = Type::Number;
        content = d;
    }
    catch (const std::invalid_argument &e){
        char c = _token[0];
        temp = Type::Operator;
        content = c;
    }
    newtoken = Token(temp, content);
    _tokens.push_back(newtoken);
};


int main(){
    std::string input = "13+25+31+4+   5 = 1203";
    std::vector<Token> tokens;
    std::string current;
    //wchar_t 
    std::string operators = "=+-*/";

    for (char c : input){
        if (std::isdigit(c) || c == '.' ){
            if (current.length() != 0 && operators.find(current) != std::string::npos ){
                addToken(tokens, current);
                current = "";
            }
            current += c;
            continue;
        }
        else if (operators.find(c) != std::string::npos ) {
            if (current.length() != 0){
                addToken(tokens, current);
                current = "";
            }
            current += c;
            continue;
        }
    }
    
    addToken(tokens,current);
    current = "";

    for (auto t : tokens){
        std::cout << "Type: ";
        if (t.type == Type::Operator){
            std::cout << "Operator";
        }
        if (t.type == Type::Dummy){
            std::cout << "Dummy";
        }
        else{
            std::cout << "Number";
        }
        std::cout << " : ";
        std::visit([](const auto& x) { std::cout << x << "\n"; }, t.content);
        std::cout << std::endl;
    }
    std::cout << "hi i work" << std::endl;

    return 0;
}