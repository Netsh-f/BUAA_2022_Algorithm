#include<stdio.h>

void func(int p[][10]){
	p[3][4] = 100;
}

int main(){
	int a[10][10] = {{3,4,5},{6,7,8}};
	func(a);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
