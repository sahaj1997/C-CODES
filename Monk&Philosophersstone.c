#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[10005];

struct nst
{
    int s;
    struct nst* link;
}; 
// A structure to represent a stack
struct Stack
{
    struct nst* link;
};

struct nst* crtsn()
{
        struct nst* nst = (struct nst*)malloc(sizeof(struct nst));
        nst->s = 0;
        nst->link = NULL;
        return nst;
}

struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->link = NULL;
    return stack;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{   
    return stack->link == NULL;  
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int s)
{
    struct nst* item = crtsn();
    item->s = s;
    if(isEmpty(stack))
    {
        stack->link = item;
    }
    else
    {

        item->link = stack->link;
        stack->link = item;
    }
    //printf("%lld pushed to stack\n", stack->link->symbol);
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return 0;
    
    struct nst* temp = crtsn();
    temp = stack->link;
    stack->link = stack->link->link;
    return temp->s;
}

int main(){
	int N,i;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
	        scanf("%d",&A[i]);
	}
	int Q,X;
	scanf("%d", &Q);
	scanf("%d", &X);
	char c[10];
	int j = 0;
	int k = 0;
	int sum = 0;
	struct Stack* stack = createStack(); 
	for(i = 0; i < Q ; i++)
	{
	        scanf("%s",c);
	        if(strcmp(c,"Harry") == 0)
	        {
	                sum += A[j];
	                push(stack,A[j]);
                        j++;
                        k++;
	        }
	        else
	        {
	                if(strcmp(c,"Remove") == 0)
	                {
	                    sum = sum - pop(stack);
	                    k--;    
	                }
	        }
	        if(sum == X)
	        {
	                printf("%d\n",k);
	                return 0;
	        }
	}
	printf("-1");
}
