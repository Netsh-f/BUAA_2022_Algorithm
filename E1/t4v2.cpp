#include <bits/stdc++.h>
#define maxn 20000086
#define MAX 20000000

using namespace std;

unsigned seed;
int b[MAX];

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
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		unsigned ans = 0;
		int rank = 1;
		for(int i=0;i<MAX;i++){
			if(b[i] > 0){
				while(b[i]--){
					ans += i^rank;
					rank++;
				}
			}
		}
		printf("%u\n", ans);
	}
}  
