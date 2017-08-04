#include <iostream>
#include <vector>

using namespace std;

bool flagged = false;
bool visited[10000];
int cnt;
vector <int> connected[10000];

void dfs(int src) {
	visited[src] = true;
	for (int i = 0; i < connected[src].size(); ++i)
		if (!visited[connected[src][i]]) {
			dfs(connected[src][i]);
			cnt++;
			cout << cnt << endl;
		}
}

int main() {
	freopen("input.txt", "r", stdin);
	int nodes, edges, a, b, max_cnt = 0;
	cin >> nodes;
	edges = nodes-1;
	for (int i = 0; i < nodes; ++i)
		visited[i] = false;
	while (edges--) {
		cin >> a >> b;
		connected[a-1].push_back(b-1);
		connected[b-1].push_back(a-1);
	}
	dfs(0);
	cout << cnt << endl;
	return 0;
}