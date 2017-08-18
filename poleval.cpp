#include <iostream>

using namespace std;
typedef long long int ll;

ll horner (ll c[], int n, ll x) {
	ll res = 0;
	for (int i = 0; i <= n; i++)
		res = (res*x) + c[i];
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	int C = 0, n, k;
	while (cin >> n && n != -1) {
		cout << "Case " << ++C << ":" << endl;
		ll c[n+1], x;
		for (int i = 0; i<=n; i++)
			cin >> c[i];
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> x;
			cout << horner(c, n, x) << endl;
		}
	}
	return 0;
}