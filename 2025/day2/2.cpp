#include<iostream>
#include <string>
#include<vector>
#include<fstream>

std::vector<std::pair<std::string, std::string>> readFile(const std::string& path) {
    std::ifstream f(path);

    if (!f.is_open()) {
        std::cerr << "Error: cannot open file!" << path << "\n";
        return {};
    }

    std::string firstN;
    std::string secondN;
    std::string current;
    std::vector<std::pair<std::string, std::string>> pairs;
    char ch;

    while (f.get(ch)) {
        if (ch == '-') {
            firstN = current;
            current.clear();
        }
        else if (ch == ',') {
            secondN = current;
            current.clear();

            if (firstN.size() % 2 == 0 || secondN.size() % 2 == 0) {
                pairs.emplace_back(firstN, secondN);
                // std::cout << firstN << ", " << secondN << "\n";
            }
            firstN.clear();
            secondN.clear();
        } else {
            current += ch;
        }
    }

    if (!current.empty() && !firstN.empty()) {
        secondN = current;

        if (firstN.size() % 2 == 0 || secondN.size() % 2 == 0) {
            pairs.emplace_back(firstN, secondN);
            // std::cout << firstN << ", " << secondN << "\n";
        }
    }

    return pairs;
}

long long invalidID(const std::vector<std::pair<std::string, std::string>>& pairs) {
    using u128 = __uint128_t;
    u128 sumOfInvalidIDs = 0;

    for (size_t i = 0; i < pairs.size(); ++i) {
        long long num1 = std::stoll(pairs[i].first);
        long long num2 = std::stoll(pairs[i].second);

        while (num1 <= num2) {
            std::string str = std::to_string(num1);
            long long half = str.size() / 2;
            std::string firstHalf = str.substr(0, half);
            std::string secondHalf = str.substr(half);

            long long current = std::stoll(firstHalf + secondHalf);

            if (firstHalf == secondHalf) {
                // std::cout << str << "\n";
                sumOfInvalidIDs += current;
                // std::cout << current << "\n";
            }

            int firstNum = std::stoll(firstHalf);
            firstNum++;
            std::string newHalf = std::to_string(firstNum);

            if (newHalf.size() != (size_t)half) {
                break;
            }

            num1 = std::stoll(newHalf + newHalf);
        }
    }

    return sumOfInvalidIDs;
}

int main() {
    std::vector<std::pair<std::string, std::string>> pairs = readFile("input.txt");
    // std::vector<std::pair<std::string, std::string>> pairs = readFile("input1.txt");

    if (pairs.empty()) {
        return 1;
    }

    std::cout << invalidID(pairs);

    std::cin.get();
}

