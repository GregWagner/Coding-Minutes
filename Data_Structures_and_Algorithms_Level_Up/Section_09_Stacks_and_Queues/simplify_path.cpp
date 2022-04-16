/*
 */
#include <iostream>
#include <sstream>
#include <vector>

std::string simplifyPath(std::string path) {
    std::istringstream iss(path);
    std::vector<std::string> tokens;

    // Tokenisation and filtering
    std::string token;
    while (getline(iss, token, '/')) {
        if (token == "." || token == "") {
            continue;
        }
        tokens.push_back(token);
    }

    // handle ..
    std::vector<std::string> stack;
    if (path[0] == '/') {
        // denote absolute path
        stack.push_back("");
    }

    for (auto t : tokens) {
        if (t == "..") {
            // handle relative path
            if (stack.size() == 0 || stack[stack.size() - 1] == "..") {
                stack.push_back("..");
            } else if (stack[stack.size() - 1] != "") {
                // remove absolute path indicator
                stack.pop_back();
            }
        } else {
            stack.push_back(t);
        }
    }

    // if single element
    if (stack.size() == 1 && stack[0] == "") {
        return "/";
    }

    // combine all elements in stack to get the answer
    std::ostringstream oss;
    int i {};
    for (auto t : stack) {
        if (i != 0) {
            oss << "/";
        }
        ++i;
        oss << t;
    }
    return oss.str();
}

int main() {
    // output sb /x/z/c
    std::string path = "/../x/y/../z/././w/a///../../c/./";
    std::cout << simplifyPath(path) << '\n';
}
