#include<stdio.h>

int main(){
	int n, m, x;
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d", &n);
		if(n==2){
			scanf("%d %d %d", &x, &x, &x);
		}else if(n==1){
			scanf("%d %d", &x, &x);
		}else{
			scanf("%d %d", &x, &x);
			printf("0\n");
		}
	}
	return 0;
} 
