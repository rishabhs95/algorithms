#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <utility>
#include <list>
#include <set>
#include <map>

using namespace std;

string add(string a, string b) {
	string res;
	int sum = 0, carry = 0;
	int len = max(a.length(), b.length());
	for (int i=len-1; i>-1; i--) {
		res.push_back();
	}
}

string multiply(string a, string b) {
	string res;

}

string factorial(string n) {
	if (n == "1")
		return res;
	string res;
	res = multiply(n, factorial(n-1));
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
	int test_cases;
	cin >> test_cases;
	string n;
	while (test_cases--) {
		cin >> n;
		cout << factorial(n) << endl;
	}
	return 0;
}