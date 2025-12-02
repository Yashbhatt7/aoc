#include<iostream>
#include<fstream>

std::string readFile(const std::string& path) {
    std::ifstream f(path);

    if (!f.is_open()) {
        std::cerr << "Error: cannot open file!" << path << "\n";
        return "";
    }

    std::string content;
    char ch;

    while (f.get(ch)) {
        content.push_back(ch);
    }

    return content;
}

int countZeroes(const std::string& str) {
    int pos = 50;
    int count2 = 0;

    for (int i = 0; i < str.size(); ++i) {
        std::string temp = "";

        if (str[i] == 'L') {
            ++i;
            while (i < str.size() && str[i] != '\n' && str[i] != '\r') {
                temp += str[i];
                ++i;
            }
            int n = std::stoi(temp);
            int leftOver = n % 100;
            int temp_pos = pos;

            pos = (pos - leftOver + 100) % 100;

            int fullCycles = n / 100;

            count2 += fullCycles;

            if (leftOver > 0 && temp_pos < leftOver) {
                ++count2;
            }
        } else if (str[i] == 'R') {
            ++i;
            while (i < str.size() && str[i] != '\n' && str[i] != '\r') {
                temp += str[i];
                ++i;
            }
            int n = std::stoi(temp);
            int leftOver = n % 100;
            int temp_pos = pos;

            pos = (pos + leftOver) % 100;

            int fullCycles = n / 100;

            count2 += fullCycles;

            if (leftOver > 0 && temp_pos + leftOver >= 100) {
                ++count2;
            }
        }
    }

    return count2;
}

int main() {
    std::string str = readFile("input.txt");

    if (str.empty()) {
        return 1;
    }

    std::cout << countZeroes(str);

    std::cin.get();
}

