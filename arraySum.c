#include<stdio.h>
#include<string.h>

int isPrime(int n)

{

    if(n == 0 || n == 1)

        return 0;

    int i;

    for(i=2; i<n; i++)

    {

        if(n%i==0)

            return 0;

    }

    return 1;

}

int main()

{

    int i, j, temp;

    int a[5];

    for(i=0; i<5; i++)

    {

        scanf("%d", &a[i]);

    }

    for(i=0; i<5; i++)

    {

        for(j=0; j<5-i-1; j++)

        {

            if(a[j]>a[j+1])

            {

                temp=a[j];

                a[j]=a[j+1];

                a[j+1]=temp;

            }

        }

    }

    for(i=0; i<5; i++)

    {

        printf("%d ", a[i]);

    }



    int num = a[0] + a[4];

    if(isPrime(num) == 1)

    {

        printf("Prime");

    }

    else

        printf("Not Prime");

    return 0;

}

