#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ull unsigned long long int
ull cnt[26];
ull comb(char *a, int n)
{
ull ans=0;
for(int b=0;b<n;++b)
{
for(int d=b+1;d<n;++d)
{
if(a[b]==a[d])
{
for(int c=b+1;c<d;++c)
{
ans += cnt[a[c]-'a']; // add the combinations in b/w b and d, suh that xa==ac && c>a
}
}
}
cnt[a[b]-'a']++;// count all characters before the position b
}


return ans;
}

int main()
{
        int T,N;
	scanf("%d", &N);
	int i,j;
	char A[N];
	scanf("%s",A);
	printf("%lld",comb(A,N));
}
