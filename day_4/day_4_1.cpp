#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ifstream input("D:\\Downloads\\advent_of_code_2025\\day_4\\input.txt");

    if (!input.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    vector<string> grid;
    string line;
    
    while (getline(input, line)) {
        grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();

    long long accessibleCount = 0;
    
    int dr[] = {-1, -1, -1,  0,  0,  1, 1, 1};
    int dc[] = {-1,  0,  1, -1,  1, -1, 0, 1};
    
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == '@') {
                int paperNeighbors = 0;

                for (int i = 0; i < 8; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '@') {
                        paperNeighbors++;
                    }
                }

                if (paperNeighbors < 4) {
                    accessibleCount++;
                }
            }
        }
    }

    cout << "Total Accessible Cells: " << accessibleCount << endl;
    return 0;
}