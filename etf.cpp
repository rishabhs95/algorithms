#include <iostream>

using namespace std;

int etf (int n) {
	int res = n;
	long long int i;
	for (i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			res -= res/i;
			while (n%i == 0)
				n /= i;
		}
	}
	if (n > 1)
        res -= res/n;
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, n;
	cin >> test_cases;
	while (test_cases--) {
		cin >> n;
		cout << etf(n) << endl;
	}
	return 0;
}