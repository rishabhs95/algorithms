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
	int test_cases, n1, n2;
	cin >> test_cases;
	while (test_cases--) {
		cin >> n1;
		int alt1[n1];
		for (int i = 0; i < n1; ++i) {
			cin >> alt1[i];
		}
		// sort(alt1, alt1+n1);
		cin >> n2;
		int alt2[n2];
		for (int i = 0; i < n2; ++i) {
			cin >> alt2[i];
		}
		// sort(alt2, alt2+n2);
		int diff = 1000000;
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < n2; ++j) {
				diff = min(diff, abs(alt1[i]-alt2[j]));
			}
		}
		cout << diff << endl;
	}
	return 0;
}