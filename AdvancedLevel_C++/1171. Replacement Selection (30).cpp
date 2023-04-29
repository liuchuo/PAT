#include <iostream>
#include <vector>
#include <queue>
using namespace std;

size_t N;       // The total number of records.
size_t M;       // The capacity of the internal memory.
vector<int> tape;           // tape[i] indicates the i-th record.
vector<vector<int>> runs;   // runs[i] indicates the i-th run.

int main() {
    cin >> N >> M;
    tape.resize(N);
    for (size_t i = 0; i < N; ++i) cin >> tape[i];
    
    while (!tape.empty()) {
        vector<int> run;
        vector<int> left;
        priority_queue<int, vector<int>, greater<int>> qu;

        // The number of records that stay till the next run.
        size_t stay = 0;
        
        size_t i = 0;
        for (; i < tape.size() && i < M; ++i)
            qu.push(tape[i]);
        for (; i < tape.size(); ++i) {
            if (stay == M) {
                // Memory is full of staying records left to the next run.
                left.push_back(tape[i]);
                continue;
            }
            else if (qu.size() + stay == M) {
                // Pop the top to spare a memory unit for tape[i].
                int t = qu.top();
                run.push_back(t);
                qu.pop();
            }
            
            if (!run.empty() && tape[i] < run.back()) {
                // tape[i] needs to stay till the next run.
                left.push_back(tape[i]);
                ++stay;
            }
            else {
                // tape[i] belongs to the current run.
                qu.push(tape[i]);
            }
        }
        
        while (!qu.empty()) {
            int t = qu.top();
            qu.pop();
            run.push_back(t);
        }
        
        tape = left;
        runs.emplace_back(run);
    }
    
    // Print runs.
    for (vector<int>& run : runs) {
        for (auto ri = run.cbegin(); ri != run.cend(); ++ri) {
            cout << *ri;
            if (ri + 1 == run.cend()) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}
