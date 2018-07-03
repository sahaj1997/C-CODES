#include<stdio.h>
#include<stdlib.h>

#define mod 1000000007

//TOO MUCH MEMORY REQUIRED BY THE PROGRAM ELSE CORRECT TILL 20000


 int fib( int N,  int K,  int* T)
{
         //int S = 0; 
         int i,j;
         //printf("\n\n\n\n\n\n\nNot Just Anybody!\n\n\n\n\n\n\n");
        /*if(N > K)
        {
                if(N-K <= K)
                {
                        S = S + (2 * K + 1 - N);
                        for(i = K+1; i<N ; i++)
                        {
                                if(T[i-1] != 0)
                                {
                                        
                                }else
                                {
                                        for(j =  i-K; j <= i-1 ; j++)
                                        {
                                                T[i-1] += T[j-1];
                                                printf("This is T[%d] j = %d",j,T[j-1]);
                                        }
                                }
                                printf("This is T[%d] i = %d",i,T[i-1]);
                                S = S+T[i-1];
                        }
                }
                else
                {
                        for(i = N-K; i<N ; i++)
                        {
                                if(T[i-1] == 0)
                                {
                                        T[i-1] = fib(i,K,T);
                                }
                                S = S+T[i-1];
                        }
                }
        }
        else
        {
        
        }*/
        /*
        RIGHT COMMENTED CODE
        if(N > (K+1))
        {
                if(T[N-2] != 0)
                {
                        T[N-1] = 2*T[N-2]-T[N-K-1];
                }
                else
                {
                        printf("T[%d] : %d I",N-2,T[N-2]);
                        if(T[N-K-1] != 0)
                        {
                                T[N-2] = fib(N-1,K,T);
                                printf("T[%d] : %d II",N-2,T[N-2]);
                                T[N-1] = 2*T[N-2] - T[N-K-1];
                        }
                        else
                        {
                                T[N-2] = fib(N-1,K,T);
                                printf("T[%d] : %d III",N-2,T[N-2]);
                                T[N-K-1] = fib(N-K-1,K,T);
                                printf("T[%d] : %d IV",N-K-1,T[N-K-1]);
                                T[N-1] = 2*T[N-2] - T[N-K-1];
                        }          
                }
        }
        else
        {
                if(N == K+1)
                {
                        T[N-1] = K;
                }
        }
        printf("This is S : %d for N : %d K : %d\n",T[N-1],N,K);
        return T[N-1];
        */
        if(N > (K+1))
        {
                if(T[N-2] != 0)
                {
                        T[N-1] = (2*T[N-2]-T[N-K-2])%mod;
                }
                else
                {
                        if(T[N-K-2] != 0)
                        {
                                T[N-2] = fib(N-1,K,T)%mod;
                                T[N-1] = (2*T[N-2] - T[N-K-2])%mod;
                        }
                        else
                        {
                                T[N-2] = fib(N-1,K,T)%mod;
                                T[N-K-2] = fib(N-K-1,K,T)%mod;
                                T[N-1] = (2*T[N-2] - T[N-K-2])%mod;
                        }          
                }
        }
        else
        {
                if(N == K+1)
                {
                        T[N-1] = K;
                }
        }
        if(T[N-1] < 0)
        {
                T[N-1] += mod;
        }
        //printf("This is S : %d for N : %d K : %d\n",T[N-1],N,K);
        return T[N-1];
}

int main()
{
         int N,K,S,i;
        scanf("%d",&N);
        scanf("%d",&K);
         int* T;
        if(N > K)
        {
                T = ( int*)malloc(N *sizeof( int));
                for(i = 0 ; i < N ; i++)
                {
                        T[i] = 0;
                        if(i <= K-1)
                        {
                                T[i] = 1;
                        }
                }
                //printf("\n\n\n\n\n\n\nHelp!\n\n\n\n\n\n\n");
                S = fib(N,K,T);
                S = S%mod;
                printf("%d",S);
        }
        else
        {
                printf("1");
        }
        free(T);
        return 1;
}
