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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_cases, len;
	cin >> test_cases;
	while (test_cases--) {
		cin >> len;
		int arr[len], dp[len];
		for (int i = 0; i < len; ++i)
			cin >> arr[i];
		dp[0] = arr[0];
		dp[1] = dp[0]+arr[1];
		dp[2] = dp[1]+arr[2];
		for (int i = 3; i < len; ++i) {
			dp[i] = max(dp[i-3]+arr[i-2]+arr[i-1]+arr[i], max(dp[i-2]+arr[i-1]+arr[i], dp[i-1]+arr[i]));
		}
		cout << dp[len-1] << endl;
	}
	return 0;
}