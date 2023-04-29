#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
#include <vector>
#include <unordered_map>
using namespace std;

size_t N;       // The number of dates.
unordered_map<string, string> ump = {
    {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},
    {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
    {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},
    {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
};

int main() {
    cin >> N; cin.get(); // Absorb the Enter('\n').
    for (size_t i = 0; i < N; ++i) {
        string inp;
        getline(cin, inp);
        vector<string> v; // Split the input to 3 strings.
        string::iterator p = inp.begin(), q = p;
        while (true) {
            if (q == inp.end() || !isalnum(*q)) {
                // *q is neither a digit nor a letter.
                if (p < q) v.emplace_back(p, q);
                if (q == inp.end()) break;
                else p = q + 1;
            }
            ++q;
        }
        assert(v.size() == 3); // month, day, year.

        while (v[1].size() < 2) v[1] = "0" + v[1]; // dd
        while (v[2].size() < 4) v[2] = "0" + v[2]; // yyyy
        string fmt = v[2] + ump[v[0]] + v[1]; // yyyymmdd format
        string rev(fmt.rbegin(), fmt.rend()); // fmt reversed

        if (fmt == rev) cout << "Y ";
        else cout << "N ";
        cout << fmt << endl;
    }
    return 0;
}