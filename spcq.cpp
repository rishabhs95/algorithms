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

long long int sum(long long int num) {
	long long int res = 0;
	while (num > 0) {
		res += num%10;
		num /= 10;
	}
	return res;
}

void spcq(long long int n) {
	while (!(n%sum(n) == 0))
		n++;
	cout << n << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases;
	cin >> test_cases;
	long long int num;
	while (test_cases--) {
		cin >> num;
		spcq(num);
	}
	return 0;
}