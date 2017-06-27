#include <iostream>
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
	int test_cases, n, x, avg;
	cin >> test_cases;
	while (test_cases--) {
		cin >> x >> avg;
		n = avg - x + 1;
		cout << avg*n - x - ((n-1)*(n-2))/2 << endl;
	}
	return 0;
}