#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
        struct node** child;
        int pri;
        int end;
        int pos;
};

int val(char c)
{
        //printf("%c",c);
        return (int)(c-'a');
}

struct node* ininode()
{
        struct node* trie = (struct node*)malloc(sizeof(struct node));
        trie->child = NULL;
        trie->pri = 0;
        trie->end = 0;
        trie->pos = 0;
        return trie;
}

struct node** inich()
{
        struct node** chi = (struct node**)malloc(26 * sizeof(struct node*));
        int i;
        for(i = 0 ; i < 26 ; i++)
        {
                chi[i] = ininode();
        }
        return chi;
}

void insert(struct node* trie, char* word, int weight)
{
        if((word == NULL) || (word == '\0'))
        {
                return;
        }
        int i;
        int v = val(word[0]);
        if((v < 26) && (v >=0))
        {
                if(trie == NULL)
                {
                        trie = ininode();
                }
                if(trie->child == NULL)
                {
                        trie->child = inich();
                }
                if(trie->child[v]->pri < weight)
                {
                        trie->child[v]->pri = weight;
                        trie->child[v]->pos = v;
                }
                if(strlen(word) == 1)
                {
                        trie->child[v]->end = 1;
                        return;
                }
                else
                {       
                        char c[strlen(word)-1];
                        for(i=0;i < strlen(word);i++)
                        {
                                c[i] = word[i+1];
                        }
                        c[i] = '\0';
                        insert(trie->child[v],c,weight);
                }
        }
        else
        {
                //printf("wrong character inserted");
                return;
        }
}

int search(struct node* trie, char* word)
{
        if((word == NULL) || (word == '\0'))
        {
                return -1;
        }
        int i;
        int res;
        int v = val(word[0]);
        if((v < 26) && (v >=0))
        {
                if(trie == NULL)
                {
                        return -1;
                }
                if(strlen(word) == 1)
                {
                        if(trie->child == NULL)
                        {
                                return -1;
                        }
                        if((trie->child[v]->child == NULL) && (trie->child[v]->end != 1))
                        {
                                return -1;
                        }
                        //printf("I am %c : %d\n",word[0],trie->child[v]->pri);
                        return trie->child[v]->pri;
                }
                else
                {       
                        char c[strlen(word)-1];
                        if(trie->child == NULL)
                        {
                                return -1;
                        }
                        for(i=0;i < strlen(word);i++)
                        {
                                c[i] = word[i+1];
                        }
                        c[i] = '\0';
                        res = search(trie->child[v],c);
                }
        }
        else
        {
                //printf("wrong character inserted");
                return -1;
        }
        return res;
}

int main()
{
        int N,Q;
        scanf("%d",&N);
        scanf("%d",&Q);
        char word[1000000];
        int weight;
        int i;
        int res;
        //struct node* trie = (struct node*)malloc(sizeof(struct node));
        struct node* trie = ininode();
        for(i =0 ; i < N; i++)
        {
                scanf("%s",word);
                scanf("%d",&weight);
                insert(trie,word,weight);
        }
        //printf("%d",trie->pri);
        //printf("%d\n",val('z'));
        for(i = 0 ; i < Q ; i++)
        {
                scanf("%s",word);
                res = search(trie,word);
                printf("%d\n",res);
        }
}

