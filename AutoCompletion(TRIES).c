#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char c[200000];

char* app(char* a, char b)
{
        //char d[20000];
        char m[2];
        m[0] = b;
        m[1] = '\0';
        //strcpy(m,b);
        strcpy(c,"");
        strcat(c,a);
        strcat(c,m);
        return c;
}

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
        if(((int)(c-'a') < 26) && ((int)(c-'a') >=0))
        {
                return (int)(c-'a');
        }
        if(((int)(c-'A') < 26) && ((int)(c-'A') >=0))
        {
                return (int)(c-'A');
        }
}

char vali(int i)
{
        return (char)((int)'a' + i); 
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

void insert(struct node* trie, char* word)
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
                if(trie->child[v]->pri < 1)
                {
                        trie->child[v]->pri = 1;
                        trie->child[v]->pos = v;
                }
                else
                {
                        trie->child[v]->pri++;
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
                        insert(trie->child[v],c);
                }
        }
        else
        {
                //printf("wrong character inserted");
                return;
        }
}

/*void acc(struct node* trie,char* w)
{
       //char c[200000];
       char d[200000];
       int i;
       if(trie->child != NULL)
        {
        for(i = 0; i < 26; i++)
        {
                if(trie->child[i]->end == 1)
                {
                        strcpy(d,app(w,vali(i)));
                        printf("%s\n",d);
                }
                if(trie->child[i]->child != NULL)
                {
                        strcpy(d,app(w,vali(i)));
                        acc(trie->child[i],d);
                }
        }
        } 
}*/

void dfs(struct node* trie,char* w)
{
        //char c[200000];
        char d[200000];
        int i;
        if(trie->child != NULL)
        {
        for(i = 0; i < 26; i++)
        {
                if(trie->child[i]->end == 1)
                {
                        strcpy(d,app(w,vali(i)));
                        printf("%s\n",d);
                }        
                if(trie->child[i]->child != NULL)
                {
                        strcpy(d,app(w,vali(i)));
                        dfs(trie->child[i],d);
                }
        }
        }
}

int search(struct node* trie, char* word,char* w)
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
                        if(trie->child[v]->end == 1)
                        {
                                printf("%s\n",w);
                        }
                        //printf("%s\n",app(w,vali(v)));
                        //printf("%s\n",app(w,vali(v)));
                        dfs(trie->child[v],w);
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
                        res = search(trie->child[v],c,w);
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
        char word[200000];
        //int weight;
        int i;
        int res;
        //struct node* trie = (struct node*)malloc(sizeof(struct node));
        struct node* trie = ininode();
        for(i =0 ; i < N; i++)
        {
                scanf("%s",word);
                //scanf("%d",&weight);
                insert(trie,word);
        }
        //printf("%d",trie->pri);
        //printf("%d\n",val('z'));
        //printf("%c\n",vali(0));
        //printf("%s\n",app("SAhaj ",'a'));
        scanf("%d",&Q);
        for(i = 0 ; i < Q ; i++)
        {
                scanf("%s",word);
                //insert(trie,word);
                res = search(trie,word,word);
                if(res == -1)
                {
                        printf("No suggestions\n");
                        insert(trie,word);
                }
                /*else
                {
                        printf("%d Out on repair\n",res);
                }*/
                //printf("%d\n",res);
        }
}

