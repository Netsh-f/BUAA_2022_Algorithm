#include<stdio.h>
int n;
char s[25];//1顺 s逆 s[i+1]是第i个的方向

void move(int x, char A, char B, char C){
	if(x == 1){
		if(s[x-1] == '1'){
			printf("move %d from %c to %c\n", x, A, C);
		}else{
			printf("move %d from %c to %c\n", x, A, B);
			printf("move %d from %c to %c\n", x, B, C);
		}
	}else{
		if(s[x-1] == '1'){
			move(x-1, A, C, B);
			printf("move %d from %c to %c\n", x, A, C);
			move(x-1, B, A, C);
		}else{
			move(x-1, A, B, C);
			printf("move %d from %c to %c\n", x, A, B);
			move(x-1, C, B, A);
			printf("move %d from %c to %c\n", x, B, C);
			move(x-1, A, B, C);
		}
	}
} 

int main(){
	while(scanf("%d %s", &n, s) != EOF){
		move(n, 'A', 'B', 'C');
	}
	return 0;
}
