#include <bits/stdc++.h>
#define maxn 20000086

using namespace std;

unsigned seed;

int Rand(){
	seed ^= seed << 13;
	seed ^= seed >> 7;
	seed ^= seed << 17;
	return seed & ((1 << 24) - 1);
}

int t, n, a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%u", &n, &seed);
		for(int i = 1;i <= n;i++) a[i] = Rand();
		sort(a + 1, a + 1 + n);
		for(int i=1;i<=n;i++){
			printf("%d\n", a[i]);
		}
		unsigned ans = 0;
		for(int i = 1;i <= n;i++) ans += a[i] ^ i;
		printf("%u\n", ans);
	}
}  
