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
 
int main(void) {
	freopen("input.txt", "r", stdin);
	int test_cases, number;
	cin >> test_cases;
	for (int i=0; i<test_cases; i++) {
		set <long long int> data;
		cin >> number;
		long long int ele, sum = 0;
		for (int j=0; j<number; j++) {
			cin >> ele;
			data.insert(ele);
		}
		set <long long int> :: iterator j;
		long long int counter = 0, len = data.size()-1;
		for (j=data.begin(); j!=data.end(); j++) {
			sum += counter*(*j) - (len-counter)*(*j);
			counter++;
		}
		cout << sum << endl;
	}
	return 0;
} 