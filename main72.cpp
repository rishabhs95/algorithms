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
int A[110], len;
bool dp[1010][110];

bool sub (int sum) {
	for (int i = 0; i <= len; i++)
			dp[0][i] = true;
	for (int i = 1; i <= sum; i++)
			dp[i][0] = false;
	for (int i = 0; i <= sum; i++) {
		for (int j = 0; j <= len; j++) {
			dp[i][j] = dp[i][j-1];
			if (A[j-1] <= i)
				dp[i][j] = dp[i][j] | dp[i-A[j-1]][j-1];
		}
	}
	for (int i = 0; i <= sum; i++) {
		for (int j = 0; j <= len; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return dp[sum][len];
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, sum;
	cin >> test_cases;
	while (test_cases--) {
		sum = 0;
		cin >> len;
		for (int i = 0; i < len; i++)
			cin >> A[i];
		for (int i = 0; i < len; i++)
			if (sub(A[i]))
				sum += A[i];
		cout << sum << endl;
	}
	return 0;
}