#include<stdio.h>

int fac[210000000];

int main(){
	int t;
	long long n, m;
	scanf("%d", &t);
	
	fac[0] = fac[1] = 1;
	for(int i=2;i<210000000;i++){
		fac[i] = fac[i-1]*i;
		if(fac[i]>1000000000){
			printf("fac[%d]>1e9\n", i);
		}
	}
	
	for(int i=0;i<t;i++){
		scanf("%lld %lld", &n, &m);
		
	}
}
