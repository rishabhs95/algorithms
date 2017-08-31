#include <iostream>
#include <cstring> //memset
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <unordered_map>

using namespace std;
typedef pair <int, int> pii;
vector < pii > V[10000];
int dist[10000];

void djikstra(int src, int sz, int dest) {
	for (int i = 0; i < sz; i++)
		dist[i] = 1e9;
	dist[src] = 0;
	priority_queue <pii, vector<pii>, greater<pii> > Q;
	Q.push(make_pair(0, src));
	while (!Q.empty()) {
		pii curr = Q.top();
		Q.pop();
		if (curr.second == dest) {
			printf("%d\n", dist[dest]);
			return;
		}
		for (int i = 0; i < V[curr.second].size(); i++) {
			pii temp = V[curr.second][i];
			if (dist[curr.second] + temp.first < dist[temp.second]) {
				dist[temp.second] = dist[curr.second] + temp.first;
				Q.push(make_pair(dist[temp.second], temp.second));
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	char name[20], src[20], dest[20];
	unordered_map <string, int> M;
	int test_cases, nodes, neighbours, queries, dst, wt;
	scanf("%d", &test_cases);
	while (test_cases--) {
		scanf("%d", &nodes);
		for (int i = 0; i < nodes; i++)
			V[i].clear();
		for (int i = 0; i < nodes; i++) {
			scanf("%s", name);
			M[name] = i;
			scanf("%d", &neighbours);
			for (int j = 0; j < neighbours; j++) {
				scanf("%d %d", &dst, &wt);
				V[i].push_back(make_pair(wt, dst-1));
			}
		}
		cin >> queries;
		while (queries--) {
			scanf("%s %s", src, dest);
			djikstra(M[src], nodes, M[dest]);
		}
	}
	return 0;
}