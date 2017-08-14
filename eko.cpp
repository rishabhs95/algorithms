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

vector <int> v;

int sum (int ele) {
	int res = 0;
	for (int i = 0; i < v.size(); ++i)
		if (v[i] > ele)
			res += v[i]-ele;
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	int len, sum, x, low, high;
	cin >> len;
	while (len--) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	low = v[0];
	high = v[v.size()-1];
	while (low <= high) {
		mid = low + (high-low)/2;
		if ()
	}
	return 0;
}