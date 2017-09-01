#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool visited[10000];
int in_degree[10000];
vector <int> V[10000];

void dfs(int src) {
	visited[src] = true;
	for (int i = 0; i < V[src].size(); i++)
		if (!visited[V[src][i]])
			dfs(V[src][i]);
}

void fastscan(int &x) {
	bool neg = false;
	register int c;
	x = 0;
	c = getchar();
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
}

void topological_sorting(int n) {
	vector <int> topo_order;
	int curr;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < V[i].size(); j++)
			in_degree[V[i][j]]++;
	priority_queue <int, vector<int>, greater<int> > Q;
	for (int i = 0; i < n; i++)
		if (in_degree[i] == 0)
			Q.push(i);
	while (!Q.empty()) {
		curr = Q.top();
		Q.pop();
		topo_order.push_back(curr);
		for (int i = 0; i < V[curr].size(); i++)
			if (--in_degree[V[curr][i]] == 0)
				Q.push(V[curr][i]);
	}
	if (topo_order.size() != n)
		printf("Sandro fails.");
	else
		for (int i = 0; i < topo_order.size(); i++)
	        printf("%d ", topo_order[i]+1);
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, m, before, after;
	fastscan(n);
	fastscan(m);
	for (int i = 0; i < m; i++) {
		fastscan(before); 
		fastscan(after);
		V[before-1].push_back(after-1);
	}
	topological_sorting(n);
	return 0;
}