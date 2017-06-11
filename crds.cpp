#include <iostream>

using namespace std;

const int mod = 1000007;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		long long int level;
		cin >> level;
		long long int quad = (3*level*level + level)/2;
		cout << quad%mod << endl;
	}
	return 0;
}