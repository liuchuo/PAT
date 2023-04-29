#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
char input[10];
bool is_prime(int n) {
    if (n <= 1) return false;
    else if (n == 2) return true;
    int max_factor = sqrt(n) + 1;
    for (int factor = 2; factor <= max_factor; ++factor)
        if (n % factor == 0) return false;
    return true;
}

int main() {
    cin.getline(input, 10);
    bool all_prime = true;
    const char* cur_str = input;
    while (*cur_str) {
        cout << cur_str << " ";
        if (is_prime(atoi(cur_str)))
            cout << "Yes" << endl;
        else {
            cout << "No" << endl; 
            all_prime = false;
        }
        ++cur_str;
    }
    if (all_prime)
        cout << "All Prime!" << endl;
    return 0;
}
