#include <iostream>
#include <vector>
#include <utility>
#include <queue>
 
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1e9;
vector <pii> ud[10000], d[10000];
int dist[10000] = {MAX};
 
void init(int n) {
	for (int i = 0; i < n; ++i) {
		ud[i].clear();
		d[i].clear();
		dist[i] = MAX;
	}
}
 
int djikstra(int src, int dest) {
	int x, wt;
	bool flag = false;
	pii curr;
	priority_queue <pii, vector<pii>, greater<pii> > q;
	q.push(make_pair(0, src));
	dist[src] = 0;
	while (!q.empty()) {
		curr = q.top();
		q.pop();
		x = curr.second;
		wt = curr.first;
		if (x == dest)
			break;
		for (int i = 0; i < ud[x].size(); i++) {
			if (dist[x] + ud[x][i].first < dist[ud[x][i].second]) {
				dist[ud[x][i].second] = dist[x] + ud[x][i].first;
				q.push(make_pair(ud[x][i].first, ud[x][i].second));
			}
		}
		if (!flag)
			for (int i = 0; i < d[x].size(); i++) {
				if (dist[x] + d[x][i].first < dist[d[x][i].second]) {
					dist[d[x][i].second] = dist[x] + d[x][i].first;
					q.push(make_pair(d[x][i].first, d[x][i].second));
					// flag = true;
				}
			}
	}
	if (dist[dest] == MAX)
		return -1;
	return dist[dest];
}
 
int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, n, m, k, s, t, a, b, wt;
	cin >> test_cases;
	while (test_cases--) {
		cin >> n >> m >> k >> s >> t;
		init(n);
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> wt;
			ud[a-1].push_back(make_pair(wt, b-1));
 
		}
		for (int i = 0; i < k; ++i) {
			cin >> a >> b >> wt;
			d[a-1].push_back(make_pair(wt, b-1));
			d[b-1].push_back(make_pair(wt, a-1));
		}
		cout << djikstra(s-1, t-1) << endl;
	}
	return 0;
}