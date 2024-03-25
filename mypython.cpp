#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>

enum TokenType {
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    LITERAL,
    DELIMITER,
    COMMENT,
    INVALID
};

struct Token {
    TokenType type;
    std::string value;
};

bool isKeyword(const std::string& str) {
    std::vector<std::string> keywords = {
        "if", "else", "while", "for", "def", "return", "True", "False", "None"
    };
    return std::find(keywords.begin(), keywords.end(), str) != keywords.end();
}

bool isOperator(char c) {
    std::string operators = "+-*/%=><&|^~";
    return operators.find(c) != std::string::npos;
}

bool isDelimiter(char c) {
    std::string delimiters = "()[]{},.:;";
    return delimiters.find(c) != std::string::npos;
}

bool isLiteral(const std::string& str) {
    // Simplified check for literals (integers, floats, strings)
    if (str.empty()) return false;
    if (std::isdigit(str[0])) {
        for (char c : str) {
            if (!std::isdigit(c) && c != '.') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isIdentifier(const std::string& str) {
    if (str.empty()) return false;
    if (!std::isalpha(str[0]) && str[0] != '_') return false;
    for (char c : str) {
        if (!std::isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

std::vector<Token> tokenize(const std::string& code) {
    std::vector<Token> tokens;
    std::string currentToken;

    for (size_t i = 0; i < code.size(); ++i) {
        char c = code[i];
        
        // Skip whitespaces
        if (std::isspace(c)) {
            continue;
        }

        // Check for comments
        if (c == '#') {
            while (i < code.size() && code[i] != '\n') {
                ++i;
            }
            tokens.push_back({COMMENT, ""});
            continue;
        }

        currentToken += c;

        if (isOperator(c) || isDelimiter(c)) {
            if (!currentToken.empty()) {
                TokenType type = isKeyword(currentToken) ? KEYWORD :
                                 isLiteral(currentToken) ? LITERAL :
                                 isIdentifier(currentToken) ? IDENTIFIER :
                                 INVALID;
                tokens.push_back({type, currentToken});
                currentToken.clear();
            }
            
            if (isOperator(c)) {
                tokens.push_back({OPERATOR, std::string(1, c)});
            } else if (isDelimiter(c)) {
                tokens.push_back({DELIMITER, std::string(1, c)});
            }
        } else if (i == code.size() - 1) {
            TokenType type = isKeyword(currentToken) ? KEYWORD :
                             isLiteral(currentToken) ? LITERAL :
                             isIdentifier(currentToken) ? IDENTIFIER :
                             INVALID;
            tokens.push_back({type, currentToken});
        }
    }

    return tokens;
}

void printTokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        std::cout << "Type: ";
        switch (token.type) {
            case IDENTIFIER: std::cout << "Identifier"; break;
            case KEYWORD:    std::cout << "Keyword";    break;
            case OPERATOR:   std::cout << "Operator";   break;
            case LITERAL:    std::cout << "Literal";    break;
            case DELIMITER:  std::cout << "Delimiter";  break;
            case COMMENT:    std::cout << "Comment";    break;
            case INVALID:    std::cout << "Invalid";    break;
        }
        std::cout << ", Value: " << token.value << std::endl;
    }
}

int main() {
    std::string code = "def add(a, b):\n    return a + b\nprint(add(5, 10))";

    std::vector<Token> tokens = tokenize(code);
    printTokens(tokens);

    return 0;
}


int main(){
  std::ifstream myfile;
  myfile.open("example.py");
  std::string myline;
  if ( myfile.is_open() ) {
    while ( myfile ) { // equivalent to myfile.good()
      std::getline (myfile, myline);
      std::cout << myline << '\n';
      }
    }
  else {
    std::cout << "Couldn't open file\n";
  }
}
