#include<iostream>
#include<fstream>

int countWhichFlore(std::string str) {
    int flore = 0;
    int cal1 = 0;
    int cal2 = 0;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            cal1 += 1;
        } else {
            cal2 += 1;
        }
    }

    flore = cal1 - cal2;

    return flore;
}

int countPosition(std::string str) {
    int pos = 0;
    int cal1 = 0;
    int cal2 = 0;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            cal1 += 1;
        } else {
            cal2 += 1;
        }
        if (cal2 > cal1) {
            return i + 1;
        }
    }

    return 0;
}

int main() {
    std::ifstream f("input.txt");

    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }

    std::string s;
    std::string str;

    while (getline(f, s)) {
        str += s;
    }

    // std::cout << countWhichFlore(str);
    std::cout << countPosition(str);

    std::cin.get();
}
