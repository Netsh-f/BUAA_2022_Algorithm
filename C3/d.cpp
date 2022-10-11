#include<stdio.h>
#define MAXN 1000005

long long t, n, a[MAXN], dp[MAXN];

long long max(long long a, long long b){
	return a>b?a:b;
}

int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		for(int i=1;i<=n;i++){
			scanf("%lld", &a[i]);
		}
		dp[0] = 0;
		dp[1] = a[1];
		for(int i=2;i<=n;i++){
			dp[i] = max(dp[i-2]+a[i], dp[i-1]);
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}
