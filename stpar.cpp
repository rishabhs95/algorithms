#include <iostream>
#include <cstring> //memset
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int len, i, temp, index;
	bool flagged;
	while (cin >> len && len != 0) {
		flagged = false;
		index = 1;
		stack <int> S;
		while (len--) {
			cin >> temp;
			if (temp == index) {
				index++;
				continue;
			}
			while (!S.empty() && (S.top() == index)) {
				S.pop();
				index++;
			}
			if (temp != index)
				S.push(temp);
		}
		while (!S.empty()) {
			if (S.top() != index)
				break;
			S.pop();
			index++;
		}
		if (!S.empty())
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return 0;
}