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
	bool flagged;
	int test_cases, n, x, res, count[2010];
	cin >> test_cases;
	while (test_cases--) {
		flagged = false;
		memset(count, 0, sizeof(count));
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			count[x+1000]++;
		}
		for (int i = 0; i < 2010; ++i) {
			if (count[i] > n/2) {
				flagged = true;
				res = i-1000;
			}
		}
		if (flagged)
			cout << "YES " << res << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}