#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N,M;
    scanf("%d", &N);
    scanf("%d", &M);          
    int i;
    int x,y;
    int C[N][N] ; 
    for(i = 0 ; i < M ; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        C[x-1][y-1] = 1;
    }
    int Q;
    scanf("%d", &Q);
    for(i = 0 ; i < Q ; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        if(C[x-1][y-1] == 1)
        {
                printf("YES\n");
        }
        else
        {
                printf("NO\n");
        }
    }
}
