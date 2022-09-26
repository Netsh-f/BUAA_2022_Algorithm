#include<stdio.h>
#define M 1000000006
int a[100005];

int main(){
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		int n, sum = 1;
		scanf("%d", &n);
		for(int j=0;j<n;j++){
			scanf("%d", &a[j]);
			sum = (sum * a[j]) % M;
		}
		for(int j=0;j<n;j++){
			printf("--%d ", (sum / a[j]) % M);
		}
		printf("\n");
	}
	return 0;
}
