#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, a, b, c, hcf, i;
	cin >> test_cases;
	for (i=1; i<=test_cases; i++) {
		cin >> a >> b >> c;
		hcf = gcd(max(a, b), min(a, b));
		cout << "Case " << i << ": ";
		if (c%hcf ==0)
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}