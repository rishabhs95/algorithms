#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases;
	double n, k, t, f;
	cin >> test_cases;
	while (test_cases--) {
		cin >> n >> k >> t >> f;
		double lambda = (f-n)/(k-1);
		cout << (int)(n + k*lambda) << endl;
	}
	return 0;
}