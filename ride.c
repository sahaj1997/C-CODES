#include <stdio.h>
#include <stdlib.h>


int main()
{
        int T,Tt;
        long int N,Ni,i,Kp,Ks;
        long int* Gi;
        long int* Si;
        scanf("%d",&T);
        Tt = T;
        while(T != 0)
        {
                scanf("%ld %ld",&Kp,&Ks);
                scanf("%ld",&N);
                Ni = N;
                i = 0;
                Gi = (long int*)malloc(N * sizeof(long int));
                Si = (long int*)malloc(N * sizeof(long int));
                while(N != 0)
                {
                      scanf("%ld",&Gi[i]);
                      i++;
                      N--;  
                }
                i = 0;
                N = Ni;
                while(Ni != 0)
                {
                      scanf("%ld",&Si[i]);
                      i++;
                      Ni--;  
                }
                i = 0;
                Ni = N;
                while(N != 0)
                {
                      printf("%ld : %ld\n",Gi[i],Si[i]);
                      i++;
                      N--;  
                }
                T--;
        }
        printf("Case %d: %ld",(Tt - T + 1),Kp); 
}
