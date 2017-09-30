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

int calc_max_min_dist(int arr[], int n, int c) {
	/*  mid denotes the maximum possible distance between cows, such that   
	 	with that difference we can allocate c cows at given stall positions */
	int lo = 0, hi = (arr[n-1]-arr[0]+1), mid, ind, bins, ans;
	while (lo <= hi) {
		ind = 0;
		bins = 1;
		mid = (hi+lo)/2;
		for (int i = 1; i < n; i++) {
			if (arr[i]-arr[ind] >= mid) {
				ind = i;
				bins++;
			}
		}
		// if (arr[n-1]-arr[ind] > mid)
		// 	bins++;
		// cout << bins << " " << mid << " " << endl;
		if (bins >= c) {
			lo = mid+1;
			ans = mid;
		}
		else {
			hi = mid-1;
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_cases, num_stalls, num_cows;
	cin >> test_cases;
	while (test_cases--) {
		cin >> num_stalls >> num_cows;
		int pos[num_stalls];
		for (int i = 0; i < num_stalls; i++) {
			cin >> pos[i];
		}
		sort(pos, pos+num_stalls);
		cout << calc_max_min_dist(pos, num_stalls, num_cows) << endl;
	}
	return 0;
}