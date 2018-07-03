#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct D
{
        int val;
        int index;
};

/*struct D** Qsort(struct D* C)
{

}*/

void swap(struct D** A , struct D** A1)
{       
        struct D* temp = *A;
        *A = *A1;
        *A1 = temp;
}

int partition ( struct D** A ,int start , int end) {
    int i = start + 1;
    struct D* piv = A[start] ;            //make the first element as pivot element.
    for(int j =start + 1; j <= end ; j++ )  {
    
          if ( A[ j ]->val < piv->val) {
                 swap (&A[ i ],&A [ j ]);
            i += 1;
        }
   }
   swap ( &A[ start ] ,&A[ i-1 ] ) ;  //put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}

void quick_sort ( struct D** A ,int start , int end ) {
   if( start < end ) {
        //stores the position of pivot element
         int piv_pos = partition (A,start , end ) ;     
         quick_sort (A,start , piv_pos -1);    //sorts the left side of pivot.
         quick_sort ( A,piv_pos +1 , end) ; //sorts the right side of pivot.
   }
}

struct D* ininode()
{
        struct D* trie = (struct D*)malloc(sizeof(struct D));
        trie->val = 0;
        trie->index = 0;
        return trie;
}

struct D** ini(int X)
{
        struct D** chi = (struct D**)malloc(X * sizeof(struct D*));
        int i;
        for(i = 0 ; i < X ; i++)
        {
                chi[i] = ininode();
        }
        return chi;
}

int main(){
	int M;
	scanf("%d", &M);              			// Reading input from STDIN
	
    int i,ind,k;
    int j;
    int X;
    struct D** C;
    int* L;
    unsigned long long int sum;
    int min; 
    //C = ini(2000);
    for(i = 0 ; i < M ; i++)
    {
        sum = 0;
        scanf("%d",&X);
        C = ini(X);
        L = (int *)malloc(X*sizeof(int));
        for(j = 0 ; j < X ; j++)
        {
                scanf("%d",&(C[j]->val));
                C[j]->index = j;
        }
        for(j = 0 ; j < X ; j++)
        {
                scanf("%d",&L[j]);
        }
        quick_sort(C,0,X-1);
        /*for(j = 0; j < X ; j++)
        {
                printf("Index : %d , Value : %d\n",C[j]->index,C[j]->val);
        }*/
        min = X-1;
        for(j = 0; j < X ; j++)
        {
                ind = C[j]->index;       
                if(ind <= min)
                {
                        for(k = ind; k <= min; k++)
                        {
                                sum += L[k]*(C[j]->val);
                        }
                        min = ind-1;
                }
                if((min == -1))
                {
                        break;
                }
        }
        printf("%lld\n",sum);
        //swap(&C[0],&C[1]);
    }
}
