#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int stations;
	while(scanf("%d",&stations),stations!=0)
	{
		int newDistance[stations], distance = 0, i, flag = 0;
		for (int l=0; l<stations; l++)
			scanf("%d", &newDistance[l]);
		sort(newDistance, newDistance+stations);

		for (int j=0; j<stations; j++)
		{
			if (newDistance[j] - distance > 200) flag =1;
			distance = newDistance[j];
		}
		if (1422 - newDistance[stations-1] > 100) flag = 1;
		if (flag !=1) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}

	return 0;
}