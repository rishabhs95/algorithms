#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
 
using namespace std;
typedef pair <int, int> pii;
const int MAX = 10000;
 
vector < pair<int, pii> > v;
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
	int m, n, i, j, a, b, edge, wt, sum;
	while (true) {
		sum = 0;
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		initialize();
		for (i = 0; i < n; i++) {
			cin >> a >> b >> wt;
			v.push_back(make_pair(wt, make_pair(a, b)));
			sum += wt;
			// v.push_back(make_pair(wt, make_pair(b, a)));
		}
		sort(v.begin(), v.end());
		cout << sum-kruskals() << endl;
	}
	return 0;
}