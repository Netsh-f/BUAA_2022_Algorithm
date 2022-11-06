#include<cstdio>
#include<cstring>
#define MAXN 550

int edges[MAXN][MAXN];
int dist[MAXN];
bool visited[MAXN];

int dijkstra(int n){
	for(int i=1;i<=n;i++){//ÿһ���޳�һ���� 
		int index = -1;//index����ǰδ�����ʵľ���ԭ������ĵ�
		dist[1] = 0;//ԭ�㵽ԭ��ľ���Ϊ0 ��ʼ�� 
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
	memset(edges, 0x3f, sizeof(edges));//��ʼ�� �� Ϊ����� 
	int n, m;
	
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		int start, end, dis;
		scanf("%d %d %d", &start, &end, &dis);
		edges[start][end] = edges[start][end] < dis ? edges[start][end] : dis;//������رߣ�ȡ��С 
	}
	
	memset(dist, 0x3f, sizeof(dist));//��ʼ��dist����� 
	memset(visited, false, sizeof(visited));//��ʼ��visited 
	dijkstra(n);
	for(int i=1;i<=n;i++){
		printf("dist[%d] = %d\n", i, dist[i]);
	}
	printf("ans = %d\n", dist[3]);
	return 0;
}
