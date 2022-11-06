#include<stdio.h>
#include<string.h>
#define MAXN 2505

int edges[MAXN][MAXN], dist[MAXN], visited[MAXN];
int n;

int dijkstra(int s, int t){
	for(int i=1;i<=n;i++){//ÿһ���޳�һ���� 
		int index = -1;//index����ǰδ�����ʵľ���s����ĵ�
		dist[s] = 0;//ԭ�㵽ԭ��ľ���Ϊ0 ��ʼ�� 
		for(int j=1;j<=n;j++){//find index
			if(!visited[j] && (dist[j] < dist[index] || index == -1)){
				index = j;
			}
		}
		
		visited[index] = 1;
		for(int j=1;j<=n;j++){//update dist
			if(dist[index] + edges[index][j] < dist[j]){
				dist[j] = dist[index] + edges[index][j];
			}
		}
	}
	
	if(dist[t] == 0x3f3f3f3f){
		return -1;
	}
	return dist[t];
}

int main(){
	memset(edges, 0x3f, sizeof(edges));
	int m, s, t;
	
	scanf("%d %d %d %d", &n, &m, &s, &t);
	int x, y, d;
	for(int i=0;i<m;i++){
		scanf("%d %d %d", &x, &y, &d);
		edges[x][y] = edges[x][y] < d ? edges[x][y] : d;//�ر�
		edges[y][x] = edges[y][x] < d ? edges[y][x] : d;
	}
	
	memset(dist, 0x3f, sizeof(dist));//��ʼ��dist����� 
	memset(visited, 0, sizeof(visited));//��ʼ��visited
	dijkstra(s, t);
	printf("%d", dist[t]);
	return 0;
}
