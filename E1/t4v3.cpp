#include <bits/stdc++.h>
#define maxn 20000086
#define MAX 17000000

using namespace std;

unsigned seed;

int Rand(){
	seed ^= seed << 13;
	seed ^= seed >> 7;
	seed ^= seed << 17;
	return seed & ((1 << 24) - 1);
}

int t, n, a[maxn];
int b[MAX], r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%u", &n, &seed);
		for(int i = 1;i <= n;i++) a[i] = Rand();
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		unsigned ans = 0;
		r = 1;
		for(int i=0;i<MAX;i++){
			if(b[i]>0){
				for(int j=0;j<b[i];j++){
					ans += i^r;
					r++;
				}
				b[i] = 0;
			}
		}
		printf("%u\n", ans);
	}
}  
