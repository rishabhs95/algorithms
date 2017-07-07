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
	int test_cases, x, y, z;
	cin >> test_cases;
	while (test_cases--) {
		cin >> x >> y >> z;
		if (z == 0)
			cout << "YES" << endl; 
		else {
			if (z > max(x, y)) {
				if (z % (x+y) == 0)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
			else {
				if ((max(x, y) + z) % min(x, y) == 0)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
	}
	return 0;
}