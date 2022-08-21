#include <iostream>
#include <vector>
using namespace std;
int V, E, K, Start, End, a, b, d;
int Edge[1002][1002], Distance[1002], flag, book[1002];
void deal(int x, int index, vector<int> Path) {
    for(int k = 1; k <= V; k++) {
        int Min = 9999999, now = Path[index];
        for(int i = 1; i <= V; i++) {
            if(Distance[i] != 9999999 && !book[i] && Distance[i] <= Min) {
                if(Distance[i] < Min) {
                    if(i == now) flag = 1;
                    else flag = 0;
                } else if(Distance[i] == Min) {
                    if(i == now) flag = 1;
                }
                Min = Distance[i];
            }
        }
        if(!flag) return;
        ++index;
        if(index > V) return;
        book[now] = 1;
        for(int i = 1; i <= V; i++) 
            if(!book[i] && Distance[i] > Distance[now] + Edge[now][i] && Edge[now][i] != 0) 
                Distance[i] = Distance[now] + Edge[now][i];
    }
}
int main() {
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        cin >> a >> b >> d;
        Edge[a][b] = Edge[b][a] = d;
    }
    cin >> K;
    for(int i = 0; i < K; i++) {
        vector<int> Path(V);
        flag = 1;
        fill(book, book + 1002, 0);
        fill(Distance, Distance + 1002, 9999999);
        for(int j = 0; j < V; j++) cin >> Path[j];
        Start = Path[0], End = Path[V - 1];
        Distance[Start] = 0;
        deal(Start, 0, Path);
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}