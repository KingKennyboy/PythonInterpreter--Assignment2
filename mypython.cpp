#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <fstream>

#include "scanner.h"
#include "parser.h"

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
    //std::string code = "a = 10";
    //Scanner s(code);
    //s.printTokens();

    std::string code = openFile("testcases/in10.py");
    //std::cout << code;
    Scanner scan(code);
    scan.printTokens();

    //Parser parseObject(s.getTokens());
    //parseObject.printNodes();

    return 0;
}
