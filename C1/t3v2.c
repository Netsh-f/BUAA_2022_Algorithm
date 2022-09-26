#include<stdio.h>
#define M 1000000006
long long a[100005];

int main(){
	int t;
	scanf("%d", &t);
	for(int j=0;j<t;j++){
		long long n, sum1 = 1, sum2 = 1, ans;
		scanf("%lld", &n);
		for(int i=0;i<n;i++){
			scanf("%lld", &a[i]);
		}
		for(int i=0;i<n/2;i++){
			sum1 = (sum1 * a[i]) % M;
		}
		for(int i=n/2;i<n;i++){
			sum2 = (sum2 * a[i]) % M;
		}
		for(int i=0;i<n;i++){
			if(i < n/2){
				ans = sum2;
				for(int k=0;k<n/2;k++){
					if(k != i){
						ans = (ans * a[k]) % M;
					}
				}
			}else{
				ans = sum1;
				for(int k=n/2;k<n;k++){
					if(k != i){
						ans = (ans * a[k]) % M;
					}
				}
			}
			printf("%lld ", ans);
		}
		printf("\n");
	}
}
