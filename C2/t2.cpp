#include<stdio.h>
#define M 100005
int n;

int heap[M], cnt;

void push(int x){
	int p = cnt++, pfa;
	while(p>0){
		pfa = (p-1)/2;
		if(heap[pfa] > x){
			break;
		}
		heap[p] = heap[pfa];
		p = pfa;
	}
	heap[p] = x;
}

int pop(){
	int ret = heap[0];
	int t = heap[--cnt];
	int p = 0;
	while(p*2+1 < cnt){
		int a = p*2+1, b = p*2+2;
		if(b < cnt && heap[a] < heap[b]){
			a = b;
		}
		if(heap[a] < t){
			break;
		}
		heap[p] = heap[a];
		p = a;
	}
	heap[p] = t;
	return ret;
}

int top(){
	return heap[0];
}

int main(){
	int op, x;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &op);
		if(op == 1){
			scanf("%d", &x);
			push(x);
		}else if(op == 2){
			pop();
		}else if(op == 3){
			printf("%d\n", top());
		}
	}
	n = cnt;
	for(int i=0;i<n;i++){
		printf("%d ", pop());
	}
	return 0;
}
