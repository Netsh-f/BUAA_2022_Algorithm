#include<cstdio>
#include<cstring>
#define MAXN 1005

char x[MAXN], y[MAXN];
int c[MAXN][MAXN], b[MAXN][MAXN];

void printLCS(int i, int j){
	if(i == 0 || j == 0){
		if(x[i] == y[j]){
			printf("%c", x[i]);
		}
		return;
	}else if(b[i][j] == 3){
		printLCS(i-1, j-1);
		printf("%c", x[i]);
	}else if(b[i][j] == 2){
		printLCS(i-1, j);
	}else{
		printLCS(i, j-1);
	}
}

int main(){
	int lenx, leny;
	scanf("%s", x);
	scanf("%s", y);
	lenx = strlen(x);
	leny = strlen(y);
	memset(b, 0, sizeof(b));
	for(int i=0;i<lenx;i++){
		c[i][0] = 0;
	}
	for(int i=0;i<leny;i++){
		c[0][i] = 0;
	}
	for(int i=1;i<lenx;i++){
		for(int j=1;j<leny;j++){
			if(x[i] == y[j]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 3;// 0:- 1:<- 2:^ 3:\ //
			}else if(c[i-1][j] > c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			}else{
				c[i][j] = c[i][j-1];
				b[i][j] = 1;
			}
		}
	}
	printLCS(lenx-1, leny-1);
	return 0;
}
