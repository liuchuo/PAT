#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Player{
	int weight, rank;
};

int main() {
#if ONLINE_JUDGE
#else
	freopen("input.txt", "r", stdin);
#endif
	int Np, Ng;
	scanf("%d %d", &Np, &Ng);
	vector<Player> players(Np);
	for(int i = 0; i < Np; i++) {
		scanf("%d", &players[i].weight);
	}
	queue<int> q;
	for(int i = 0; i < Np; i++) {
		int index;
		scanf("%d", &index);
		q.push(index);
	}
	while(q.size() > 1) { 
		int group, len = q.size();
		if(len % Ng > 0) {
			group = len / Ng + 1;
		} else {
			group = len / Ng;
		}
		int i = 0;
		for(int g = 0; g < group; g++) {
			int cnt = 0, max_index = q.front();
			while(cnt < Ng && i < len) {
				int index = q.front();
				players[index].rank = group + 1;
				if(players[index].weight > players[max_index].weight) {
					max_index = index;
				}
				q.pop();
				cnt++;
				i++;
			}
			q.push(max_index);
		}
	}
	players[q.front()].rank = 1;
	printf("%d", players[0].rank);
	for(int i = 1; i < Np; i++) {
		printf(" %d", players[i].rank);
	}
	return 0;
}
