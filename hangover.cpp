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
	double sum, res = 0.5, count = 2;
	while (cin >> sum && sum != 0) {
		if (sum < 0.5) {
			cout << "1 card(s)" << endl;
			continue;
		}
		while (sum-res > 1e-4) {
			count++;
			res += 1.0/count;
		}
		cout << count-1 << " card(s)" << endl;
	}
	return 0;
}