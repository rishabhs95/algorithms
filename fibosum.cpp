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

int arr[2][2] = {1, 0, 0, 1};

int[2][2] mult(int a[2][2], int b[2][2]) {
	int c[2][2] = {0};
	for (int i = 0; i < 2; i ++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	return c;
}

int[2][2] pow(int a[2][2], int b) {
	int res[2][2];
	res = pow(res, b/2);
	res = mult(res, res);
	if (b%2 != 0)
		res = mult(res, arr);
	return res;
}

int fibo(int n) {
	return pow(arr, n)[0];
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, m, n;
	cin >> test_cases;
	while (test_cases--) {
		cin >> m >> n;
		cout << fibo(m) << " " << fibo(n) << endl;
	}
	return 0;
}