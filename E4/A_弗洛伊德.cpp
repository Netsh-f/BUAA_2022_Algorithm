#include<cstdio>
#include<cstring>
#define MAXN 505
const long long inf = 1e11;
long long n, m, q, edge[MAXN][MAXN];
int main(){
	long long x, y, w;
	scanf("%lld %lld %lld", &n, &m, &q);
	for(int i=1;i<MAXN;i++){
		for(int j=1;j<MAXN;j++){
			edge[i][j] = inf;
		}
		edge[i][i] = 0;
	}
	for(int i=0;i<m;i++){
		scanf("%lld %lld %lld", &x, &y, &w);
		if(w < edge[x][y]){
			edge[x][y] = w;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(edge[i][k] + edge[k][j] < edge[i][j]){
					edge[i][j] = edge[i][k] + edge[k][j];
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		scanf("%lld %lld", &x, &y);
		if(edge[x][y] == inf){
			printf("No So1ution\n");
		}else{
			printf("%lld\n", edge[x][y]);
		}
	}
	return 0;
}
