#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>


int main() {
    std::vector<std::vector<char>> data;
    std::ifstream file("./input");
    // std::ifstream file("./sample");


    std::string line{};
    std::vector<char> chars;
    while (std::getline(file, line)) {
        chars.clear();
        for (char c : line) {
            chars.push_back(c);
        }
        data.push_back(chars);
    }

    int num_rows = static_cast<int>(data.size());
    int num_cols = static_cast<int>(data[0].size());


    // Given char 'X' is at pos y,x give the offset_arr to match the rest of the str
    std::vector<std::vector<std::pair<int,int>>> offset_arr  {
        {{0,1}, {0,2}, {0,3}}, // XMAS
        {{0,-1}, {0,-2}, {0,-3}}, // backwards
        {{1,0}, {2,0}, {3,0}}, // down
        {{-1,0}, {-2,0}, {-3,0}}, // up
        {{1,1}, {2,2}, {3,3}}, // diag down-right
        {{1,-1}, {2,-2}, {3,-3}}, // diag down-left
        {{-1,1}, {-2,2}, {-3,3}}, // diag up-right
        {{-1,-1}, {-2,-2}, {-3,-3}} // diag up-left
    };

    std::vector<std::pair<int,int>> MAS_offsets  {
        {{-1,-1}, {-1,1}, {1,1}, {1,-1}}, // x-MAS
    };

    auto isInBounds = [&](std::pair<int,int> point) {
        auto [row,col] = point;
        return (0 <= row && row < num_rows && 0 <= col && col < num_cols);
    };

    int xmas_count = 0;
    int x_mas_count = 0;
    std::vector<std::pair<int,int>> points;
    for (auto row_idx = 0; row_idx<num_rows; row_idx++) {
        for (auto col_idx = 0; col_idx<num_cols; col_idx++) {

            if (data[row_idx][col_idx] == 'X') { // PART 1

            for (auto offsets: offset_arr) {
                points.clear();
                for (auto offset: offsets) {
                    points.push_back({row_idx + offset.first, col_idx + offset.second});
                }

                auto valid_search = std::ranges::all_of(points, [&](auto p){return isInBounds(p);});
                if (!valid_search) {continue;}

                if (data[points[0].first][points[0].second] == 'M' &&
                    data[points[1].first][points[1].second] == 'A' &&
                    data[points[2].first][points[2].second] == 'S' 
                    ) {
                        xmas_count++;
                    }
                }

            } else if (data[row_idx][col_idx] == 'A') { // PART 2
                points.clear();
                for (auto offset: MAS_offsets) {
                    points.push_back({row_idx + offset.first, col_idx + offset.second});
                }
                auto valid_search = std::ranges::all_of(points, [&](auto p){return isInBounds(p);});
                if (!valid_search) {continue;}


                char tl = data[points[0].first][points[0].second];
                char tr = data[points[1].first][points[1].second];
                char br = data[points[2].first][points[2].second];
                char bl = data[points[3].first][points[3].second];

                bool tl_br = (tl == 'M' && br == 'S' || tl == 'S' && br == 'M');
                bool tr_bl = (tr == 'M' && bl == 'S' || tr == 'S' && bl == 'M');

                if (tl_br && tr_bl) {x_mas_count++;}
            }
        }
    }
    // std::cout << num_cols << " "  << num_rows << std::endl;
    std::cout << "Part1: " << xmas_count << std::endl;
    std::cout << "Part2: " << x_mas_count << std::endl;
}