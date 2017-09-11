#include <iostream>
#include <cstdio>
using namespace std;

int parent[100005], wt[100005];

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

void merge (int a, int b, int m) {
	if (root(a) != root(b) && wt[root(a)]+ wt[root(b)] <= m) {
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
	int users, m, q, x, y;
	char type;
	scanf("%d %d %d", &users, &m, &q);;
	initialise(users);
	while (q--) {
		scanf("%s", &type);;
		switch(type) {
			case 'A': 	scanf("%d %d", &x, &y);
						merge(x, y, m);
						break;
			case 'E': 	scanf("%d %d", &x, &y);
						if (root(x) == root(y))
							printf("Yes\n");
						else printf("No\n");
						break;
			case 'S': 	scanf("%d", &x);
						printf("%d\n", wt[root(x)]);
						break;
		}
	}
	return 0;
}