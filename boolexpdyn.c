#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000009

/*int r(int b ,int a )
{
        if(b < a)
        {
                return 1;
        }
        int i = 0;
        int p = 1;
        for(i = a; i < (b+1); i++)
        {
                p*=i;
        }
        for(i = b/2 ; i > 1 ; i--)
        {
                p = p/i;
        }
        return p;
}*/


int opd(int a, int b,int ka ,int kb ,char op)
{
    //printf("%d : %d\n", a, b);
    switch(op)
    {
    case 'a':
    if((a == 0) || (b == 0))
    {
        return 0;
    }
    return (a*b);
    break;
    case 'o':
    if(a == 0)
    {
        return b*(ka);
    }
    if(b == 0)
    {
        return a*(kb);
    }
    return (kb*a + ka*b - a*b);
    break;
    case 'x':
    if(a == 0 && b == 0)
    {
        return 0;
    }
    if(a == 0)
    {
        return b*ka;   
    }
    if(b == 0)
    {
        return a*kb ;
    }
    return (b*(ka-a) + a*(kb-b)) ;
    break;
    default:
    printf("Dont get the character sorry\n");
    exit(0);
    break;
    }
}

int main(){
	char S[3000];
	char OP[3000];
	scanf("%s", S);              			// Reading input from STDIN
	scanf("%s", OP);
	//printf("Input number is %s : %s.\n", S,OP);       // Writing output to STDOUT
	//printf("%d : %d",strlen(S),strlen(OP));
	//printf("%d",(int)S[0]);
	int SL = strlen(S);
	int OPL = strlen(OP);
	int i,j;
	//printf("%d", opd(S[0],S[2],OP[2]));
	//int** D = (int *)malloc(SL * sizeof(int *));
	/*for(i = 0; i < SL ; i++)
	{
	    D[i] = (int *)malloc(SL * sizeof(int));
	    for(j = 0 ; j != i ; j++ )
	    {
	        D[i][j] = opd(S[i],S[j],OP[j]);
	        //printf("%d : for num :%d %d and op :%c",D[i][j],i,j,OP[j]);
	    }
	    printf("\n");
	}*/
	int Q;
	scanf("%d",&Q);
	//printf("%d",Q);
	int** DQ = (int **)malloc(Q * sizeof(int *));
	char res[5];
	int minx,maxx;
	minx = 0;
	maxx = 0;
	for(i = 0 ; i < Q ; i++)
	{
	    //printf("Got here %d\n",(i+1));
	    DQ[i] = (int *)malloc(3 * sizeof(int));
	    scanf("%d",&DQ[i][0]);
	    scanf("%d",&DQ[i][1]);
	    scanf("%s",res);
	    switch(res[0])
	    {
	        case 'f':
	            DQ[i][2] = 0;
	        break;
	        case 't':
	            DQ[i][2] = 1;
	        break;
	    }
	    if(i == 0)
	    {
	        minx = (DQ[i][0]-1);
	    }
	    if(minx > (DQ[i][0]-1))
	    {
	        minx = (DQ[i][0]-1);
	    }
	    if(maxx < (DQ[i][1]-1))
	    {
	        maxx = (DQ[i][1]-1);
	    }
	}
	int* T = (int *)malloc((maxx - minx +1) * sizeof(int));
	T[0] = 1;
	T[1] = 1;
	T[2] = 2;
	for(i = 4 ; i <= (maxx - minx +1) ; i++)
	{
	        for(j = 1; j <= i ;j++)
	        {
	                T[i-1] = (T[i-1] + (T[j-1]*T[i-j-1]))%mod;
	                if(T[i-1] < 0)
	                {
	                        T[i-1] = T[i-1] + mod;
	                }
	                //printf("i+1 : %d T[i] : %d\n",(i+1),T[i]);
	        }
	        //printf("i : %d T[i] : %d\n",i,T[i-1]);
	}
	//printf("min %d : max %d\n",minx,maxx);
	int** F = (int **)malloc((maxx - minx +1) * sizeof(int *));
	int w = 0;
	//printf("maxx - minx + 1 : %d\n",(maxx - minx +1));
	for(i = 0; i < (maxx-minx+1); i++)
	{
	        //printf("%d\n",i);
	        F[i] = (int *)malloc((maxx-minx + 1) *sizeof(int));
	        F[i][i] = ((int)S[i+minx]-48);
	        //printf("i : %d , F[i][i] : %d\n",i,F[i][i]);
	}
	//printf("i on exit %d %d\n",i,(maxx-minx));
	for(w = 0 ; w < (maxx - minx + 1); w++)
	{
	    for(i = 0; i < (maxx - minx + 1); i++)
	    {
	        for(j = i; j < (i + w) ; j++)
	        {
	                if((i+w) < (maxx - minx + 1))
	                {
	                        F[i][i+w] = (F[i][i+w] + opd(F[i][j],F[j+1][i+w],T[j-i],T[i+w-j-1],OP[j]))%mod;
	                        if(F[i][i+w] < 0)
	                        {
	                                F[i][i+w] = F[i][i+w] + mod; 
	                        }
	                        //printf("i : %d i+w : %d F[i][i+w] = %d\n",i,(i+w),F[i][i+w]);
	                }
	        }
	    }
	}
	int k;
	int temp;
	for(i = 0 ; i < Q ; i++)
	{
	        j = DQ[i][0]-1;
	        w = DQ[i][1]-1;
	        k = DQ[i][2];
	        if(k == 1)
	        {
	                
	                printf("%d\n",(F[j][w])%mod);
	        }
	        else
	        {
	                //printf("Fac : %d\n",r(2*(w-j),(w-j+2)));
	                //printf("VaL : %d\n",F[j][w]);
	                //printf("%d\n",(r(2*(w-j),(w-j+2)) - F[j][w])%mod);
	                temp = (T[w-j]-F[j][w])%mod;
	                /*if(temp < 0)
	                {
	                        temp = temp + mod;
	                }*/
	                printf("%d\n",temp);
	        }
	}
}
