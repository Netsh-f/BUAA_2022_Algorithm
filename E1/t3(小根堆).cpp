#include<stdio.h>
#include<string.h>
#define M 200005

struct dat{
	int x;
	int line;
}a[M], heap[M];

int cnt;
int pos[M];

void push(struct dat t){
	int p = cnt++;
	while(p > 0){
		int fat = (p-1)/2;
		if(heap[fat].x < t.x){
			break;
		}
		heap[p] = heap[fat];
		p = fat;
	}
	heap[p] = t;
}

struct dat pop(){
	struct dat ret = heap[0];
	struct dat t = heap[--cnt];
	int p = 0;
	while(p*2+1 < cnt){
		int a = p*2+1, b = p*2+2;
		if(b<cnt && heap[b].x<heap[a].x){
			a = b;
		}
		if(heap[a].x > t.x){
			break;
		}
		heap[p] = heap[a];
		p = a;
	}
	heap[p] = t;
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int j=0;j<t;j++){
		cnt = 0;
		int k, n, num = 0;
		scanf("%d %d", &k, &n);
		for(int i=0;i<k;i++){
			for(int l=0;l<n;l++){
				scanf("%d", &a[i*n+l].x);
				a[i*n+l].line = i;
			}
			pos[i] = 0;
		}

		for(int i=0;i<k;i++){
			push(a[i*n + pos[i]]);
			pos[i]++;
		}		
		while(num<k*n){
			struct dat root = pop();
			printf("%d ", root.x);
			if(pos[root.line] < n){
				push(a[root.line*n + pos[root.line]]);
				pos[root.line]++;
			}
			num++;
		}
		printf("\n");
	}
}
