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

map < pair<int, int>, int > pointSet;

void create_map() {
	for (int i = 0; i <= 20000; ++i) {
		int x = 2*(i/4);
		int y = 2*(i/4);
		if (i%4 == 1) {
			x += 1;
			y += 1;
		}
		if (i%4 == 2)
			x += 2;
		if (i%4 == 3) {
			x += 3;
			y += 1;
		}
		pointSet[make_pair(x, y)] = i;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, x, y;
	create_map();
	cin >> test_cases;
	while (test_cases--) {
		cin >> x >> y;
		if (pointSet[make_pair(x, y)] != 0 || (x == 0 && y == 0))
			cout << pointSet[make_pair(x, y)] << endl;
		else cout << "No Number" << endl;
	}
	return 0;
}