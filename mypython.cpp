#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

enum TokenType {
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    LITERAL,
    COMMENT,
    NEWLINE,
    INDENT,
    DEDENT,
    INVALID
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
private:
    std::ifstream file;
    char currentChar;
    int indentLevel;
    std::vector<std::string> keywords = {"if", "else", "while", "for", "def", "return"};
    std::string operators = "+-*/%=(){}[]<>";
    std::string literals = "0123456789";
    std::string validIdentifierChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
    
    char getNextChar() {
        return file.get();
    }

    void skipWhitespace() {
        while (isspace(currentChar) && currentChar != '\n') {
            currentChar = getNextChar();
        }
    }

    Token getNextToken() {
        Token token;
        token.value = "";

        if (currentChar == EOF) {
            token.type = INVALID;
            return token;
        }

        if (currentChar == '\n') {
            token.type = NEWLINE;
            token.value += currentChar;
            currentChar = getNextChar();
            return token;
        }

        if (isspace(currentChar)) {
            skipWhitespace();
            return getNextToken();
        }

        if (currentChar == '#') {
            token.type = COMMENT;
            while (currentChar != '\n' && currentChar != EOF) {
                token.value += currentChar;
                currentChar = getNextChar();
            }
            return token;
        }

        if (std::find(operators.begin(), operators.end(), currentChar) != operators.end()) {
            token.type = OPERATOR;
            token.value += currentChar;
            currentChar = getNextChar();
            return token;
        }

        if (std::isdigit(currentChar)) {
            token.type = LITERAL;
            while (std::isdigit(currentChar) || currentChar == '.') {
                token.value += currentChar;
                currentChar = getNextChar();
            }
            return token;
        }

        if (std::find(validIdentifierChars.begin(), validIdentifierChars.end(), currentChar) != validIdentifierChars.end()) {
            while (std::find(validIdentifierChars.begin(), validIdentifierChars.end(), currentChar) != validIdentifierChars.end() ||
                   std::isdigit(currentChar)) {
                token.value += currentChar;
                currentChar = getNextChar();
            }

            if (std::find(keywords.begin(), keywords.end(), token.value) != keywords.end()) {
                token.type = KEYWORD;
            } else {
                token.type = IDENTIFIER;
            }

            return token;
        }

        token.type = INVALID;
        return token;
    }

public:
    Lexer(const std::string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            std::cerr << "Unable to open file\n";
            exit(1);
        }
        currentChar = getNextChar();
        indentLevel = 0;
    }

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;
        Token token;
        token.value = "";

        while (currentChar != EOF) {
            token = getNextToken();
            tokens.push_back(token);
        }

        file.close();
        return tokens;
    }
};

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
