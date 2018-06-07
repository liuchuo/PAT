1122. Hamiltonian Cycle (25)
The “Hamilton cycle problem” is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a “Hamiltonian cycle”.
In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2< N <= 200), the number of vertices, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format “Vertex1 Vertex2”, where the vertices are numbered from 1 to N. The next line gives a positive integer K which is the number of queries, followed by K lines of queries, each in the format:
n V1 V2 … Vn
where n is the number of vertices in the list, and Vi‘s are the vertices on a path.
Output Specification:
For each query, print in a line “YES” if the path does form a Hamiltonian cycle, or “NO” if not.
Sample Input:
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
Sample Output:
YES
NO
NO
NO
YES
NO

#include <iostream>
int **graph;
int isConnected(int *v, int n) {
    int pre = v[0];
    for (int i = 1; i < n; i++) {
        if (graph[pre][v[i]] != 1) {
            return 0;
        }
        pre = v[i];
    }
    return 1;
}

int isHamilt(int *v, int n) {
    if (v[0] != v[n - 1]) return 0;
    int *times = new int[n];
    for (int i = 0; i < n; i++) {
        times[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        times[v[i]]++;
    }

    for (int i = 1; i < n; i++) {
        if (i == v[0]) {
            if (times[i] != 2) {
                return 0;
            }
        } else {
            if (times[i] != 1) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    graph = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        graph[i] = new int[n+1];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }
    int k = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int kn = 0;
        scanf("%d", &kn);
        int *v = new int[kn];
        for (int j = 0; j < kn; j++) {
            scanf("%d", &v[j]);
        }
        if (kn == n + 1 && isConnected(v, kn) && isHamilt(v, kn)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}