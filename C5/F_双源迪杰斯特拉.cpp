#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N = 100005;
const int M = 500005;
const long long INF = 1e10;
bool visited[N];

int head[N], cnt, point[N];
struct edge{
	int to, next, w;
}e[M*2];
void add(int u, int v, int w){
	e[++cnt].to = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
} 

void djkstra(int s, long long dis[]){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	for(int i=1;i<N;i++){
		dis[i] = INF;
		visited[i] = false;
	}
	dis[s] = 0;
	q.push({0, s});
	while(!q.empty()){
		int h = q.top().second;
		q.pop();
		if(visited[h]){
			continue;
		}
		visited[h] = true;
		for(int i=head[h]; i!=0; i=e[i].next){
			int t = e[i].to;
			if(dis[h] + e[i].w < dis[t] && !visited[t]){
				dis[t] = dis[h] + e[i].w;
				q.push({dis[t], t});
			}
		}
	}
}

int main(){
	int n, m, k, u, v, w;
	long long dis1[N], dis2[N];
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d", &point[i]);
	}
	djkstra(1, dis1);
	djkstra(n, dis2);
	long long min = INF;
	for(int i=1;i<=k;i++){
		if(dis1[point[i]] + dis2[point[i]] < min){
			min = dis1[point[i]] + dis2[point[i]];
		}
	}
	printf("%lld\n", min);
	return 0;
}
