#include<stdio.h>
#include<stdlib.h>
#define MAX 100005

int n, k;
long long ans;
int tree[2*MAX], rank[2*MAX];
struct node{
	long long val;
	int id;
}a[2*MAX];

int lowbit(int x){
	return x&(-x);
}

void add(int p){
	for(int i=p;i<=2*n;i+=lowbit(i)){
		tree[i]++;
	}
}

int sum(int p){
	int s = 0;
	for(int i=p;i>0;i-=lowbit(i)){
		s += tree[i];
	}
	return s;
}

int cmp(const void *a, const void *b){
	return ((struct node*)a)->val > ((struct node*)b)->val ? 1:-1;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i].val);
		a[n+i].val = a[i].val * k;
		
		a[i].id = i;
		a[n+i].id = n+i;
	}
	
	qsort(a+1, 2*n, sizeof(a[0]), cmp);//离散化
	for(int i=1;i<=2*n;i++){
		if(a[i].val!=a[i-1].val)
			rank[a[i].id] = rank[a[i-1].id]+1;
		else
			rank[a[i].id] = rank[a[i-1].id];
	}
	
	for(int i=1;i<=n;i++){
		ans += sum(2*n) - sum(rank[n+i]);//比k*ai大的个数
		add(rank[i]);
	}
	printf("%lld", ans);
	return 0;
}
