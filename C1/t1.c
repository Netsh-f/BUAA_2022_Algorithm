#include<stdio.h>
#include<math.h>

int main(){
	int t;
	double a, b, k, tt;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%lf %lf %lf", &a, &b, &k);
		tt = log(a) / log(b);
		if(fabs(tt - k) < 1e-9){
			printf("n^k\\log n\n");
		}else if(tt > k){
			printf("n^{\\log_ba}\n");
		}else{
			printf("n^k\n");
		}
	}
	return 0;
}
