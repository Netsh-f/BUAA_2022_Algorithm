#include<cstdio>
#define MAXN 10005

long long n, p[MAXN], w[MAXN];

long long max(long long a, long long b){
	return a>b?a:b;
}

int main(){
	scanf("%lld", &n);
	for(long long i=1;i<=n;i++){
		scanf("%lld", &p[i]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			w[j] = max(w[j], w[j-i]+p[i]);
		}
	}
	printf("%lld\n", w[n]);
	return 0;
}
