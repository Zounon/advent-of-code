#include <iostream>
#include <string>
#include <fstream>
#include <format>
#include <vector>

int main()
{
    // std::string input = "./sample";
    std::string input = "./input";
    std::ifstream file(input);

    std::string line{};

    int dial = 50;
    int land_on_zero_cnt = 0;
    int passed_by_zero_cnt = 0;

    std::vector<std::pair<int, int>> vals;
    while (std::getline(file, line)) {
        int direction = (line.substr(0,1) == "R") ? 1 : -1;
        int distance = std::stoi(line.substr(1, line.size()-1));
        vals.push_back({direction, distance});
    }

    int ans1{}, ans2{};
    for (auto [dir,dist] : vals) {
        for (int i=0; i<dist; i++) {
            dial += dir;
            if (dial < 0) {dial = 99;}
            if (dial > 99) {dial = 0;}
            if (dial == 0) {ans2++;}
        }
        if (dial == 0) {ans1++;}
    }
    std::cout << std::format("Day1: {}\n", ans1);
    std::cout << std::format("Day2: {}\n", ans2);
}