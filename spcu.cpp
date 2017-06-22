#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
	int test_cases, member, h;
	cin >> test_cases;
	while (test_cases--) {
		bool flag = false;
		cin >> member;
		for (int i = 0; i < member; ++i) {
			cin >> h;
			if (h > i) {
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}