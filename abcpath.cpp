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
typedef pair < pair <int, int>, int > ppi;

bool vis[100][100];
char grid[100][100];

int mx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int my[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool isValid(int i, int j, int h, int w) {
	if (i < 0 || j < 0 || i >= h || j >= w)
		return false;
	return true;
}

int bfs(int i, int j, int h, int w) {
	queue <ppi> q;
	ppi curr;
	int c, d, m, n, st, res = 0;
	q.push(make_pair(make_pair(i, j), 1));
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		c = curr.first.first;
		d = curr.first.second;
		st = curr.second;
		res = max(res, st);
		vis[c][d] = true;
		for (i = 0; i < 8; i++) {
			m = c + mx[i];
			n = d + my[i];
			if (isValid(m, n, h, w) && !vis[m][n] && grid[m][n] - grid[c][d] == 1)
				q.push(make_pair(make_pair(m, n), st+1));
		}
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	char c;
	int h, w, i, j, cs = 1, res = 0;
	while (true) {
		cin >> h >> w;
		if (h == 0 && w == 0)
			break;
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				cin >> grid[i][j];
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (grid[i][j] == 'A') {
					memset(vis, false, sizeof(vis));
					res = max(res, bfs(i, j, h, w));
				}
			}
		}
		cout << "Case " << cs++ << ": " <<  res << endl;
	}
	return 0;
}