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

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else return gcd(b, a%b);
}

int main() {
	freopen("input.txt", "r", stdin);
	int len, prev = 0, curr, i, hcf, res = 0, add;
	cin >> len;
	int diff[len];
	for (i = 0; i < len; i++) {
		cin >> curr;
		if (i>0)
			diff[i-1] = curr-prev;
		prev = curr;
	}
	hcf = gcd(max(diff[0], diff[1]), min(diff[0], diff[1]));
	for (i=2; i<len-1; i++) {
		hcf = gcd(max(hcf, diff[i]), min(hcf, diff[i]));
	}
	for (i=0; i<len-1; i++) {
		add = diff[i]/hcf - 1;
		if (add < 0)
			add = 0;
		res += add;
	}
	cout << res << endl;
	return 0;
}