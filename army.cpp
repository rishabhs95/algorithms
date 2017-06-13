#include <iostream>
#include <queue>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
	int g, mg, x, test_cases;
	cin >> test_cases;
	while (test_cases--) {
		priority_queue <int> godzilla, mecha_godzilla;
		cin >> g >> mg;
		while (g--) {
			cin >> x;
			godzilla.push(x);

		}
		while (mg--) {
			cin >> x;
			mecha_godzilla.push(x);
		}
		while (!godzilla.empty() && !mecha_godzilla.empty()) {
			if (godzilla.top() < mecha_godzilla.top())
				godzilla.pop();
			else mecha_godzilla.pop();
		}
		if (mecha_godzilla.empty())
			cout << "Godzilla" << endl;
		if (godzilla.empty())
			cout << "MechaGodzilla" << endl;
	}
	return 0;
}