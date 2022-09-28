#include<stdio.h>
int main(){
	int t;long long cnta, cntb, n, m, k;
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld%lld", &n, &m, &k);
		cnta = 0;
		for(long long i=k;i<=n;i*=k)
			cnta += n/i - (m/i + (n-m)/i);
		printf("%lld\n", cnta);
	}
	return 0;
}
