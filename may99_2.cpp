#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_cases;
	cin >> test_cases;
	long long int num;
	string dict = "manku";
	while (test_cases--) {
		cin >> num;
		string word;
		while (num > 0) {
			word.push_back(dict[(num%5LL+4)%5LL]);
			num--;
			num /= 5LL;
		}
		reverse(word.begin(), word.end());
		cout << word << endl;
	}	
	return 0;
}