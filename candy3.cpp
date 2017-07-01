#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, len;
	__int128 sum, suml, sumg;
	cin >> test_cases;
	while (test_cases--) {
		cin >> len;
		__int128 ele[len];
		sum = suml = sumg = 0;
		for (int i = 0; i < len; ++i) {
			cin >> ele[i];
			sum += ele[i];
		}
		// double avg = (double)sum/(double)len;
		__int128 avg = sum/len;
		// if (avg_ != avg) {
		// 	cout << "NO" << endl;
		// 	continue;
		// }
		for (int i = 0; i < len; ++i) {
			if (ele[i] < avg)
				suml += avg-ele[i];
			if (ele[i] > avg)
				sumg += ele[i]-avg;
		}
		if (suml == sumg) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}