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

int parent[1000000];
int wt[1000000];

void initialise (int sz) {
	for (int i = 0; i < sz; ++i) {
		parent[i] = i;
		wt[i] = 1;
	}
}

int root(int a) {
	while (parent[a] != a) {
		parent[a] = parent[parent[a]];
		a = parent[a];
	}
	return a;
}

void union_(int a, int b) {
	if (wt[a] <= wt[b]) {
		parent[root(a)] = parent[root(b)];
		wt[b] += wt[a];
	}
	else {
		parent[root(b)] = parent[root(a)];
		wt[a] += wt[b];
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, nodes, edges, a, b, res;
	cin >> test_cases;
	while (test_cases--) {
		res = 0;
		cin >> nodes >> edges;
		initialise(nodes);
		while (edges--) {
			cin >> a >> b;
			union_(a, b);
		}
		// for (int i = 0; i < nodes; ++i)
		// 	cout << parent[i] << " ";
		for (int i = 0; i < nodes; ++i)
			if (i == root(i))
				res++;
		cout  << res << endl;
	}
	return 0;
}