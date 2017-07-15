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

int gcd (int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, a, b, hcf;
	cin >> test_cases;
	while (test_cases--) {
		cin >> a >> b;
		hcf = gcd(max(a, b), min(a, b));
		cout << b/hcf << " " << a/hcf << endl;
	}
	return 0;
}