#include <stdio.h>

void printValue(int *x, int A[][*x])
{
    printf("The spiral matrix: \n");
    for(int i=0; i<*x; ++i)
    {
        for(int j=0; j<*x; ++j)
        {
            printf("%10.d", A[i][j]);
        }
        printf("\n");
    }
}
int validacija(int num)
{   if(getchar() == '\n')
    {
        if(num>0)
        {
            return 1; 
        }
        else if(num<0)
        {
            printf("Only natural values required\n");
        }
    }
    else 
    {
        while(getchar() != '\n');
        printf("Wrong symbols! \n");
    }

}


int main()
{
    int i, n, eil=0, st=0, sk=1, kint, index;
    printf("Input matrix size:\n");

    do{
    scanf("%d", &n);
    index=validacija(n);
    }while(index!=1);
    int Mat[n][n], eil_in=n-1, st_in=n-1;

        while(sk<=(n*n))
        {
            for(int i=st; i<st_in+1; ++i)
            {
                Mat[eil][i]=sk++;
            }
            for(int i=eil+1; i<eil_in+1; ++i)
            {
                Mat[i][st_in]=sk++;
            }
            for(int i=st_in-1; i>=st; --i)
            {
                Mat[eil_in][i]=sk++;
            }
            for(int i=eil_in-1; i>=eil+1; --i)
            {
                Mat[i][st]=sk++;
            }
            st++;
            eil++;
            st_in--;
            eil_in--;
        }

        printValue(&n, Mat);

    return 0;
}
