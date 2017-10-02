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

int cost[1010], profit[1010], dp[1010][60];

void disp(int num, int lim) {
	for (int i = 0; i <= num; ++i) {
		for (int j = 0; j <= lim; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << "#" << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_cases, res, lim, num;
	cin >> test_cases;
	while (test_cases--) {
		cin >> lim >> num;
		for (int i = 0; i < num; ++i) {
			cin >> cost[i] >> profit[i];
		}
		for (int i = 0; i <= num; i++) {
			for (int j = 0; j <= lim; j++) {
				if (i == 0 || j == 0)
					dp[i][j] = 0;
				else {
					dp[i][j] = max(dp[i][j], dp[i-1][j]);
					if (j-cost[i-1] >= 0)
						dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i-1]]+profit[i-1]);
				}
			}
		}
		res = dp[num][lim];
		//disp(num, lim);
		cout << "Hey stupid robber, you can get " << res << "." << endl;
	}
	return 0;
}