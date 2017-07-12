#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int nums, diff, res = 0;
	cin >> nums >> diff;
	int eles[nums];
	for (int i=0; i<nums; i++)
		cin >> eles[i];
	sort(eles, eles+nums);
	for (int i=0; i<nums; i++) {
		int *index = lower_bound(eles, eles+nums, eles[i]+diff);
		if (*index == eles[i]+diff)
			res++;
	}
	cout << res << endl;
	return 0;
}