#include<stdio.h>
#define MAXN 1005

long long t, n, m, a[MAXN][MAXN], dp[MAXN][MAXN];

long long max(long long a, long long b){
	return a>b?a:b;
}

int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld", &n, &m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%lld", &a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			dp[i][1] = dp[i-1][1] + a[i][1];
		}
		for(int i=1;i<=n;i++){
			dp[1][i] = dp[1][i-1] + a[1][i];
		}
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i][j-1]);
			}
		}
		printf("%lld\n", dp[n][m]);
	}
	return 0;
}
