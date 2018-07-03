#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 1000000

int C[X] ; 
int left_reach[X+5][2];
int right_reach[X+5][2];

int main()
{
    int N,M;
    scanf("%d", &N); 
    //printf("%d", N);        
    int i,j;
    int x,sum;
    for(i = 1 ; i <= (N-1) ; i++)
    {
        scanf("%d", &C[i]);
        //printf("%d",C[i]);
    }
    for(i = 0 ; i <= (N-1) ; i++)
    {
        if(C[i])
        {
                left_reach[i+1][1] = left_reach[i][1] + 1;
                left_reach[i+1][0] = 1;
        }
        else
        {
                left_reach[i+1][0] = left_reach[i][0] + 1;
                left_reach[i+1][1] = 1;
        }
    }
    for(i = N ; i >= 1 ; i--)
    {
        if(C[i])
        {
                right_reach[i][0] = right_reach[i+1][0] + 1;
                right_reach[i][1] = 1;
        }
        else
        {
                right_reach[i][1] = right_reach[i+1][1] + 1;
                right_reach[i][0] = 1;
        }
    }
    int Q;
    scanf("%d", &Q);
    char c[1];
    char s;
    int t = 0;
    for(i = 0 ; i < Q ; i++)
    {
        sum = 0;
        scanf("%s", c);
        s = (char)c[0];
        switch(s) 
        {
                case 'Q' :
                        scanf("%d", &x);
                        sum = (left_reach[x][t]) + (right_reach[x][t])-1;
                        printf("%d\n",sum);
                break; 
                case 'U' :
                        t = t^1;
                break;
                default :
                //printf("Somethings' wrong\n");
                //printf("c = %c\n",s);
                break;
        
        }
        
    }
    //printf("%d %d \n",(0^1),(1^1));
}
