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

typedef long long int ll;
typedef pair<int, int> pii;

int dp[1000][25][85], co[1000], cn[1000], cw[1000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_cases, t, a, c;
	cin >> test_cases;
	while (test_cases--) {
		cin >> t >> a;
		cin >> c;
		for (int i = 0; i < c; ++i) {
			cin >> co[i] >> cn[i] >> cw[i];
		}
		for (int i = 0; i <= c; i++) {
			for (int j = 0; j <= t; j++) {
				for (int k = 0; k <= a; k++) {
					if (i == 0 || j == 0 || k == 0) {
						dp[i][j][k] = 0;
					}
					else {
						dp[i][j][k] = dp[i-1][j][k];
						if (j >= co[i-1] && k >= cn[i-1]) {
							dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-co[i-1]][k-cn[i-1]]+cw[i-1]);
						}
					}
				}
			}
		}
		cout << dp[c][t][a] << endl;
	}
	return 0;
}