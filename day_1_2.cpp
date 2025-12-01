#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ifstream input("D:\\Downloads\\advent_of_code_2025\\day_1.txt");

    if (!input.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    int curr = 50;
    long long ans = 0;

    string word;
    while (input >> word) {
        char direction = word[0];
        int value = stoi(word.substr(1));

        int step = (direction == 'R') ? 1 : -1;

        for (int i = 0; i < value; i++) {
            curr += step;

            if (curr < 0) curr = 99;
            else if (curr > 99) curr = 0;

            if (curr == 0)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
