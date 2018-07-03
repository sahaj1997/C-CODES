    #include <stdio.h>
     
    #include <stdlib.h>
     
     
     
    int main () {
     
    	int k, n;
     
    	scanf("%d%d", &n, &k);
     
    	if(n<=k) {
     
    		printf("%d", 1);
     
    		return 0;
     
    	}
     
    	int *v = (int *)malloc((k+1)*sizeof(int));
     
    	int i, from=0;
     
    	v[0]= k;
     
    	for(i=1; i<=k; i++)
     
    		v[i] = 1;
     
    	for(i=k+1; i<n; i++){
     
    		from = (from+1)%(k+1);
     
    		v[from] = (2*v[(from+k)%(k+1)]-v[from]) % 1000000007;
     
    		if(v[from] < 0)
     
    			v[from] += 1000000007;
     
    	}
     
    	printf("%d", v[from]);
     
    	free(v);
     
    } 
