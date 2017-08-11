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

long long int recaman[500010];
set <long long int> reserve;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int K;
	recaman[0] = 0;
	for (int i = 1; i <= 500000; ++i) {
		recaman[i] = recaman[i-1]-i;
		if (recaman[i] <= 0 || reserve.find(recaman[i]) != reserve.end())
			recaman[i] += 2*i;
		reserve.insert(recaman[i]);
	}
	while (cin >> K && K != -1) {
		cout <<  recaman[K] << endl;
	}
	return 0;
}