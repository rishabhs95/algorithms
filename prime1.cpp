#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

void simpleSieve(int limit, vector<int> &prime) {
    bool mark[limit+1];
    memset(mark, false, sizeof(mark));
 
    for (long long int i=2; i*i<limit; i++)
        if (mark[i] == false)
            for (long long int i=i*2; i<limit; i+=i)
                mark[i] = true;
 
    for (int i=2; i<limit; i++)
        if (mark[i] == false)
            prime.push_back(i);
}

void segmentedSieve(long long int n, long long int l) {
    int limit = floor(sqrt(n))+1;
    vector<int> prime;  
    simpleSieve(limit, prime); 
 
    bool mark[n-l+1];
    memset(mark, false, sizeof(mark));

    int i = 0;
    while (i < prime.size() && prime[i] <= limit) {
        long long int beg;
        if (prime[i] >= l)
            beg = prime[i] * 2;
        else
            beg = l + ((prime[i] - l % prime[i]) % prime[i]);
        for (long long int j = beg; j <= n; j += prime[i]) {
            mark[j - l] = true;
        }
        i++;
    }

    for (int i = 0; i < n-l; i++)
        if (mark[i] == false)
            cout << mark[i]+l << endl;
}
 
int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test_cases;
    long long int lb, ub;
    cin >> test_cases;
    while (test_cases--) {
    	cin >> lb >> ub;
    	segmentedSieve(ub, lb);
    	cout << endl;
    }
    return 0;
}