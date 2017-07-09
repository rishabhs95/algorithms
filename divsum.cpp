#include <iostream>
using namespace std;

int main(void)
{
	int test_cases=0;
	scanf("%ld",&test_cases);
	for (i=0; i<test_cases; i++)
	{
		divsum = 0;
		scanf("%ld",&number);
		for (j=1; j<number; j++)
		{
			if(number%j == 0)
				divsum += j;
 		}
 		printf("%ld\n",divsum);
	} 
	return 0;
}