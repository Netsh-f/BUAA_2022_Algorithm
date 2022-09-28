#include<stdio.h>
int n;
char s[25];//1顺 r逆 s[i+1]是第i个的方向

void move(int x, char A, char B, char C){ 
	if(x == 1){
		if((s[x-1] == 'l' && ((A=='A'&&C=='C')||(A=='C'&&C=='B')||(A=='B'&&C=='A')))
		||(s[x-1]=='r' && ((A=='A'&&C=='B')||(A=='B'&&C=='C')||(A=='C'&&C=='A')))){
			printf("move %d from %c to %c\n", x, A, C);
		}else{
			printf("move %d from %c to %c\n", x, A, B);
			printf("move %d from %c to %c\n", x, B, C);
		}
	}else{
		if((s[x-1] == 'l' && ((A=='A'&&C=='C')||(A=='C'&&C=='B')||(A=='B'&&C=='A')))
		||(s[x-1]=='r' && ((A=='A'&&C=='B')||(A=='B'&&C=='C')||(A=='C'&&C=='A')))){
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
		printf("\n");
	}
	return 0;
}
