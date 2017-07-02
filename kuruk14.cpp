#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, len;
	cin >> test_cases;
	while (test_cases--) {
		cin >> len;
		int ele[len], intended_sum = 0, actual_sum = 0;
		bool marked[len], visited[len], flagged = false;
		memset(marked, false, sizeof(marked));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < len; ++i) {
			cin >> ele[i];
			if (ele[i] >= len)
				flagged = true;
			else
				marked[ele[i]] = true;
		}
		if (flagged)
			cout << "NO" << endl;
		else {
			for (int i = 0; i < len; ++i) {
				if (!marked[i])
					intended_sum += i;
				if (visited[ele[i]])
					actual_sum += len-ele[i]-1;
				else
					visited[ele[i]] = true;
			}
			if (actual_sum == intended_sum)
				cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}