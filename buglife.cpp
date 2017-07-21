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
	int test_cases, bugs, interactions, bug1, bug2;
	cin >> test_cases;
	for (int i=1; i<= test_cases; i++) {
		flagged = false;
		cin >> bugs >> interactions;
		int gender[bugs];
		for (int i = 0; i < bugs; ++i) {
			gender[i] = 0;
		}
		while (interactions--) {
			cin >> bug1 >> bug2;
			if (gender[bug1] != 0) {
				if (gender[bug2] != 0) {
					if ((gender[bug1] == 1 && gender[bug2] == 2) || (gender[bug2] == 1 && gender[bug1] == 2))
						continue;
					else
						flagged = true;
				}
				else {
					if (gender[bug1] == 1)
						gender[bug2] = 2;
					else gender[bug2] = 1;
				}
			}
			else {
				if (gender[bug2] == 0) {
					gender[bug1] = 1;
					gender[bug2] = 2;
				}
				else {
					if (gender[bug2] == 1)
						gender[bug1] = 2;
					else gender[bug1] = 1;
				}
			}
		}
		cout << "Scenario #" << i << ":" << endl;
		if (flagged) cout << "Suspicious bugs found!" << endl;
		else cout << "No suspicious bugs found!" << endl;
	}
	return 0;
}