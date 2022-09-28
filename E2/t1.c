#include<stdio.h>
#define M 100005

int heap[M], cnt;

void push(int x){
	int p = cnt++, pfa;
	while(p>0){
		pfa = (p-1)/2;
		if(heap[pfa] < x){
			break;
		}
		heap[p] = heap[pfa];
		p = pfa;
	}
	heap[p] = x;
}

int top(){
	return heap[0];
}

int pop(int pos){
	int ret = heap[pos];
	int x = heap[--cnt], p = pos, a, b;
	while(p*2+1<cnt){
		a = p*2+1;
		b = p*2+2;
		if(b<cnt && heap[a] > heap[b]){
			a = b;
		}
		if(x < heap[a]){
			break;
		}
		heap[p] = heap[a];
		p = a;
	}
	heap[p] = x;
	return ret;
}

void dfs(int p, int x){
	if(heap[p] == x){
		pop(p);
		return;
	}
	if(p*2+1<cnt){
		dfs(p*2+1, x);
	}
	if(p*2+2<cnt){
		dfs(p*2+2, x);
	}
}

void del(int x){
	dfs(0, x);
}

int main(){
//	int dat[5] = {3, 10, 0, -3, 999};
//	for(int i=0;i<5;i++){
//		push(dat[i]);
//	}
//	for(int i=0;i<5;i++){
//		printf("%d\n", pop(0));
//	}
	int n, op, x;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &op);
		switch (op) {
			case 1:
				scanf("%d", &x);
				push(x);
				break;
			case 2:
				pop(0);
				break;
			case 3:
				printf("%d\n", top());
				break;
			case 4:
				scanf("%d", &x);
				del(x);
			default:
				break;
		}
	}
	for(int i=0;i<cnt;i++){
		printf("%d ", pop(0));
	}
	return 0;
}
