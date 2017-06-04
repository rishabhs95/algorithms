#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

void sieve(bool x[], int limit) {
	for (int i = 2; i < limit; i++)
		if (x[i] == false)
			for (int j = i; i*j < limit; j++)
				x[i*j] = true;
}

int string_to_int(string str) {
	int res = 0;
	for (int i = 0; i < str.length(); i++)
		res = res * 10 + (str[i]-'0');
	return res;
}

int main() {
	// freopen("input.txt", "r", stdin);

	// precalculated primes
	bool prime[10000] = {false};
	bool visited[10000];
	prime[0] = true;
	prime[1] = true;
	sieve(prime, 10000);

	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		memset(visited, 0, sizeof(visited));
		string a, b;
		cin >> a >> b;
		bool flag = false;
		//bfs and check each generation's primality by sieve
		queue < pair<string, int> > Q;
		Q.push(make_pair(a, 0));
		visited[string_to_int(a)] = true;
		while (!Q.empty()) {
			pair <string, int> ele = Q.front();
			Q.pop();
			// cout << ele.first << " " << ele.second << endl;
			if (ele.first == b) {
				cout << ele.second << endl;
				flag = true;
				break;
			}
			for (int i = 0; i < ele.first.length(); i++) {
				for (char c = '0'; c <= '9'; c++) {
					if (i == 0 && c == '0')
						continue;
					string temp = ele.first;
					temp[i] = c;
					if (!prime[string_to_int(temp)] && !visited[string_to_int(temp)]) {
						Q.push(make_pair(temp, ele.second+1));
						visited[string_to_int(temp)] = true;
					}
				}
			}
		}
		if (flag == false) cout << "Impossible" << endl;
	}
	return 0;
}