#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases;
	cin >> test_cases;
	double n;
	while (test_cases--) {
		cin >> n;
		printf("%.8f\n", ((n-1)/n + 1/(n*(n+1))));
	}
	return 0;
}