#include<cstdio>
#define MAXN 505
long long n, p[MAXN], e[MAXN][MAXN], w[MAXN][MAXN], root[MAXN][MAXN];

int main(){
	int j, t;
	scanf("%lld", &n);
	for(int i=1;i<=n;i++){
		scanf("%lld", &p[i]);
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			j = i+l-1;
			e[i][j] = 2e9;
			w[i][j] = w[i][j-1] + p[j];
			for(int r=i;r<=j;r++){
				t = e[i][r-1] + e[r+1][j] + w[i][j];
				if(t < e[i][j]){
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
	printf("%lld\n", e[1][n]);
	return 0;
}
