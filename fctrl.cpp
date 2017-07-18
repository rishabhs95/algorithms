#include <iostream>

using namespace std;

int z(int n) {
	int res = 0;
	while (n > 0) {
		n /= 5;
		res += n;
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
	int test_cases, num;
	cin >> test_cases;
	while (test_cases--) {
		cin >> num;
		cout << z(num) << endl;
	}
	return 0;
}