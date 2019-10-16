#include <iostream>
#include <map>
#include <vector>

using namespace std;

int ka, kb;
int expa[10], expb[10], expc[100];
double coefa[10], coefb[10], coefc[100];

map<int, int> expIndex;

int main () {
    cin >> ka;
    for (int i = 0; i < ka; i++) cin >> expa[i] >> coefa[i];
    cin >> kb;
    for (int i = 0; i < kb; i++) cin >> expb[i] >> coefb[i];

    int usedC = 0;
    for (int i = 0; i < ka; i++) {
        expIndex[expa[i]] = usedC;
        expc[usedC] = expa[i];
        coefc[usedC] = coefa[i];
        usedC++;
    }
    for (int j = 0; j < kb; j++) {
        if (expIndex.count(expb[j])) {
            coefc[expIndex[expb[j]]] += coefb[j];
        }
        else {
            expIndex[expb[j]] = usedC;
            expc[usedC] = expb[j];
            coefc[usedC] = coefb[j];
            usedC++;
        }
    }

    // 消除为 0 的项
    for (auto it = expIndex.begin(); it != expIndex.end(); it++)
        if (coefc[it->second] == 0) {
            usedC--;
            expIndex.erase(it);
        }
    cout << usedC;
    for (auto it = expIndex.rbegin(); it != expIndex.rend(); it++)
        printf(" %d %.1f", expc[it->second], coefc[it->second]);

    return 0;
}