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
	int test_cases, n, x;
	cin >> test_cases;
	while (test_cases--) {
		cin >> n;
		if (!n) {
			cout << "NO" << endl;
			continue;
		}
		vector <int> elements;
		while (n--) {
			cin >> x;
			elements.push_back(x);
		}
		if (elements.size() > 1)
			for (int i = 1; i < elements.size(); i++)
				elements[i] = elements[i]-min(elements[i], elements[i-1]);
		if (elements[elements.size()-1]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}