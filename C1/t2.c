#include<stdio.h>
#define M 10007

int a[30005], b[30005];
int n, m, q, x, y;

int f1(int x){
	int ans = 0;
	for(int i=n;i>=0;i--){
		ans = (a[i] + x*ans) % M;
	}
	return ans % M;
}

int f2(int y){
	int ans = 0;
	for(int i=m;i>=0;i--){
		ans = (b[i] + y*ans) % M;
	}
	return ans % M;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n+1;i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i=0;i<m+1;i++){
		scanf("%d", &b[i]);
	}
	scanf("%d", &q);
	for(int i=0;i<q;i++){
		scanf("%d %d", &x, &y);
		printf("%d\n", (f1(x) * f2(y)) % M);
	}
	return 0;
}
