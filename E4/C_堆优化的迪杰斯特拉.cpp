#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MAXM 1600005
#define MAXN 1000005 //ϡ��ͼ���ö��Ż���Dijkstra 
//head[i]��ʾ��iΪ�������һ���ߵı�ţ�����������ǰ����Ǹ�
long long n, m, s, t, cnt = 0, head[MAXN];
long long dis[MAXN];
bool visited[MAXN];
struct edge{
	int to, next, w;
}e[MAXM*2];

void add(int u, int v, int w){
	e[++cnt].to = v;//��1��ʼ 
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
void dijkstra(int s){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	memset(dis, 0x3f3f, sizeof dis);
	q.push({0, s});//���disΪ0��pair��һ��ֵdis[id]����ά�����id˳��
	dis[s] = 0;
	while(!q.empty()){
		int h = q.top().second;
		q.pop();
		if(visited[h]){
			continue;
		}
		visited[h] = true;
		for(int i=head[h]; i!=0; i=e[i].next){//�����������ڵĵ� 
			int t = e[i].to;
			if(dis[h]+e[i].w < dis[t] && !visited[t]){
				dis[t] = dis[h]+e[i].w;
				q.push({dis[t], t});
			}
		}
	}
}

int main(){
	int u, v, w;
	scanf("%lld %lld %lld %lld", &n, &m, &s, &t);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d", &u, &v, &w);//�رߺ��Ի�
		add(u, v, w);
		add(v, u, w);
	}
	dijkstra(s);
	printf("%lld\n", dis[t]);
	return 0;
}
