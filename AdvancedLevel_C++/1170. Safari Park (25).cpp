#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
using namespace std;

size_t N;   // The number of regions.
size_t R;   // The number of neighboring relations.
size_t K;   // The number of species of animals.
size_t M;   // The number of distribution plans.
vector<pair<size_t, size_t>> relations;
vector<vector<size_t>> plans;

int main() {
    cin >> N >> R >> K;
    size_t r1, r2;
    for (size_t i = 0; i < R; ++i) {
        cin >> r1 >> r2;
        relations.emplace_back(--r1, --r2);
    }
    cin >> M;
    plans.resize(M);
    for (size_t i = 0; i < M; ++i) {
        plans[i].resize(N);
        for (size_t j = 0; j < N; ++j) cin >> plans[i][j];
    }
    
    for (vector<size_t>& plan : plans) {
        unordered_set<size_t> species;
        for (size_t s : plan) species.insert(s);
        if (species.size() < K)
            cout << "Error: Too few species." << endl;
        else if (species.size() > K)
            cout << "Error: Too many species." << endl;
        else {
            bool is_ok = true;
            for (pair<size_t, size_t> relation: relations) {
                size_t r1 = relation.first;
                size_t r2 = relation.second;
                if (plan[r1] == plan[r2]) {
                    is_ok = false;
                    break;
                }
            }
            cout << (is_ok ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
