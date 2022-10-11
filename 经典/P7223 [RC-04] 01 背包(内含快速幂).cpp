#include<cstdio>
#define MAX 1000005
#define MOD 998244353

long long a[MAX];

long long fastPower(long long base, long long index){
	base %= MOD;
	long long ret = 1;
	while(index > 0){
		if(index & 1){
			ret = ret * base % MOD;
		}
		base = base * base % MOD;
		index >>= 1;
	}
	return ret % MOD;
}

int main(){
	long long n, p, ans = 1;
	scanf("%lld %lld", &n, &p);
	
	for(int i=0;i<n;i++){
		scanf("%lld", &a[i]);
	}
	for(int i=0;i<n;i++){
		ans = ans * (fastPower(p, a[i]) + 1) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
