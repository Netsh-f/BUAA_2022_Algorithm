#include<stdio.h>
#define M 100005
int n;

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

int pop(int pos){
	int ret = heap[pos];
	int t = heap[--cnt];
	int p = pos;
	while(p*2+1 < cnt){
		int a = p*2+1, b = p*2+2;
		if(b < cnt && heap[a] > heap[b]){
			a = b;
		}
		if(heap[a] > t){
			break;
		}
		heap[p] = heap[a];
		p = a;
	}
	heap[p] = t;
	
	int pfa;
	p = pos;
	t = heap[pos];
	while(p>0){
		pfa = (p-1)/2;
		if(heap[pfa] < t){
			break;
		}
		heap[p] = heap[pfa];
		p = pfa;
	}
	heap[p] = t;
	
	return ret;
}

int top(){
	return heap[0];
}

int findFlag = 0;
void dfs(int p, int x){
	if(findFlag || p>=cnt || heap[p] > x){
		return;
	}
	if(heap[p] == x){
		pop(p);
		findFlag = 1;
		return;
	}
	if(p*2+1 < cnt){
		dfs(p*2+1, x);
	}
	if(p*2+2 < cnt){
		dfs(p*2+2, x);
	}
}

void del(int x){
	int p;
	for(int i=0;i<cnt;i++){
		if(heap[i]==x){
			p = i;
		}
	}
	pop(p);
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
			pop(0);
		}else if(op == 3){
			printf("%d\n", top());
		}else if(op == 4){
			scanf("%d", &x);
			del(x);
		}else if(op == 5){
			break;
		}
	}
	n = cnt;
	for(int i=0;i<n;i++){
		printf("%d ", pop(0));
	}
	return 0;
}
