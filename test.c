#include <stdio.h>

void sort(int values[], int n)
{
    int i,j,temp;
    for (i=0; i < n; i++)
    {
        for (j=i; j > 0 && values[j] < values[j-1]; j--)
        {
            temp = values[j];
            values[j] = values[j-1];
            values[j-1] = temp;
        }
        
    }
    for (i=0; i<10; i++)
        printf("%d",values[i]);
}

int main(void)
{
    int i;
    int array[10] = {9,8,7,1,2,3,4,5,6,7};
    sort(array, 10);
    return 0;
}