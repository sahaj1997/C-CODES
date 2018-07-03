#include <stdio.h>
 
typedef long long llong;
 
llong N;
int M;
 
static inline llong mod(llong x)
{
	return x % M;
}
 
llong modpow(llong b, llong e)
{
	llong r = 1;
	while (e > 0) {
		if (e%2 == 1)
			r = mod(r*b);
		b = mod(b*b);
		e /= 2;
	}
	return r;
}
 
llong modpowsum(llong b, llong n)
{
	if (n == 0)
		return 0;
	llong nb = mod(b*b);
	llong ns = modpowsum(nb, n/2);
	ns = mod((1+b) * ns);
	if (n%2 == 1)
		ns = mod(1 + ns*b);
	return ns;
}
 
int main(void)
{
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%lld %d", &N, &M);
		llong times = N / M;
		llong last = mod(N);
		llong sum = 0;
		for (int i = 1; i < M; ++i) {
			llong cnt = times;
			if (i <= last)
				cnt += 1;
			llong ii = modpow(i,i);
			llong iM = mod(ii * modpow(i, M-i));
			llong s = mod(ii * modpowsum(iM, cnt));
			sum = mod(sum + s);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
