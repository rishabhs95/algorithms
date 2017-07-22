#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases;
	long long int num, two = 2;
	cin >> test_cases;
	for (int i=1; i<=test_cases; i++) {
		cin >> num;
		while (num%two == 0)
			num /= two;
		cout << "Case " << i << ": " << num << endl;
	}
	return 0;
}