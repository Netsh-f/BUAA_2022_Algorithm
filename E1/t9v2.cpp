#include<stdio.h>
#include<math.h>
#define MAX 2100

int **pic, **tem;

int **paint(int n){
	if(n==1){
		return pic;
	}else{
		paint(n-1);
	}
	int m = pow(2, n)-1;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)tem+MAX*i+j) = *((int*)pic+MAX*i+j);
			*((int*)pic+MAX*i+j) = 0;
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)pic+MAX*i+j) = *((int*)tem+MAX*(m-1-j)+(i));
		}
	}
	*((int*)pic+MAX*0+m) = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)pic+MAX*i+(m+1+j)) = *((int*)tem+MAX*i+j);
		}
	}
	*((int*)pic+MAX*(m)+(m+1)) = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)pic+MAX*(m+1+i)+(m+1+j)) = *((int*)tem+MAX*i+j);
		}
	}
	*((int*)pic+MAX*(2*m)+m) = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)pic+MAX*(m+1+i)+j) = *((int*)tem+MAX*j+(m-1-i));
		}
	}
	return pic;
}

int main(){
	pic = (int**)malloc(MAX*sizeof(int*));
	tem = (int**)malloc(MAX*sizeof(int*));
	for(int i=0;i<MAX;i++){
		pic[i] = (int*)malloc(MAX*sizeof(int));
		tem[i] = (int*)malloc(MAX*sizeof(int));
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			*((int*)pic+i*MAX+j) = 1;
		}
	}
	*((int*)pic+1*MAX+0) = 0;
	*((int*)pic+1*MAX+1) = 0;
	
	int n;
	scanf("%d", &n);
	int **ans = paint(n);
	int m = pow(2, n+1)-1;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(*((int*)ans+i*MAX+j)==1){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
