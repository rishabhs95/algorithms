#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int bin_rev(int num) {
	int res = 0;
	while (num > 0) {
		res = res*2 + num%2;
		num /= 2;
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		int num;
		cin >> num;
		if (num % 2 == 0) 
			cout << bin_rev(num) << endl;
		else
			cout << num << endl;
	}
	return 0;
}