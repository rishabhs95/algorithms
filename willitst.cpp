#include <iostream>
#include <cstring> //memset
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	long long int num;
	bool flagged = false;
	cin >> num;
	while (num > 1LL) {
		if (!(num&1))
			num /= 2;
		else
			num = 3*num+3;
		if (num%3 == 0) {
			flagged = true;
			break;
		}
	}
	if (flagged)
		cout << "NIE" << endl;
	else cout << "TAK" << endl;
	return 0;
}