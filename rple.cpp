#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, n, r, a, b;
	bool flagged;
	set <int> spy, civil;
	set <int> :: iterator it;
	cin >> test_cases;
	for (int i=1; i<=test_cases; i++) {
		spy.clear();
		civil.clear();
		flagged = false;
		cin >> n >> r;
		for (int j=0; j<r; j++) {
			cin >> a >> b;
			spy.insert(a);
			civil.insert(b);
		}
		for (it = spy.begin(); it != spy.end(); it++)
			if (find(civil.begin(), civil.end(), *it) != civil.end())
				flagged = true;
		cout << "Scenario #" << i << ": ";
		if (flagged)
			cout << "spied" << endl;
		else cout << "spying" << endl;
	}
	return 0;
}