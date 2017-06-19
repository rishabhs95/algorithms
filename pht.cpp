#include <iostream>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases;
	long long int num;
	cin >> test_cases;
	for (int i=0; i<test_cases; i++) {
		cin >> num;
		cout << "Case " << i+1 << ": " << (int)sqrt(1LL+num)-1 << endl;
	}
	return 0;
}