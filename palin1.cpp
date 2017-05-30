#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(void)
{
	int nine;
	long int testCases, start, len, flag;
	scanf("%ld", &testCases);
	for (int i = 0; i < testCases; i++)
	{
		nine = 0;
		flag = 0;
		string number;
		cin >> number;
		len = strlen(number.c_str());
		(len % 2 == 0) ? start = len/2 - 1 : start = len/2;
		for (long int j = start; j >= 0; j--)
		{
			*/if (len % 2 != 0)					// odd
			{
				if (number[j] != number[len-j-1])
				{
					
					number[len - j - 1] = number[j];
					flag++;
				}
				if (number[start] != 9)
				{
					++number[start];
					flag++;
				}
			}
			*/else								//even
			{	
				if (number[j] > number[len-j-1])
				{
					number[len - j - 1] = number[j];
					flag++;
				}
				if (number[j] < number[len - j - 1])
				{
					if (flag == 1)
						number[len - j - 1] = ++number[j];
					else
						number[len - j - 1] = number[j];
					flag++;
				}
			}*/
		}
		if (flag == 0)
		{
			for (long int j=start; j>=0; j--)
				number[j] = number[len - j - 1] = '0';
		}
		if (flag == 0)
			printf("1%s\n", number.c_str());
		else
			printf("%s\n", number.c_str());
	}
	return 0;
}