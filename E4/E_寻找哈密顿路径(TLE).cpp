#include<cstdio>
#define MAXN 100005
#define MAXM 200005
int head[MAXN], cntEdge = 0;
bool visited[MAXN];
struct edge{
	int v, next;
}e[MAXM];
void add(int u, int v){
	e[++cntEdge].v = v;
	e[cntEdge].next = head[u];
	head[u] = cntEdge;
}
void init(int n){
	cntEdge = 0;
	for(int i=1;i<=n;i++){
		head[i] = 0;
		visited[i] = false;
	}
}

bool findHamiltonpath(int n, int u, int cnt){
	if(cnt == n){
		return true;
	}
	for(int i=head[u]; i!=0; i=e[i].next){
		if(!visited[e[i].v]){
			visited[e[i].v] = true;
			if(findHamiltonpath(n, e[i].v, cnt+1)){
				return true;
			}
			visited[e[i].v] = false;
		}
	}
	return false;
}
bool startHamilton(int n, int u){
	visited[u] = true;
	if(findHamiltonpath(n, u, 1)){
		return true;
	}
	return false;
}

int main(){
	int t, n, m, u, v;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		init(n);
		for(int i=1;i<=m;i++){
			scanf("%d %d", &u, &v);
			add(u, v);
		}
		if(startHamilton(n, 1)){
			printf("yy\n");
		}else{
			printf("nn\n");
		}
	}
	return 0;
}
