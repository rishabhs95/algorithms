#include <stdio.h>
#define MAX_PRIME 32000
int primes[MAX_PRIME], req_prime[MAX_PRIME];

int total_prime=0;

void set_to_one()

{

for(int i=0;i<MAX_PRIME;i++)

    primes[i]=1;
}

void preprocess()

{

primes[0]=primes[1]=0;

for(int i=2;i<MAX_PRIME;i++)

{

    if(primes[i])

    {

        req_prime[total_prime++]=i;

        for(int j=i+i;j<MAX_PRIME;j+=i)

        {

            primes[j]=0;

        }

    }

}
}

void check_prime(int n)

{

int count=0;

for(int i=0;i<total_prime;i++)

{

    if(n%req_prime[i]==0 && n!=req_prime[i])

            count++;



    if(req_prime[i]>=n)

        break;

}

if(count==0 && n!=1)

    printf("%d\n",n);
}

void solve_problem(int arr[],int size)

{

for(int i=0;i<size;i++)

{

    check_prime(arr[i]);

}
}

int main()

{

int test,a,b;

scanf("%d",&test);

set_to_one();

preprocess();

while(test--)

{

    scanf("%d%d",&a,&b);

    int arr[b-a+1];

    for(int i=a;i<=b;i++)

        arr[i-a]=i;

    solve_problem(arr,b-a+1);

}

return 0;
}