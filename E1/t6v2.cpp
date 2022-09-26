#include<stdio.h>
#include<string.h>
#define MAX 100005

int data[MAX], chl[MAX], chr[MAX], stack[MAX], top = -1;
char color[MAX];

void add(int pfa, int pch){
	if(chl[pfa] == 0){
		chl[pfa] = pch;
	}else{
		chr[pfa] = pch;
	}
}

void dfs(int pfa){
	stack[++top] = pfa;
	while(top!=-1){
		int p = stack[top];
		top--;
		data[p] = data[p]==0?1:0;
		if(chl[p]!=0){
			stack[++top] = chl[p];
		}
		if(chr[p]!=0){
			stack[++top] = chr[p];
		}
	}
}

int main(){
	int t, n, pfa, q;
	scanf("%d", &t);
	while(t--){
		memset(chl, 0, sizeof(chl[0]));
		memset(chr, 0, sizeof(chr[0]));
		scanf("%d", &n);
		for(int i=1;i<=n-1;i++){
			scanf("%d", &pfa);
			add(pfa, i+1);
		}
		scanf(" %s", color);
		for(int i=1;i<=n;i++){
			data[i] = color[i-1] - '0';
		}
		scanf("%d", &q);
		for(int i=1;i<=q;i++){
			scanf("%d", &pfa);
			dfs(pfa);
		}
		for(int i=1;i<=n;i++){
			printf("%d", data[i]);
		}
		printf("\n");
	}
}
