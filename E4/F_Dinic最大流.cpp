#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 105;
const int MAXM = 5005;
const long long INF = 1e15;
int depth[MAXN], cur[MAXN], head[MAXN], cntEdge = 0;
struct edge{
	int u, v, flow, next, rev;
}e[MAXN];
void add(int u, int v, int w){
	e[++cntEdge].u = u;
	e[cntEdge].v = v;
	e[cntEdge].flow = w;
	e[cntEdge].next = head[u];
	if(head[u] != 0){
		e[head[u]].rev = cntEdge;
	}
	head[u] = cntEdge;
}
void init(){
	memset(head, 0, sizeof head);
	cntEdge = 0;
}

bool BFS(int s, int t){
	memset(depth, 0, sizeof(depth));
	queue<int> q;
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
//				if(e[i].v == t){
//					return true;
//				}
				q.push(e[i].v);
			} 
		}
	}
	if(depth[t] != 0){
		return true;
	}
	return false;
}
long long DFS(int s, long long flow, int t){
	if(s == t || flow <= 0){
		return flow;
	}
	long long rest = flow;
	for(int i=cur[s]; i!=0; i=e[i].next){
		if(e[i].flow > 0 && depth[e[i].v] == depth[s] + 1){
			long long tmp = DFS(e[i].v, min(rest, (long long)e[i].flow), t);
			if(tmp <= 0){//将depth置0意味着将忽视这个点 
				depth[e[i].v] = 0;//优化，如果接收的流量为0，那么就无法推送更多流量 
			}
			rest -= tmp;
			e[i].flow -= tmp;
//			e[e[i].rev].flow += tmp;
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
