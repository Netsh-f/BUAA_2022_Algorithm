#include<stdio.h>
#define N 90
int main(){
	long long c[100][100]={0};
	for(int i=0;i<=N;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	int t;
	scanf("%d",&t);
	printf("%lld\n",c[2*t][t]-c[2*t][t-1]);
	return 0;
}
