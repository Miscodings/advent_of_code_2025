#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Range {
    long long start;
    long long end;
};

int main() {
    ifstream input("D:\\Downloads\\advent_of_code_2025\\day_5\\input.txt");

    if (!input.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    vector<Range> ranges;
    string line;
    long long freshCount = 0;
    bool readingRanges = true;

    while (getline(input, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        if (line.empty()) {
            readingRanges = false;
            continue;
        }

        if (readingRanges) {
            size_t dashPos = line.find('-');
            long long start = stoll(line.substr(0, dashPos));
            long long end = stoll(line.substr(dashPos + 1));
            ranges.push_back({start, end});
        } else {
            long long id = stoll(line);
            bool isFresh = false;
            for (const auto& range : ranges) {
                if (id >= range.start && id <= range.end) {
                    isFresh = true;
                    break;
                }
            }
            if (isFresh) {
                freshCount++;
            }
        }
    } 
    
    cout << "Total Fresh Items: " << freshCount << endl;
    return 0;
}