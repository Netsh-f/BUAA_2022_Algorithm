#include<stdio.h>
#define M 1000000006
long long a[100005], b[100005], c[100005];


int main(){
	int t;
	scanf("%d", &t);
	for(int j=0;j<t;j++){
		long long n;
		scanf("%lld", &n);
		for(int i=0;i<n;i++){
			scanf("%lld", &a[i]);
		}
		b[0] = a[0];
		for(int i=1;i<n;i++){
			b[i] = b[i-1] * a[i] % M;
		}
		c[n-1] = a[n-1];
		for(int i=n-2;i>=0;i--){
			c[i] = c[i+1] * a[i] % M;
		}
		for(int i=0;i<n;i++){
			if(i == 0){
				printf("%lld ", c[i+1]);
			}else if(i == n-1){
				printf("%lld ", b[i-1]);
			}else{
				printf("%lld ", b[i-1] * c[i+1] % M);
			}
		}
		printf("\n");
	}
	return 0;
}
