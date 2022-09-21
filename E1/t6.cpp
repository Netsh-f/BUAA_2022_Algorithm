#include<stdio.h>
#include<string.h>
#define MAX 100005

int data[MAX], chl[MAX], chr[MAX], magic[MAX];

void add(int pfa, int pch){
	if(chl[pfa] == 0){
		chl[pfa] = pch;
	}else{
		chr[pfa] = pch;
	}
}

void dfs(int pfa, int index){
	index ^= magic[pfa];
	data[pfa] ^= index;
	if(chl[pfa] != 0){
		dfs(chl[pfa], index);
	}
	if(chr[pfa] != 0){
		dfs(chr[pfa], index);
	} 
}

int stack[MAX], top = -1, visited[MAX];
void dfs2(int pfa){
	memset(visited, 0, sizeof(visited[0]));
	stack[++top] = pfa;
	int p, index = 0;
	while(top > -1){
		p = stack[top];
		if(visited[p]==0){
			index ^= magic[p];
			data[p] ^= index;
			visited[p] = 1;
		}
		if((chl[p]==0||visited[chl[p]]==1) && (chr[p]==0||visited[chr[p]]==1)){
			index ^= magic[p];
			top--;
		}
		if(chl[p]!=0 && visited[chl[p]]==0){
			stack[++top] = chl[p];
		}
		if(chr[p]!=0 && visited[chr[p]]==0){
			stack[++top] = chr[p];
		}
	}
}

int main(){
	int t, n, pfa, q, a;
	char s[MAX];
	scanf("%d", &t);
	while(t--){
		memset(chl, 0, sizeof(chl[0]));
		memset(chr, 0, sizeof(chr[0]));
		memset(magic, 0, sizeof(magic[0]));
		memset(data, 0, sizeof(data[0]));
		scanf("%d", &n);
		for(int i=1;i<=n-1;i++){
			scanf(" %d", &pfa);
			add(pfa, i+1);
		}
		scanf(" %s", s);
		for(int i=1;i<=n;i++){
			data[i] = s[i-1] - '0';
		}
		scanf("%d", &q);
		for(int i=1;i<=q;i++){
			scanf("%d", &a);
			magic[a] ^= 1;
		}
//		dfs(1, 0);
		dfs2(1);
		for(int i=1;i<=n;i++){
			printf("%d", data[i]);
		}
		printf("\n");
	}
}
