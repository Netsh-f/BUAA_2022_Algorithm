#include<stdio.h>
#define M 1000005
#define MOD 998244353

long long f[M];

int main(){
	int t, n;
	
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	f[3] = 7;
	f[4] = 15;
	for(int i=5;i<=1e6+1;i++){
		f[i] = (((f[i-1]+f[i-2])%MOD+4*f[i-3]%MOD)%MOD+2*f[i-4]%MOD) % MOD;
	}
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", f[n]);
	}
	return 0;
}
