// Created by rishabhstr ツ
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

const int SIZE = 1e6;

int A[SIZE], tree[2*SIZE];

void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
        A[idx] += val;
        tree[node] += val;
    }
    else {
        int mid = (start + end) / 2;
        if(start <= idx && idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if(r < start || end < l)
        return 0;
    if(l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, a, b;
	string s;
	cin >> n >> q;
	while (q--) {
		cin >> s >> a >> b;
		if (s == "find")
			cout << query(1, 1, n, a, b) << endl;
		else if (a > 0 && b < n+1)
			update(1, 1, n, a, b);
	}
	return 0;
}