#include<cstdio>
#include<cstring>
#define MAXN 1005

char x[MAXN], y[MAXN];
int c[MAXN][MAXN], b[MAXN][MAXN][2];

void printLCS(int i, int j){
	if(i == 0 || j == 0){
		return;
	}
	printLCS(b[i][j][0], b[i][j][1]);
	if(b[i][j][0] == i-1 && b[i][j][1] == j-1){
		printf("%c", x[i]);
	}
}

int main(){
	int lenx, leny;
	scanf("%s", x+1);
	scanf("%s", y+1);
	lenx = strlen(x+1);
	leny = strlen(y+1);
	memset(b, 0, sizeof(b));
	for(int i=0;i<lenx;i++){
		c[i][0] = 0;
	}
	for(int i=0;i<leny;i++){
		c[0][i] = 0;
	}
	for(int i=1;i<=lenx;i++){
		for(int j=1;j<=leny;j++){
			if(x[i] == y[j]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j][0] = i-1;
				b[i][j][1] = j-1;
			}else if(c[i-1][j] > c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j][0] = i-1;
				b[i][j][1] = j;
			}else{
				c[i][j] = c[i][j-1];
				b[i][j][0] = i;
				b[i][j][1] = j-1;
			}
		}
	}
	printLCS(lenx, leny);
	return 0;
}
