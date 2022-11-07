#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 200005
#define MAXM 500005
long long n, m, parent[MAXN], Rank[MAXN], cost = 0;//并查集 DisJointSetUnion
struct edge{
	int u, v, w;
}e[MAXM], minTree[MAXN];
bool cmp(const edge a, const edge b){
	return a.w < b.w;
}

void initParent(){
	for(int i=0;i<MAXN;i++){
		parent[i] = i;
		Rank[i] = 1;
	}
}
int find(int x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find(parent[x]);//路径压缩，直接指向根节点
		return parent[x];
	}
}
void merge(int x, int y){
	int rx = find(x);
	int ry = find(y);
	if(rx != ry){
		if(Rank[x] < Rank[y]){
			swap(rx, ry);//保证Rank[rx]>Rank[ry]，秩大的做父节点 
		}
		parent[ry] = rx;
		if(Rank[rx] == Rank[ry]){
			Rank[rx] += 1;
		}
	}
}

void kruskal(){
	int cntMinTree = 0;
	sort(e+1, e+m+1, cmp);
	initParent();
	for(int i=1;i<=m;i++){
		if(find(e[i].u) != find(e[i].v)){
			minTree[cntMinTree++] = e[i];
			cost += e[i].w;
			merge(e[i].u, e[i].v);
			if(cntMinTree == n-1){
				break;
			}
		}
	}
}

int main(){
	scanf("%lld %lld", &n, &m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	}
	kruskal();
	printf("%lld\n", cost);
	return 0;
}
