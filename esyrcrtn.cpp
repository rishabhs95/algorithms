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
	int test_cases, res[6] = {1,4,6,5,2,0};
	cin >> test_cases;
	long long int n;
	while (test_cases--) {
		cin >> n;
		cout << res[(n%(long long int)6)-1] << endl;
	}
	return 0;
}