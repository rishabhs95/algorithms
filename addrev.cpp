#include <iostream>
#include <string>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		string a, b, res = "";
		cin >> a >> b;
		int carry = 0;
		bool non_zero = false;
		int mx = max(a.length(), b.length());
		for (int i = 0; i < mx; i++) {
			int sum = carry;
			if (i < a.length()) sum += a[i]-'0';
			if (i < b.length()) sum += b[i]-'0';
			// cout << "*" << sum << "*" << endl;
			char digit = '0'+ sum%10;
			carry = sum/10;
			res.push_back(digit);
		}
		if (carry != 0) res.push_back('0'+carry);
		for (int i = 0; i < res.length(); i++) {
			if (res[i] == '0' && !non_zero)
				continue;
			non_zero = true;
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}