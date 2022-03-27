#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i, j, t, m,n,temp,a[100];
    static int count=0;
    scanf("%d", &t);
    for (m= 0;m<t;m++)
    {
        count=1;
        scanf("%d", &n);
        char b[n];
        scanf("\n%c",b);
        // char *ptr = (char *)malloc(n * sizeof(char));
        // for (i = 0; i < n; i++)
        // {
        //     scanf("%d", ptr + i);
        // }
        a[0]=1;
        for (j = 1; j < n; j++)
        {
            if (b[j] > b[j-1])
            {
                count++;
            }
            else
            {
                count=1;
            }
            a[j+1]=count;
        }
        printf("case #%d:",m+1);
        for(i=0;i<n;i++)
        {
            printf(" %d",a[i]);
        }
        printf("\n");
    }
}