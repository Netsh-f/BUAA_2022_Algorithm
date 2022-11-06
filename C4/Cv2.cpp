#include<stdio.h>
#define MAXN 1005
#define MAXK 100005

long long max(long long a, long long b){
	return a>b?a:b;
}

long long n, k, v[MAXN], w[MAXN], ans = 0, f[MAXK];

int main(){
	scanf("%lld %lld", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%lld %lld", &v[i], &w[i]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=k;j>=w[i];j--){
			f[j] = max(f[j], f[j-w[i]]+v[i]);
		}
	}
	
	printf("%lld", f[k]);
	return 0;
}
