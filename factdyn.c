#include <stdio.h>
#define mod 1000000007

int main(){
	long long T;
	scanf("%lld", &T);
	long long int* F;
	long long int* N = (long long int*)malloc(T*sizeof(long long int));
	// Reading input from STDIN
	int i,j;
	int max = 0;
	for(i = 0; i< T ; i++)
	{
	    scanf("%lld",&N[i]);          // Writing output to STDOUT
	    if(max < N[i])
	    {
	        max = N[i];
	    }
	    //printf("%d\n",N[i]);
	}
	    F = (long long int*)malloc((max+1)*sizeof(long long int));
	    F[0] = 1;
	    for(j = 1; j < max; j++)
	    {
	        F[j] = F[j-1]*(j+1);
	        if(F[j] < 0)
	        {   
	            F[j] = F[j] + mod;
	        }
	        else{
	            F[j] = F[j]%mod;
	        }
	    }
	for(i = 0; i< T ; i++)
	{
	    if(N[i] == 0)
	    {
	        printf("1\n");   
	    }
	    else
	    {
	        printf("%lld\n", F[(N[i]-1)]);
	    }
	}

}
