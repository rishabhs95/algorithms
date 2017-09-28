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

int mat[105][105];

int bfs(int x, int y) {
	int res = 0;
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			cin >> mat[i][j];
		}
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h;
	cin >> w >> h;
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			cin >> mat[i][j];
		}
	}
	cout << bfs(w, h);
	return 0;
}