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
    int ans = 0;

    string word;
    while (input >> word) {
        char direction = word[0];
        int value = stoi(word.substr(1));

        if (direction == 'L') curr -= value;
        else if (direction == 'R') curr += value;

        curr = (curr % 100 + 100) % 100;
        if (curr == 0) ans++;
    }

    input.close();
    cout << ans << endl;
    return ans;
};