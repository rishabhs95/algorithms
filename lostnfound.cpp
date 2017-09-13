#include <iostream>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int parent[100005], wt[100005];
multiset <int> s;
multiset <int> :: iterator it;

void initialise(int len) {
	parent[0] = 0;
	wt[0] = 1;
	for (int i = 1; i <= len; i++) {
		parent[i] = i;
		wt[i] = 1;
		s.insert(wt[i]);
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
	int n, q, a, b;
	scanf("%d %d", &n, &q);
	initialise(n);
	while (q--) {
		scanf("%d %d", &a, &b);
		if (root(a) != root(b)) {
			s.erase(s.find(wt[root(a)]));
			s.erase(s.find(wt[root(b)]));
			merge(a, b);
			s.insert(wt[root(a)]);
		}
		// display(n);
		cout << (*(s.rbegin()) - *(s.begin())) << endl;
	}
	return 0;
}