#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int n, m, x, res;
	cin >> n;
	set <int> friends, friends_of_friends;
	set <int> :: iterator it;
	while (n--) {
		cin >> m;
		friends.insert(m);
		cin >> m;
		while (m--) {
			cin >> x;
			friends_of_friends.insert(x);
		}
	}
	res = friends_of_friends.size();
	for (it = friends.begin(); it != friends.end(); it++)
		if (find(friends_of_friends.begin(), friends_of_friends.end(), *it) != friends_of_friends.end())
			res--;
	cout << res << endl;
	return 0;
}