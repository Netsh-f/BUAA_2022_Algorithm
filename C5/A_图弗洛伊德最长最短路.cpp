#include<cstdio>
#define N 305
#define M 50005
const long long INF = 1e9;
long long edge[N][N];

int main(){
	int t, n, m, x, y, w;
	long long max, cnt;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				edge[i][j] = INF;
			}
			edge[i][i] = 0;
		}
		for(int i=1;i<=m;i++){
			scanf("%d %d %d", &x, &y, &w);
			edge[x][y] = w;
			edge[y][x] = w;
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
		max = 0;
		cnt = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(edge[i][j] == INF){
					continue;
				}
				if(edge[i][j] == max){
					cnt++;
				}else if(edge[i][j] > max){
					max = edge[i][j];
					cnt = 1;
				}
			}
		}
		printf("%lld %lld\n", max, cnt);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(edge[i][j] == max){
					printf("%d %d\n", i, j);
				}
			}
		}
	}
	return 0;
}
