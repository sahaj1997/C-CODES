#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bubble_sort(int* A, int N)
{
        int c=0;
        int i,k,temp;
        for(i = 0; i < N-1 ; i++)
        {
                for(k = 0; k < (N-1-i) ; k++)
                {
                        if(A[k+1] < A[k])
                        {
                                c++;
                                temp = A[k];
                                A[k] = A[k+1];
                                A[k+1] = temp;
                        }
                }
        }
        return c;
}

int main()
{
        int N;
	scanf("%d", &N);
	int i;
	int* A = (int*)malloc(N*(sizeof(int)));
	for(i = 0 ; i < N ; i++)
	{
	        scanf("%d",&A[i]);
	}
	printf("%d",bubble_sort(A,N));
}
