#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 305

long long n, a[MAXN], dp[MAXN][MAXN];

long long min(long long a, long long b){
	return a<b?a:b;
}

int main(){
	scanf("%lld", &n);
	for(int i=1;i<=n+1;i++){
		scanf("%lld", &a[i]);
	}
	memset(dp, 127, sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][i] = 0;
		dp[i][i+1] = 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j+i<=n+1;j++){
			for(int k=j+1;k<j+i;k++){
				dp[j][j+i] = min(dp[j][j+i], dp[j][k]+dp[k][j+i]+a[j]*a[k]*a[j+i]);
			}
		}
	}
	printf("%lld\n", dp[1][n+1]);
	return 0;
}
