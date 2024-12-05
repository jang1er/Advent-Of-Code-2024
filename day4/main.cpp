#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

int main() {
    // read input and transform into matrix
    std::vector<std::vector<char>> matrix;
    std::ifstream input("input.txt");
    //std::istringstream input;
    /*input.str(R"(MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX)");*/
    std::string line;
    while (std::getline(input, line)) {
        std::vector<char> row;
        for(auto c : line) {
            row.push_back(c);
        }
        row.shrink_to_fit();
        matrix.push_back(row);
    }
    input.close();
    matrix.shrink_to_fit();
    std::cout << matrix.size() << " " << matrix[0].size() <<std::endl;
    // search through
    int sum = 0;
    unsigned int size_y = matrix.size();
    for(int i = 0; i < matrix.size(); i++) {
        unsigned int size_x = matrix[i].size();
        for(int j = 0; j < matrix[i].size(); j++) {
            // check horizontal
            if(j < size_x - 3 && matrix[i][j] == 'X' && matrix[i][j+1] == 'M' && matrix[i][j+2] == 'A' && matrix[i][j+3] == 'S' )++sum;
            if(j < size_x - 3 && matrix[i][j] == 'S' && matrix[i][j+1] == 'A' && matrix[i][j+2] == 'M' && matrix[i][j+3] == 'X' )++sum;
            // check vertical
            if(i < size_y - 3 && matrix[i][j] == 'X' && matrix[i+1][j] == 'M' && matrix[i+2][j] == 'A' && matrix[i+3][j] == 'S' )++sum;
            if(i < size_y - 3 && matrix[i][j] == 'S' && matrix[i+1][j] == 'A' && matrix[i+2][j] == 'M' && matrix[i+3][j] == 'X' )++sum;
            // check diagonal 1
            if(j < size_x - 3 && i < size_y - 3 && matrix[i][j] == 'X' && matrix[i+1][j+1] == 'M' && matrix[i+2][j+2] == 'A' && matrix[i+3][j+3] == 'S' )++sum;
            if(j < size_x - 3 && i < size_y - 3 && matrix[i][j] == 'S' && matrix[i+1][j+1] == 'A' && matrix[i+2][j+2] == 'M' && matrix[i+3][j+3] == 'X' )++sum;
            // check diagonal 2
            if(j > 2 && i < size_y - 3 && matrix[i+3][j-3] == 'X' && matrix[i+2][j-2] == 'M' && matrix[i+1][j-1] == 'A' && matrix[i][j] == 'S' )++sum;
            if(j > 2 && i < size_y - 3 && matrix[i+3][j-3] == 'S' && matrix[i+2][j-2] == 'A' && matrix[i+1][j-1] == 'M' && matrix[i][j] == 'X' )++sum;
        }
    }
    std::cout << sum << std::endl;
    sum = 0;
    // second phase
    for(int i = 0; i < matrix.size(); i++) {
        unsigned int size_x = matrix[i].size();
        for(int j = 0; j < matrix[i].size(); j++) {
            if(i < 1 || i > size_y - 2)continue;
            if(j < 1 || j > size_x - 2)continue;
            // check the x pattern

            // check middle
            if(matrix[i][j] != 'A')continue;
            // check for correct rest position
            if(!(matrix[i-1][j-1] == 'M' && matrix[i+1][j+1] == 'S' || matrix[i-1][j-1] == 'S' && matrix[i+1][j+1] == 'M'))continue;
            if(!(matrix[i+1][j-1] == 'M' && matrix[i-1][j+1] == 'S' || matrix[i+1][j-1] == 'S' && matrix[i-1][j+1] == 'M'))continue;
            ++sum;
        }
    }
    std::cout << sum << std::endl;

    return 0;
}
