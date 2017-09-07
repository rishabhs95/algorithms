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
int A[15], dp[15];

void lis(int len) {
	int mx = 0;
	for (int i = 0; i < len; i++)
		dp[i] = 1;
	for (int i = 1; i < len; i++)
		for (int j = 0; j < i; j++)
			if (A[i] > A[j] && dp[i] < dp[j]+1)
				dp[i] = dp[j] + 1;
	for (int i = 0; i < len; i++)
		mx = max(mx, dp[i]);
	cout << mx << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	int len;
	cin >> len;
	for (int i = 0; i < len; i++)
		cin >> A[i];
	lis(len);
	return 0;
}