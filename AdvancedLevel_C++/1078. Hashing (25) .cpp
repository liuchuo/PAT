#include <iostream>
using namespace std;
int size, n, hashTable[10100];
bool isprime(int num) {
    if(num == 1) return false;
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0) return false;
    return true;
}
void insert(int key) {
    for(int step = 0; step < size; step++) {
        int index = (key + step * step) % size;
        if(hashTable[index] == 0) {
            hashTable[index] = 1;
            cout << index % size;
            return ;
        }
    }
    cout << '-';
}
int main() {
    cin >> size >> n;
    while(!isprime(size)) size++;
    for(int i = 0; i < n; i++) {
        int key;
        cin >> key;
        if(i != 0) cout << ' ';
        insert(key);
    }
    return 0;
}