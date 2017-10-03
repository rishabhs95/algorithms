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

typedef long long ll;

ll dp[5010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int temp;
	string x;
	cin >> x;
	while (x[0] != '0') {
		dp[0] = 1ll;
		dp[1] = 1ll;
		for (int i = 2; i <= x.length(); ++i) {
			dp[i] = dp[i-1];
			temp = 0;
			temp = (x[i-2]-'0')*10+(x[i-1]-'0');
			if (temp > 0 && temp < 27)
				dp[i] += dp[i-2];
		}
		cout << dp[x.length()] << endl;
		cin >> x;
	}
	return 0;
}