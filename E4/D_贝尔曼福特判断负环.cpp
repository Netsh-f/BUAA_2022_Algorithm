#include<cstdio>
#include<cstring>
#define MAXN 2005
#define MAXM 6005
const long long INF = 1e9;
long long dis[MAXN], cntEdge;
bool visited[MAXN];
struct edge{
	int u, v, w;
}e[MAXM];

bool bellman_ford(int n, int m){
	for(int i=1;i<=n;i++){
		dis[i] = INF;
	}
	dis[1] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int u = e[j].u, v = e[j].v, w = e[j].w;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				if(i == n){
					return true;//ÓÐ¸º»·
				}
			}
		}
	}
	return false;
}

int main(){
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		cntEdge = 0;
		for(int i=1;i<=m;i++){
			cntEdge++;
			scanf("%d %d %d", &e[cntEdge].u, &e[cntEdge].v, &e[cntEdge].w);
		}
		if(bellman_ford(n, m)){
			printf("boo how\n");
		}else{
			for(int i=1;i<=n;i++){
				printf("%lld ", dis[i]);
			}
			printf("\n");
		}
	}
}
