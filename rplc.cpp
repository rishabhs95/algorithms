#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	long int test_cases;
	long long int no_of_cokes, sumEnergy, energy, minEnergy;
	scanf("%ld",&test_cases);
	for (long int i=0; i<test_cases; i++)
	{
		sumEnergy = 0;
		minEnergy = 1;
		scanf("%lld",&no_of_cokes);
		for (long int j=0; j<no_of_cokes; j++)
		{
			scanf("%lld",&energy);
			sumEnergy += energy;
			if(sumEnergy <= minEnergy) minEnergy=sumEnergy;
		}
		if (minEnergy<1) 
			minEnergy = 1 - minEnergy;
		printf("Scenario #%ld: %lld\n", i + 1, minEnergy);
	}
	return 0;
}