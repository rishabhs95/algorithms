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

long long int dp[10005][2], a[10005];

long long int calc(int len) {
	if (len < 1)
		return 0;
	dp[0][0] = 0;
	dp[0][1] = a[0];
	for (int i = 1; i < len; i++) {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = a[i]+dp[i-1][0];
	}
	return max(dp[len-1][0], dp[len-1][1]);
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, n;
	cin >> test_cases;
	for (int i = 0; i < test_cases; i++) {
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> a[j];
		cout << "Case " << i+1 << ": " << calc(n) << endl;
	}
	return 0;
}