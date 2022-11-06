#include<cstdio>
#include<cstring>
#define MAXN 550

int edges[MAXN][MAXN];
int dist[MAXN];
bool visited[MAXN];

int dijkstra(int n){
	for(int i=1;i<=n;i++){//每一次剔除一个点 
		int index = -1;//index代表当前未被访问的距离原点最近的点
		dist[1] = 0;//原点到原点的距离为0 初始化 
		for(int j=1;j<=n;j++){//find index
			if(!visited[j] && (dist[j] < dist[index] || index == -1)){
				index = j;
			}
		}
		
		visited[index] = true;
		for(int j=1;j<=n;j++){//update dist
			if(dist[index] + edges[index][j] < dist[j]){
				dist[j] = dist[index] + edges[index][j];
			}
		}
	}
	
	if(dist[n] == 0x3f3f3f3f){
		return -1;
	}
	return dist[n];
}

int main(){
	memset(edges, 0x3f, sizeof(edges));//初始化 边 为无穷大 
	int n, m;
	
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		int start, end, dis;
		scanf("%d %d %d", &start, &end, &dis);
		edges[start][end] = edges[start][end] < dis ? edges[start][end] : dis;//如果有重边，取最小 
	}
	
	memset(dist, 0x3f, sizeof(dist));//初始化dist无穷大 
	memset(visited, false, sizeof(visited));//初始化visited 
	dijkstra(n);
	for(int i=1;i<=n;i++){
		printf("dist[%d] = %d\n", i, dist[i]);
	}
	printf("ans = %d\n", dist[3]);
	return 0;
}
