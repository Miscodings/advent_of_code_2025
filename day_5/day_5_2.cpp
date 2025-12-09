#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


int main() {
    ifstream input("D:\\Downloads\\advent_of_code_2025\\day_5\\input.txt");

    if (!input.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    vector<pair<long long, long long>> ranges;
    bool readingRanges = true;
    string line;

    while (getline(input, line)) {
        if (line.empty()) break;

        size_t dashPos = line.find('-');
        long long start = stoll(line.substr(0, dashPos));
        long long end = stoll(line.substr(dashPos + 1));
        ranges.push_back({start, end});
    }

    sort(ranges.begin(), ranges.end());

    long long freshCount = 0;
    long long currStart = ranges[0].first;
    long long currEnd = ranges[0].second;

    for (int i = 1; i < ranges.size(); ++i) {
        auto [s, e] = ranges[i];
        if (s <= currEnd + 1) {
            currEnd = max(currEnd, e);
        } else {
            freshCount += (currEnd - currStart + 1);
            currStart = s;
            currEnd = e;
        }
    }

    freshCount += (currEnd - currStart + 1);
    
    cout << "Total Fresh Items: " << freshCount << endl;
    return 0;
}

// this method would have worked if the numbers were way smaller but because the ranges are so huge, it was inefficient.

// #include <fstream> 
// #include <string> 
// #include <iostream> 
// #include <vector> 
// #include <sstream> 
// #include <algorithm> 

// using namespace std; 

// int main() { 
//     ifstream input("D:\\Downloads\\advent_of_code_2025\\day_5\\input.txt"); 
//     if (!input.is_open()) { 
//         cerr << "Error: Unable to open file." << endl; 
//         return 1; 
//     } 
    
//     vector<long long> found; 
//     bool readingRanges = true; 
//     string line; 
//     long long freshCount = 0; 
    
//     while (getline(input, line)) { 
//         if (!line.empty() && line.back() == '\r') { 
//             line.pop_back(); 
//         }
        
//         if (line.empty()) { 
//             readingRanges = false; 
//             continue; 
//         } 
        
//         if (readingRanges) { 
//             size_t dashPos = line.find('-'); 
//             long long start = stoll(line.substr(0, dashPos)); 
//             long long end = stoll(line.substr(dashPos + 1));
            
//             for (long long i = start; i <= end; ++i) { 
//                 if (find(found.begin(), found.end(), i) == found.end()) { 
//                     found.push_back(i); freshCount++; 
//                 } 
//             } 
//         } 
//     } 
//     cout << "Total Fresh Items: " << freshCount << endl; 
//     return 0; 
// }