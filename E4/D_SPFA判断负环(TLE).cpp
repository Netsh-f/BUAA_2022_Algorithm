#include<cstdio>
#include<queue>
#define MAXN 2005
#define MAXM 6005
using namespace std;
const long long INF = 1e9;
long long dist[MAXN], head[MAXN], cntEdge, cnt[MAXN];
bool visited[MAXN];
struct edge{
	int v, w, next;
}e[MAXM];

void add(int u, int v, int w){
	e[++cntEdge].v = v;
	e[cntEdge].w = w;
	e[cntEdge].next = head[u];
	head[u] = cntEdge;
} 
bool SPFA(int n, int s){
	for(int i=1;i<=n;i++){
		visited[i] = false;
		cnt[i] = 0;
		dist[i] = INF;
	}
	queue<int> q;
	q.push(s);
	dist[s] = 0; visited[s] = true;
	while(!q.empty()){
		int h = q.front();
		q.pop();
		visited[h] = false;
		for(int i=head[h]; i!=0; i=e[i].next){
			int t = e[i].v;
			if(dist[t] > dist[h] + e[i].w){
				dist[t] = dist[h] + e[i].w;
				cnt[t] = cnt[h] + 1;
				if(cnt[t] >= n){
					return true;
				}
			}
			if(!visited[t]){
				q.push(t);
				visited[t] = true;
			}
		}
	}
	return false;
}
void init(int n){
	cntEdge = 0;
	for(int i=1;i<=n;i++){
		head[i] = 0;
	}
}

int main(){
	int t, n, m, u, v, w;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		init(n);
		for(int i=1;i<=m;i++){
			scanf("%d %d %d", &u, &v, &w);
			add(u, v, w);
		}
		if(SPFA(n, 1)){
			printf("boo how\n");
		}else{
			for(int i=1;i<=n;i++){
				printf("%lld ", dist[i]);
			}
		}
	}
	return 0;
} 
