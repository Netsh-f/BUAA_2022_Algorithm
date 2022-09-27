#include<stdio.h>
#define MAX 2500
int c[11][11];

int visited[MAX], a[11], m, cnt;
void f(int depth, int n, int r){
	if(cnt>=m){
		return;
	}
	for(int i=a[depth-1]+1;i<=n;i++){
//		if(visited[i] == 0){
			a[depth] = i;
			if(depth == r){
				printf("%d ", r);
				for(int j=1;j<=r;j++){
					printf("%d ", a[j]);
				}
				printf("\n");
				cnt++;
				if(cnt>=m)
					break;
			}else{
				f(depth+1, n, r);
			}
			visited[i] = 0;
//		}
	}
}

int main(){
	int t, n;
	
	c[0][0]=c[1][0] = c[1][1] = 1;
	for(int i=2;i<=10;i++){
		c[i][0] = 1;
		for(int j=1;j<=i;j++){
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		if(m>c[n][n/2]){
			printf("-1\n");
		}else{
			cnt = 0;
			f(1, n, n/2);
		}
	}
	return 0;
}
