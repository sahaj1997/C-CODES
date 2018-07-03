#include<stdio.h>

int gcd(int x, int y)
{
    	while(x % y != 0) {
    		int tmp = y;
    		y = x % y;
    		x = tmp;
    	}
    	return y;
}    

int main()
{
	int t,i,n,c;
    	scanf("%d",&t);
    	while(t--)
    	{
    		scanf("%d",&n);
    		int i=0;c=0;
    		int a[n];
    		for(i=0;i<n;i++)
    		{
    			scanf("%d",&a[i]);
    		}
    		int k=a[0];int val;
    		for(i=1;i<n;i++)
    		k=gcd(k,a[i]);
    		if(k==1)
    		{
    			printf("0\n");
    		}
    		else
    		{
    			printf("-1\n");
    		}
    		
    	}
    }

