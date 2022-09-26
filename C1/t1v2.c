#include<stdio.h>

int main(){
	int t;
	long long a, b, k, tt;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%lld %lld %lld", &a, &b, &k);
		tt = 1;
		for(int j=0;j<k;j++){
			tt *= b;
			if(a < tt){
				break;
			}
		}
		if(a > tt){
			printf("n^{\\log_ba}\n");
		}else if(a == tt){
			printf("n^k\\log n\n");
		}else{
			printf("n^k\n");
		}
	}
	return 0;
}
