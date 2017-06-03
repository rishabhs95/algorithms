#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <utility>
#include <list>
#include <set>
#include <map>

using namespace std;

vector <int> size, value;

int knapsack(int costMat[][], int index, int cost) {
	if (index == 0 || cost == 0) return 0;
	if (costMat[index][cost] != -1)
		return costMat[mat][cost];
	if (co[index])
	return 
}

int main() {
	freopen("input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
	int s, n;
	cin >> s >> n;
	int costMat[n][s];
	memset(costMat, -1, sizeof(costMat));
	for (int i = 0; i < n; ++i)
		cin >> size[i] >> value[i];
	cout << knapsack(costMat, n, s);
	return 0;
}