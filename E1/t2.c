#include<stdio.h>
#include<math.h>

int main(){
	int t;
	long long z, k;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%lld %lld", &z, &k);
		if(k >= 3){
			printf("0\n");
		}else if(k == 1){
			printf("%lld\n", z-1);
		}else{
			int cnt = 0;
			for(long long j=1;j<=z-1;j++){
				long long y = sqrt(z*z - j*j);
				if(j*j + y*y == z*z){
					cnt++;
				}
			}
			printf("%d\n", cnt);
		}
	}
}
