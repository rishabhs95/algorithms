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
	int test_cases, num, sum, temp;
	cin >> test_cases;
	while (test_cases--) {
		cin >> num;
		sum = 0;
		for (int i=0; i<num; i++) {
			cin >> temp;
			sum += temp;
		}
		if (sum%num == 0)
			cout << num << endl;
		else cout << num-1 << endl;
	}
	return 0;
}