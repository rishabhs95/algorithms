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
typedef long long int ll;

ll f[100];

ll fact(ll n) {
	if (n <= 1) {
		f[n] = 1;
		return 1;
	}
	if (f[n] != 0)
		return f[n];
	f[n] = n * fact(n-1);
	return f[n];
}

void rank_perm(int arr[], int n) {
	ll rank = 1;
	int lesser_count[n];
	for (int i = 0; i < n; i++)
		lesser_count[i] = i;
	for (int i = 0; i < n; i++) {
		rank += lesser_count[i] * fact(n-i-1);
		
	}
	cout << rank << endl;
}

int main() {
	memset(f, 0, sizeof(f));
	freopen("input.txt", "r", stdin);
	int test_cases, len;
	cin >> test_cases;
	while (test_cases--) {
		cin >> len;
		int perm[len];
		for (int i = 0; i < len; i++)
			cin >> perm[i];
		rank_perm(perm, len);
	}
	return 0;
}