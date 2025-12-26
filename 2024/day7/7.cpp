#include <iostream>
#include <ranges>
#include <string>
#include <fstream>
#include <vector>
#include <string_view>
#include <sstream>

int main() {

    // std::ifstream file("sample");
    std::ifstream file("./input");
    std::string line{};

    long p1_count = 0;
    long p2_count = 0;

    while (std::getline(file, line)) {
        long start = stol(line.substr(0, line.find(':')));
        line = line.substr(line.find(':')+2);
        std::vector<long> vals;
        std::string val{};
        for (auto c : line) {
            if (c == ' ') {
                vals.push_back(stol(val));
                val.clear();
            } else {
                val.push_back(c);
            }
        }
        vals.push_back(stol(val));


        // std::cout << start << " : ";
        // for (auto val : vals) {
        //     std::cout << val << ' ';
        // }
        // std::cout << std::endl;


        auto f1 = [](this auto&& self, long val, const std::vector<long>& vals, int idx, long og_val) {
            if (idx == vals.size()) {return val == og_val;}
            if (val > og_val) {return false;}

            long v = vals[idx];

            return self(val*v, vals, idx+1, og_val) || self(val+v, vals, idx+1, og_val);
        };

        auto f2 = [](this auto&& self, long val, const std::vector<long>& vals, long idx, long og_val) {
            if (idx == vals.size()) {return val == og_val;}
            if (val > og_val) {return false;}

            long v = vals[idx];
            long val_cat = stol(std::to_string(val) + std::to_string(v));

            return (
                self(val*v, vals, idx+1, og_val) || 
                self(val+v, vals, idx+1, og_val) ||
                self(val_cat, vals, idx+1, og_val));
        };

        if (f1(1, vals, 0, start)) {
            p1_count += start;
            p2_count += start;
        } else if (f2(1, vals, 0, start)) {
            p2_count += start;
        }

    }

    std::cout << "Part 1: " << p1_count << std::endl;
    std::cout << "Part 2: " << p2_count << std::endl;
}