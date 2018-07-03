#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Neg[100000];

int main()
{
    int T,M;
    scanf("%d", &T);         
    int i,j,x;
    int min;
    for(i = 0 ; i < T ; i++)
    {
        scanf("%d", &M);
        for(j = 0 ; j < M ; j++)
        {
                scanf("%d", &x);
                if((x == 1) && (j != 0))
                {
                        Neg[j] = Neg[j-1];
                }
                else
                {
                       if((x == 1) && (j == 0))
                       {
                              Neg[0] = 0;
                       }
                       else
                       {
                                if((x == -1) && (j == 0))
                                {
                                        Neg[0] = 1;
                                }
                       }
                       if((x == -1) && (j != 0))
                       {
                                Neg[j] = Neg[j-1] + 1;
                       }
                }
                //printf("Neg at %d : %d\n",j,Neg[j]);
        }
        min = (Neg[M-1] - (2*Neg[0]) + 1);
        //printf("min at 0 %d\n",min);
        for(j = 1 ; j < M ; j++)
        {
                x = (Neg[M-1] + (j+1) - (2*Neg[j]));
                if(x < min)
                {
                        min = x;
                }
                //printf("min at %d %d\n",j,min);
        }
        printf("%d\n",min);
    }
}
