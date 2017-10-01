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
	freopen("input.txt", "r", stdin);
	int stations, people;
	cin >> stations >> people;
	int a[stations], b[stations];
	for (int i = 0; i < stations; ++i)
		cin >> a[i];
	for (int i = 0; i < stations; ++i)
		cin >> b[i];
	int dp[stations][2], curr, i;
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	for (i = 1; i < stations; ++i) {
		dp[i][0] = min(min(dp[i-1][0]+a[i], dp[i-1][1]+a[i]+b[i]), dp[i-1][1]+a[i-1]+a[i]);
		dp[i][1] = min(min(dp[i-1][0]+a[i]+b[i], dp[i-1][1]+b[i]), dp[i-1][0]+b[i-1]+b[i]);
		curr = min(dp[i][0], dp[i][1]);
		if (curr >= people) {
			curr = min(dp[i-1][0], dp[i-1][1]);
			break;
		}
	}
	cout << i << " " << curr;
	return 0;
}