#include <iostream>

const long long int mod = 10000007;

using namespace std;

int power (long long int a, long long int b) {
	if (b == 0)
		return 1;
	long long res = power(a, b/2);
	res = (res*res)%mod;
	if (b%2 != 0)
		res = (res*a)%mod;
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	long long int n, k, res;
	while (cin >> n >> k && n!= 0 && k != 0) {
		res = ((power(n, n) + power(n, k))%mod + (2 * power(n-1, n-1) + 2 * power(n-1, k))%mod)%mod;
		cout << res << endl; 
	}
	return 0;
}