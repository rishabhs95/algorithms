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
	int test_cases, activities, start_time, end_time;
	cin >> test_cases;
	while (test_cases--) {
		cin >> activities;
		for (int i = 0; i < activities; ++i) {
			cin >> start_time >> end_time;
		}
	}
	return 0;
}