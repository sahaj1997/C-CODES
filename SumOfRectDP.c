#include <stdio.h>

int main(){
	int N,M;
	scanf("%d", &N);              			// Reading input from STDIN
	scanf("%d",&M);
	int i,j;
	int** Mat = (int**)malloc(N*sizeof(int*));
	for(i = 0 ; i < N ; i++)
	{
	    Mat[i] = (int *)malloc(M *sizeof(int));
	    for(j = 0 ; j < M ; j++)
	    {
	        scanf("%d",&Mat[i][j]);
	        //printf("%d",Mat[i][j]);
	    }
	}
	int Q;
	scanf("%d",&Q);
	int** DQ = (int ** )malloc(Q * sizeof(int *));
	int maxx = 0;
	int maxy = 0;
	
	for(i = 0; i < Q ; i++)
	{
	    DQ[i] = (int *)malloc(2 * sizeof(int));
	    scanf("%d",&DQ[i][0]);
	    if(DQ[i][0] > maxx)
	    {
	        maxx = DQ[i][0];
	    }
	    scanf("%d",&DQ[i][1]);
	    if(DQ[i][1] > maxy)
	    {
	        maxy = DQ[i][1];
	    }
	}
	//printf("%d %d",maxx, maxy);
	long long int** D = (long long int ** )malloc(maxx * sizeof(long long int *));
	for(i = 0 ; i < maxx ; i++)
	{
	    D[i] = (long long int *)malloc(maxy *sizeof(long long int));
	    for(j = 0 ; j < maxy ; j++)
	    {
	        if(i == 0 && j == 0)
	        {
	            D[i][j] = Mat[i][j];
	        }
	        else
	        {
	            if(i == 0)
	            {
	                D[0][j] = Mat[0][j] + D[0][j-1];
	            }
	            if(j == 0)
	            {
	                D[i][0] = Mat[i][0] + D[i-1][0];
	            }
	            if(j != 0 && i != 0)
	            {
	                D[i][j] = Mat[i][j] + D[i-1][j] + D[i][j-1] - D[i-1][j-1];    
	            }
	        }
	    }
	}
	for(i = 0; i < Q ; i++)
	{
	    printf("%lld\n",D[DQ[i][0]-1][DQ[i][1]-1]) ;
	}
	//printf("Input number is %d.\n", num);       // Writing output to STDOUT
}
