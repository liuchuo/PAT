#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

unsigned int num1, num2;            // The beginning numbers.
size_t N, M;                        // N players and M rounds.
unordered_set<unsigned int> nums;   // The numbers that have shown up.
unsigned int plays[10][1000];       // plays[i][j] implies the i-th player's
                                    // play in the j-th round.
int main() {
    cin >> num1 >> num2;
    nums.insert(num1); nums.insert(num2);
    cin >> N >> M;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < M; ++j)
            cin >> plays[i][j];
    
    vector<bool> is_out(N, false);
    for (size_t j = 0; j < M; ++j) {
        for (size_t i = 0; i < N; ++i) {
            if (is_out[i]) continue;
            unsigned int cur_play = plays[i][j];
            bool is_ok = false;
            if (nums.find(cur_play) == nums.end()) {
                for (unsigned int num : nums) {
                    if (nums.find(num + cur_play) != nums.end()) {
                        nums.insert(cur_play);
                        is_ok = true;
                        break;
                    }
                }
            }
            if (!is_ok) {
                is_out[i] = true;
                printf("Round #%u: %u is out.\n", j + 1, i + 1);
            }
        }
    }
    
    vector<size_t> winners;
    for (size_t i = 0; i < N; ++i)
        if (!is_out[i]) winners.push_back(i);
    
    if (winners.empty())
        cout << "No winner." << endl;
    else {
        cout << "Winner(s):";
        for (size_t winner : winners)
            cout << " " << winner + 1;
        cout << endl;
    }
    return 0;
}

