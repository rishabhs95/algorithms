#include <iostream>
#include <vector>

using namespace std;

bool flagged = false;
bool visited[10000];
vector <int> connected[10000];

void dfs(int src) {
	visited[src] = true;
	for (int i = 0; i < connected[src].size(); ++i)
		if (!visited[connected[src][i]])
			dfs(connected[src][i]);
}

int main() {
	freopen("input.txt", "r", stdin);
	int nodes, edges, a, b;
	cin >> nodes >> edges;
	for (int i = 0; i < nodes; ++i)
		visited[i] = false;
	if (edges != nodes-1)
		flagged = true;
	while (edges--) {
		cin >> a >> b;
		connected[a-1].push_back(b-1);
		connected[b-1].push_back(a-1);
	}
	dfs(0);
	for (int i = 0; i < nodes; ++i)
		if (!visited[i])
			flagged = true;
	if (flagged)
		cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}