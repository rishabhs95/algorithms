#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int len, sum;
	while (cin >> len && len != -1) {
		int ele[len], sum = 0, moves = 0;
		for (int i = 0; i < len; ++i) {
			cin >> ele[i];
			sum += ele[i];
		}
		double avg = (double)sum/(double)len;
		int avg_ = sum/len;
		if (avg_ != avg) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < len; ++i) {
			if (ele[i] < avg)
				moves += avg-ele[i];
		}
		cout << moves << endl;
	}
	return 0;
}