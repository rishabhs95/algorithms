#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, n, lim;
	cin >> test_cases;
	while (test_cases--) {
		cin >> n >> lim;
		int human[n], low = 0, high = 0, min_sum = 0, max_count = 0, temp_sum = 0, temp_count = 0;
		for (int i = 0; i < n; ++i)
			cin >> human[i];
		while (low <= high && high < n) {
			if (temp_sum <= lim) {
				temp_sum += human[high];
				if (temp_sum <= lim) {
					min_sum = max(temp_sum, min_sum);
					temp_count++;
				}
				max_count = max(max_count, temp_count);
				high++;
			}
			else {
				temp_sum -= human[low];
				temp_count--;
				if (max_count == temp_count)
					min_sum = min(temp_sum, min_sum);
				low++;
			}
		}
		cout << min_sum << " " << max_count << endl;
	}
	return 0;
}