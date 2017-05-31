#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(void)
{
	int flag, nine;
	long int testCases, start, len;
	scanf("%ld", &testCases);
	for (int i=0; i<testCases; i++)
	{
		flag = 0;
		nine = 0;
		string number;
		cin >> number;
		len = strlen(number.c_str());
		char initial[len];
		strcpy(initial, number.c_str());
		(len%2 == 0) ? start = len/2-1 : start = len/2;
		for (long int j=start; j>=0; j--)
		{
			if (flag == 0)
			{	
				if (number[j] != '9' || number[len - j - 1] != '9')
				{
					flag = 1;
					if (len % 2 != 0)				//ODD
					{					
						if (number[j] >= number[len-j-1] && nine == 0)
							number[len - j - 1] = number[j];
						if (number[j] != '9' && nine == 0)
							if (number[j] < number[len-j-1]) 
								number[len - j - 1] = ++number[j];	
						if (nine == 1)
						{
							if (number[j] != '9') 
							{
								for (int k=j+1; k<=start; k++)
									number[k] = number[len-k-1] = '0';
								number[len - j - 1] = ++number[j];
							}
							else 
								if (number[j] == number[len-j-1])
									flag = 0;
								else
									number[len - j - 1] = number[j];
						}
					}
					else							//EVEN
					{
						if (number[j] >= number[len-j-1] && nine == 0)
							number[len - j - 1] = number[j];
						if (number[j] != '9' && nine == 0)
							if (number[j] < number[len-j-1]) 
								number[len - j - 1] = ++number[j];	
						if (nine == 1)
						{
							if (number[j] != '9') 
							{
								for (int k=j+1; k<=start; k++)
									number[k] = number[len-k-1] = '0';
								number[len - j - 1] = ++number[j];
							}
							else 
								if (number[j] == number[len-j-1])
									flag = 0;
								else
									number[len - j - 1] = number[j];
						}
					}
				}
				else
					nine = 1;
			}
			else 
				number[len-j-1] = number[j];
		}
		if (flag == 0)
		{
			for (long int j=start; j>=0; j--)
				number[j] = number[len-j-1] = '0';
		}
		if (strcmp(initial, number.c_str()) == 0)
		{
			if (len%2 == 0)
				number[len - start - 1] = ++number[start];
			else
				++number[start];
		}
		if (flag == 0)
			printf("1%s\n", number.c_str());
		else
			printf("%s\n", number.c_str());
	}
	return 0;
}