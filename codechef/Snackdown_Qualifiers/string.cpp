#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    std::string s;
    std::cin >> s;
    for (std::size_t i = 0, size = s.size(); i < size; i++) {
        std::cout << s.substr(0, i + 1) << std::endl;
    }

    return 0;
}