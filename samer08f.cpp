#include <iostream>

using namespace std;

long long int calculate(long long int n) {
	return (n*(n+1)*(2*n+1))/6;
}

int main() {
	freopen("input.txt", "r", stdin);
	long long int num;
	while (cin >> num && num != 0) {
		cout << calculate(num) << endl;
	}
	return 0;
}