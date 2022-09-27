#include<stdio.h>
int n;
char s[25];//1顺 s逆 s[i+1]是第i个的方向

void print(int x, char A, char B, char C){
	if((A=='A'&&C=='C')||(A=='C'&&C=='B')||(A=='B'&&C=='A')){
		if(s[x-1]=='1'){
			printf("move %d from %c to %c\n", x, A, C);
		}else{
			printf("move %d from %c to %c\n", x, A, B);
			printf("move %d from %c to %c\n", x, B, C);
		}
	}else{
		if(s[x-1]=='1'){
			printf("move %d from %c to %c\n", x, A, B);
			printf("move %d from %c to %c\n", x, B, C);
		}else{
			printf("move %d from %c to %c\n", x, A, C);
		}
	}
}

void move(int x, char A, char B, char C){
	if(x == 1){
		print(x, A, B, C);
	}else{
		move(x-1, A, C, B);
		print(x, A, B, C);
		move(x-1, B, A, C);
	}
} 

int main(){
	while(scanf("%d %s", &n, s) != EOF){
		move(n, 'A', 'B', 'C');
	}
	return 0;
}
