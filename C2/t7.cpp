#include<stdio.h>
#include<stdlib.h>

int com[205][205];
int g[205][205];
int cnt = 0, mark = 2, n;
int data[40005];

int visited[205][205];
int dfs(int x, int y){
	visited[x][y] = 1;
	int num = 0;
	if(com[x][y]==0){
		return num;
	}else{
		num += 1;
		if(x>0&&visited[x-1][y]==0){
			num+=dfs(x-1, y);
		}
		if(x<n-1&&visited[x+1][y]==0){
			num+=dfs(x+1, y);
		}
		if(y>0&&visited[x][y-1]==0){
			num+=dfs(x, y-1);
		}
		if(y<n-1&&visited[x][y+1]==0){
			num+=dfs(x, y+1);
		}
	}
	return num;
}

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int t;
	char s[205];
	scanf("%d", &t);
	while(t--){
		cnt = 0;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%s", s);
			for(int j=0;j<n;j++){
				com[i][j] = s[j]-'0';
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(com[i][j]==0){
					com[i][j] = 1;
					data[cnt++] = dfs(i, j);
					com[i][j] = 0;
				}
			}
		}
		qsort(data, cnt, sizeof(data[0]), cmp);
		for(int i=0;i<cnt;i++){
			printf("%d ", data[i]);
		}
		printf("\n");
	}
}
