#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int str_mod (string str, int num) {
	int res = 0;
	for (int i = 0; i<str.length(); i++)
		res  = (res*10 + str[i] - '0')%num;
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, num;
	bool visited[20001];
	cin >> test_cases;
	while (test_cases--) {
		memset(visited, false, sizeof(visited));
		cin >> num;
		queue <string> Q;
		Q.push("1");
		visited[1 % num] = true;
		while (!Q.empty()) {
			string ele = Q.front();
			Q.pop();
			if (str_mod(ele, num) == 0) {
				cout << ele << endl;
				break;
			}
			string temp = ele;
			temp.push_back('0');
			ele.push_back('1');
			if (!visited[str_mod(temp, num)]) {
				Q.push(temp);
				visited[str_mod(temp, num)] = true;
			}
			if (!visited[str_mod(ele, num)]) { 
				Q.push(ele);
				visited[str_mod(ele, num)] = true;
			}
		}
	}
	return 0;
}