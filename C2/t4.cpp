#include <bits/stdc++.h>
#define maxn 10000086

using namespace std;

unsigned seed;

unsigned Rand(){
	seed ^= seed << 13;
	seed ^= seed >> 7;
	seed ^= seed << 17;
	return seed;
}

int t, n, k;
int fa[maxn];
unsigned a[maxn];
unsigned maxk[maxn], maxt;
int maxp;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%u", &n, &k, &seed);
		for(int i = 2;i <= n;i++) fa[i] = i - 1;
		maxt = 0;
		for(int i = 1;i <= n;i++){
			a[i] = Rand();
			if(i-k+1 > maxp){
				maxt = 0;
				for(int j=maxp+1;j<=i;j++){
					if(a[j]>maxt){
						maxt = a[j];
						maxp = j;
					}
				}
			}
			if(a[i]>maxt){
				maxt = a[i];
				maxp = i;
			}
			maxk[i] = maxt;
		}
		unsigned ans = 0;
		for(int i = 1;i <= n;i++){
//			unsigned mx = 0;
//			int x = i;
//			for(int j = 1;j <= k;j++){
//				mx = max(mx, a[x]);
//				if(x == 1) break;
//				x = fa[x];
//			}
			ans += maxk[i] ^ i;
		}
		printf("%u\n", ans);
	}
}  
