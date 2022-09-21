#include<stdio.h>
#include<math.h>
#define M 1005
int x[M], y[M];

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		int min = 2e9, t;
		scanf("%d", &n);
		for(int i=1;i<=n;i++){
			scanf("%d %d", &x[i], &y[i]);
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				t = max(abs(x[i]-x[j]), abs(y[i]-y[j]));
				if(min > t){
					min = t;
				}
			}
		}
		printf("%d\n", min);
	}
}
