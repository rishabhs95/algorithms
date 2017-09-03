#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string src, dest;

int edist(int m, int n) {
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (src[i-1] == dest[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(min(dp[i][j-1],
                                   dp[i-1][j]),
                                   dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		cin >> src >> dest;
		cout << edist(src.length(), dest.length()) << endl;
	}
	return 0;
}