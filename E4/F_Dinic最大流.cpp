#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 105;
const int MAXM = 5005;
const long long INF = 1e15;
int depth[MAXN], cur[MAXN], head[MAXN], cntEdge = 1;
struct edge{
	int v, flow, next;
}e[MAXM*2];
void add(int u, int v, int w){//i^1是翻边 从2开始 2^1=3 
	e[++cntEdge].v = v;
	e[cntEdge].flow = w;
	e[cntEdge].next = head[u];
	head[u] = cntEdge;
	
	e[++cntEdge].v = u;
	e[cntEdge].flow = 0;
	e[cntEdge].next = head[v];
	head[v] = cntEdge;
}
void init(){
	memset(head, 0, sizeof head);
	cntEdge = 1;
}

bool BFS(int s, int t){
	memset(depth, 0, sizeof(depth));
	queue<int> q;
	while(!q.empty()){
		q.pop();
	}
	q.push(s);
	depth[s] = 1;
	cur[s] = head[s];
	while(!q.empty()){
		s = q.front();
		q.pop();
		for(int i=head[s]; i!=0; i=e[i].next){
			if(e[i].flow > 0 && depth[e[i].v] == 0){
				depth[e[i].v] = depth[s] + 1;
				cur[e[i].v] = head[e[i].v];
				if(e[i].v == t){
					return true;
				}
				q.push(e[i].v);
			}
		}
	}
	return false;
}
long long DFS(int s, long long flow, int t){
	if(s == t || flow <= 0){
		return flow;
	}
	long long rest = flow;
	for(int i=head[s]; i!=0; i=e[i].next){
		if(e[i].flow > 0 && depth[e[i].v] == depth[s] + 1){
			long long tmp = DFS(e[i].v, min(rest, (long long)e[i].flow), t);
			if(tmp <= 0){//将depth置0意味着将忽视这个点 
				depth[e[i].v] = 0;//优化，如果接收的流量为0，那么就无法推送更多流量 
			}
			rest -= tmp;
			e[i].flow -= tmp;
			e[i ^ 1].flow += tmp;
			if(rest <= 0){
				break;
			}
		}
	}
	return flow - rest;
}
long long Dinic(int s, int t){
	long long ans = 0;
	while(BFS(s, t)){
		ans += DFS(s, INF, t);
	}
	return ans;
}

int main(){
	int T, n, m, s, t, u, v, w;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d %d", &n, &m, &s, &t);
		init();
		for(int i=1;i<=m;i++){
			scanf("%d %d %d", &u, &v, &w);
			add(u, v, w);
		}
		printf("%lld\n", Dinic(s, t));
	}
	return 0;
}
