#include <iostream>

// inverse modulo
using namespace std;
typedef long long int ll;

const int mod = 1e9+7;
const int sz = 2*1e6+10;
ll fact[sz];

int xGCD(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int x1, y1, gcd = xGCD(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}

ll mod_inv(int a) {
	int x, y;
    int g = xGCD(a, mod, x, y);
    return (x%mod + mod) % mod;
}

void fib() {
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i < sz; ++i)
		fact[i] = (fact[i-1] * (i))%mod;
}

int main() {
	freopen("input.txt", "r", stdin);
	fib();
	int test_cases, x, y;
	cin >> test_cases;
	while (test_cases--) {
		cin >> x >> y;
		cout << (fact[x+y] * (mod_inv(fact[x]) * mod_inv(fact[y])%mod)) % mod  << endl;
	}
	return 0;
}