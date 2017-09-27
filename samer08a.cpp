// Created by rishabhstr ツ
#include <iostream>
#include <cstring> //memset
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
#include <map>

using namespace std;

const int MAX = 1e5;

void djikstra(vector<pair<int,int>> v[], int n, int src, int dest) {
	int dist[MAX];
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
	q.push(make_pair(0,src));
	dist[src] = 0;
	while (!q.empty()) {
		pair<int, int> curr = q.top();
		q.pop();
		for (int i = 0; i < v[curr.second].size(); i++) {
			if (dist[curr.second]+v[curr.second][i].first < dist[i]) {
				dist[i] = dist[curr.second]+v[curr.second][i].first;
				q.push(make_pair(curr.first, v[curr.second][i].second));
			}
		}
	}
	cout << dist[dest] << endl;
}

// int calculate(vector<int> v[], int n, int src, int dest) {

// }

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, src, dest, a, b, wt;
	while (true) {
		cin >> n >> m;
		vector<pair<int,int>> v[n];
		cin >> src >> dest;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> wt;
			v[a].push_back(make_pair(b,wt));
		}
		djikstra(v, n, src, dest);
		if (n == 0 && m == 0) {
			break;
		}
	}	
	return 0;
}