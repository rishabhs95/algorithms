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
typedef pair <int, int> pii;
const int MAX = 10000;

vector < pair<int, pii> > v;
int cities;
int parent[MAX];

void initialize() {
	v.clear();
    for(int i = 0; i < MAX; i++)
        parent[i] = i;
}

int root(int src) {
	while (parent[src] != src) {
		parent[src] = parent[parent[src]];
		src = parent[src];
	}
	return src;
}

void union1(int x, int y) {
    int p = root(x);
    int q = root(y);
    parent[p] = parent[q];
}

int kruskals() {
	int cost, minimumCost = 0, x, y;
    for(int i = 0; i < v.size(); i++) {
        x = v[i].second.first;
        y = v[i].second.second;
        cost = v[i].first;
        if(root(x) != root(y)) {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases, neigh, i, j, edge, wt;
	string name;
	cin >> test_cases;
	while (test_cases--) {
		cin >> cities;
		initialize();
		for (i = 0; i < cities; i++) {
			cin >> name >> neigh;
			for (j = 0; j < neigh; j++) {
				cin >> edge >> wt;
				v.push_back(make_pair(wt, make_pair(i, edge-1)));
			}
		}
		sort(v.begin(), v.end());
		cout << kruskals() << endl;
	}
	return 0;
}