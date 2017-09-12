#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int parent[200005], wt[200005];

void initialise(int len) {
	for (int i = 0; i <= len; i++) {
		parent[i] = i;
		wt[i] = 1;
	}
}

int root(int i) {
	while (i != parent[i]) {
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
	return i;
}

void merge (int a, int b) {
	if (root(a) != root(b)) {
		if (wt[root(a)] > wt[root(b)]) {
			wt[root(b)] += wt[root(a)];
			parent[root(a)] = root(b);
		}
		else {
			wt[root(a)] += wt[root(b)];	
			parent[root(b)] = root(a);
		}
	}
}

void display(int len) {
	for (int i = 1; i <= len; ++i) {
		cout << parent[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= len; ++i) {
		cout << wt[i] << " ";
	}
	cout << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, users, cnt;
	string a, b;
	map <string, int> mp;
	scanf("%d", &test_cases);
	while (test_cases--) {
		cnt = 1;
		mp.clear();
		scanf("%d", &users);
		initialise(2*users);
		while (users--) {
			cin >> a >> b;
			if (mp.find(a) == mp.end())
				mp[a] = cnt++;
			if (mp.find(b) == mp.end())
				mp[b] = cnt++;
			merge(mp[a], mp[b]);
			// display(4);
			printf("%d\n", wt[root(mp[a])]);
		}
	}
	return 0;
}