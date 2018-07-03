#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int M;
	scanf("%d", &M);              			// Reading input from STDIN
	
    int i,ind,k;
    int j;
    int X;
    int* C;
    int* L;
    unsigned long long int sum;
    int min; 
    //C = ini(2000);
    for(i = 0 ; i < M ; i++)
    {
        sum = 0;
        scanf("%d",&X);
        C = (int *)malloc(X*sizeof(int));
        L = (int *)malloc(X*sizeof(int));
        for(j = 0 ; j < X ; j++)
        {
                scanf("%d",&(C[j]));
        }
        for(j = 0 ; j < X ; j++)
        {
                scanf("%d",&L[j]);
        }
        //quick_sort(C,0,X-1);
        /*for(j = 0; j < X ; j++)
        {
                printf("Index : %d , Value : %d\n",C[j]->index,C[j]->val);
        }*/
        min = C[0];
        for(j = 0; j < X ; j++)
        {
                ind = C[j];       
                if(ind < min)
                {
                        min = ind;
                }
                sum += (unsigned long long int)L[j]*(min);
        }
        printf("%lld\n",sum);
        //swap(&C[0],&C[1]);
    }
}
