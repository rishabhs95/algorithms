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

bool check (int i, int j, int n) {
	if (i > -1 && i < n && j > -1 && j < 3)
		return true;
	return false;	
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ctr = 0;
	int x[] = {1, 0, -1, -1};
	int y[] = {-1, -1, 0, -1};
	cin >> n;
	while(n > 0) {
		ctr++;
		int arr[n][3], dp[n][3];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> arr[i][j];
				dp[i][j] = 1e9;
			}
		}
		dp[0][1] = arr[0][1];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 4; k++) {
					if (check(i+y[k], j+x[k], n)) {
						dp[i][j] = min(dp[i][j], dp[i+y[k]][j+x[k]]+arr[i][j]);
					}
				}
			}
		}
		cout << ctr << ". " << dp[n-1][1] << endl;
		cin >> n;
	}
	return 0;
}