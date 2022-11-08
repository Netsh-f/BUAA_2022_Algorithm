#include<cstdio>
#include<queue>
using namespace std;
#define MAXN 100005
#define MAXM 200005
int head[MAXN], cntEdge = 0, in[MAXN], top[MAXN], cntTop = 0;
bool visited[MAXN];
struct edge{
	int v, next;
}e[MAXM];
void add(int u, int v){
	e[++cntEdge].v = v;
	e[cntEdge].next = head[u];
	head[u] = cntEdge;
	in[v]++;
}
void init(int n){
	for(int i=1;i<=n;i++){
		head[i] = 0;
	}
	cntEdge = 0;
}

bool topsort(int n){
	queue<int> q;
	int t;
	cntTop = 0;
	for(int i=1;i<=n;i++){
		if(in[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		t = q.front();
		q.pop();
		top[++cntTop] = t;
		for(int i=head[t]; i!=0; i=e[i].next){
			int j = e[i].v;
			in[j]--;
			if(in[j] == 0){
				q.push(j);
			} 
		}
	}
	if(cntTop == n){
		return true;
	}
	return false;
}

bool findHamiltonpath(int n, int top[]){
	int t;
	bool flag = false;
	for(int i=1;i<n;i++){
		t = top[i];
		flag = false;
		for(int j=head[t]; j!=0; j=e[j].next){
			if(e[j].v == top[i+1]){
				flag = true;
				if(i == n-1){
					return true;
				}
				break;
			}
		}
		if(!flag){
			return false;
		}
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
		if(topsort(n) && findHamiltonpath(n, top)){
			printf("yy\n");
		}else{
			printf("nn\n");
		}
	}
	return 0;
}
