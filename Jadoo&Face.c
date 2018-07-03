#include <stdio.h>

int main(){
	int r,c;
	scanf("%d", &r);              			// Reading input from STDIN
	scanf("%d", &c);
	int i, j;
	int q;
	int** img = (int **)malloc(r *sizeof(int *));
	for(i = 0 ; i < r ; i++)
	{
	    img[i] = (int *)malloc(c * sizeof(int));
	    for(j = 0 ; j < c ; j++)
	    {
	        scanf("%d", &img[i][j]);
	        //printf("%d",img[i][j]);
	    }
	}
	scanf("%d",&q);
	int** DQ = (int**)malloc(q * sizeof(int *)); 
	int minx1, miny1;
	int maxx2 , maxy2;
	minx1 = 0 ;
	miny1 = 0;
	maxx2 = 0;
	maxy2 = 0;
	for(i = 0 ; i < q ; i++)
	{
	    DQ[i] = (int *)malloc(4 * sizeof(int));
	    scanf("%d",&DQ[i][0]);
	    if(minx1 > DQ[i][0])
	    {
	        minx1 = DQ[i][0];
	    }
	    scanf("%d",&DQ[i][1]);
	    if(miny1 > DQ[i][1])
	    {
	        miny1 = DQ[i][1];
	        //printf("%d\n",miny1);
	    }
	    if(i == 0)
	    {
	        minx1 = DQ[i][0];
	        miny1 = DQ[i][1];
	        //printf("%d ,,,,,,,, %d\n",minx1,miny1);
	    }
	    scanf("%d",&DQ[i][2]);
	    if(maxx2 < DQ[i][2])
	    {
	        maxx2 = DQ[i][2];
	    }
	    scanf("%d",&DQ[i][3]);
	    if(maxy2 < DQ[i][3])
	    {
	        maxy2 = DQ[i][3];
	    }
	}
	//printf("%d , %d , %d , %d",minx1,miny1,maxx2,maxy2);
	//printf("Input number is %d.\n", num);       // Writing output to STDOUT
	int** D = (int **)malloc((maxx2 - minx1 + 1) * sizeof(int *));
	for(i = minx1 ; i < (maxx2 + 1) ; i++)
	{
	    D[(i-minx1)] = (int *)malloc((maxy2 - miny1 + 1) * sizeof(int));
	    for(j = miny1 ; j < (maxy2 + 1) ; j++)
	    {
	        //D[(i-minx1)][(j-miny1)] = img[i][j];
	        //printf("%d ",D[(i-minx1)][(j-miny1)]);
	        //printf("%d %d \n", (i - minx1),(j - miny1));
	        //printf("%d ", img[i][j]);
	        if((i-minx1) == 0 && (j-miny1) == 0)
	        {
	            D[(i-minx1)][(j-miny1)] = img[i][j];
	        }
	        else
	        {
	            if((i-minx1) == 0)
	            {
	                D[(i-minx1)][(j-miny1)] = D[(i-minx1)][(j-miny1 - 1)] + img[i][j];
	            }
	            if((j-miny1) == 0)
	            {
	                D[(i-minx1)][(j-miny1)] = D[(i-minx1 - 1)][(j-miny1)] + img[i][j];
	            }
	            if((i-minx1) != 0 && (j-miny1) != 0)
	            {
	                D[(i-minx1)][(j-miny1)] = D[(i-minx1 - 1)][(j-miny1)] + D[(i-minx1)][(j-miny1 - 1)] - D[(i-minx1 - 1)][(j-miny1 - 1)] + img[i][j];
	            }
	        }
	    }
	    //printf("\n");
	}
	int k;
	int mx,my;
	for(k = 0 ; k < q ; k++)
	{
	    i = DQ[k][0];
	    j = DQ[k][1];
	    mx = DQ[k][2];
	    my = DQ[k][3];
	    if((i-minx1) == 0 && (j-miny1) == 0)
	        {
	            printf("%d\n",D[mx - minx1][my - miny1]);
	            //D[(i-minx1)][(j-miny1)] = img[i][j];
	        }
	        else
	        {
	            if((i-minx1) == 0)
	            {
	                printf("%d\n",(D[mx - minx1][my - miny1] - D[mx - minx1][j - miny1 -1] ));
	                //D[(i-minx1)][(j-miny1)] = D[(i-minx1)][(j-miny1 - 1)] + img[i][j];
	            }
	            if((j-miny1) == 0)
	            {
	                printf("%d\n",(D[mx - minx1][my - miny1]-D[i - minx1 - 1][my - miny1]));
	                //D[(i-minx1)][(j-miny1)] = D[(i-minx1 - 1)][(j-miny1)] + img[i][j];
	            }
	            if((i-minx1) != 0 && (j-miny1) != 0)
	            {
	                printf("%d\n",(D[mx - minx1][my - miny1] + D[i - minx1 - 1][j - miny1 -1] -D[i - minx1 - 1][my - miny1] -D[mx - minx1][j - miny1 -1]));
	                //D[(i-minx1)][(j-miny1)] = D[(i-minx1 - 1)][(j-miny1)] + D[(i-minx1)][(j-miny1 - 1)] - D[(i-minx1 - 1)][(j-miny1 - 1)] + img[i][j];
	            }
	        }
	}
	
