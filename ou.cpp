#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ifstream hex_file("hex_data.txt");
    std::string hex_data;
    hex_file >> hex_data;
    std::vector<char> data;
    for (int i = 0; i < hex_data.size(); i += 5) {
        int value = std::stoul(hex_data.substr(i + 2, 2), nullptr, 16);
        data.push_back((char)value);
    }
    std::ofstream file("output.gz", std::ios::binary);
    file.write(data.data(), data.size());
    file.close();
    return 0;
}