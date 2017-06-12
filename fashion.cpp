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

int main() {
	freopen("input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		int n, x;
		vector <long long int> men, women;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> x;
			men.push_back(x);
		}
		for (int i=0; i<n; i++) {
			cin >> x;
			women.push_back(x);
		}
		sort(men.begin(), men.end());
		sort(women.begin(), women.end());
		long long int res = 0;
		for (int i=0; i<n; i++)
			res += men[i] * women[i];
		cout << res << endl;
	}
	return 0;
}