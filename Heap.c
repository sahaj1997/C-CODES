#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int LENGTH;

int heapSize;

void Heapify(long int* A, int i)
{
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest;

  if(l <= heapSize && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if(r <= heapSize && A[r] > A[largest])
    largest = r;
  if(largest != i)
    {
      int temp = A[i];
      A[i] = A[largest];
      A[largest] = temp;
      Heapify(A, largest);
    }
}

void BuildHeap(long int* A)
{
  heapSize = LENGTH - 1;
  int i;
  for(i = (LENGTH - 1) / 2; i >= 0; i--)
    Heapify(A, i);
}

void sort(long int* A)
{
  BuildHeap(A);
  int i;
  for(i = LENGTH - 1; i > (LENGTH - 4); i--)
    {
      int temp = A[heapSize];
      A[heapSize] = A[0];
      A[0] = temp;
      heapSize--;
      Heapify(A, 0);
    }
}

void top_3(long int A[],int j)
{
        int i;
        for(i = 0; i < 3 ; i++)
        {
                printf("%ld ",A[j-i]);
        }
        printf("\n");
}

int main()
{
        int T,N;
	scanf("%d", &T);
	int i;
	long int A[100000];
	for(i = 0; i < T; i++)
	{
	        scanf("%ld",&A[i]);
	        LENGTH = (i+1);
	        if(i < 2)
	        {
	                printf("-1\n");
	        }
	        else
	        {
	                sort(A);
	                top_3(A,i);
	        }
	}
}
