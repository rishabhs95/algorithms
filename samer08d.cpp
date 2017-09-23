// Created by rishabhstr ツ
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
const int MX = 1e3;
string a, b;

int lcs[MX][MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k, len_a, len_b;
	cin >> k;
	while (k != 0) {
		memset(lcs, 0, sizeof(lcs));
		cin >> a >> b;
		len_a = a.length();
		len_b = b.length();
		for (int i = 0; i <= len_a; ++i) {
			for (int j = 0; j <= len_b; ++j) {
				if (i == 0 or j == 0)
					lcs[i][j] = 0;
				else {
					if (a[i-1] == b[j-1]) {
						lcs[i][j] = lcs[i-1][j-1]+1;
					}
					else {
						if (lcs[i-1][j] >= k) {
							lcs[i][j] = lcs[i-1][j];
						}
						if (lcs[i][j-1] >= k) {
							lcs[i][j] = max(lcs[i][j], lcs[i][j-1]);
						}
					}
				}

			}
		} 
		cout << lcs[len_a][len_b] << endl;
		cin >> k;
	}
	return 0;
}