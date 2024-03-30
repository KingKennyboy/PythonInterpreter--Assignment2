#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <fstream>

#include "tokenizer.h"

std::string openFile(std::string filename) {
    std::ifstream file;
    file.open(filename);

    std::string contents;
    while (file.good()) {
        char c;
        file.get(c);
        contents += c;
    }

    file.close();
    return contents;
}

// Main function
int main() {
    //std::string code = "def add(a, b):\n    return a + b\nprint(add(5, 10))";
    //Scanner s(code);
    //s.printTokens();

    std::string code = openFile("testcases/in10.py");
    //std::cout << code;
    Scanner scan(code);
    scan.printTokens();

    return 0;
}
