#include<stdio.h>
#include<math.h>
#define MAX 2100

int **pic;

void paint(int n){
	if(n==1){
		return;
	}else{
		paint(n-1);
	}
	int m = pow(2, n)-1;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)pic+MAX*i+(m+1+j)) = *((int*)pic+MAX*i+j);
		}
	}//右上 
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)pic+MAX*i+j) = 0;
		}
	}//清空左上 
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)pic+MAX*i+j) = *((int*)pic+MAX*(m-1-j)+(m+1+i));
		}
	}//左上 
	*((int*)pic+MAX*0+m) = 1;//上方 

	*((int*)pic+MAX*(m)+(m+1)) = 1;//右方 
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)pic+MAX*(m+1+i)+(m+1+j)) = *((int*)pic+MAX*i+(j+m+1));
		}
	}//右下 
	*((int*)pic+MAX*(2*m)+m) = 1;//下方 
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*((int*)pic+MAX*(m+1+i)+j) = *((int*)pic+MAX*j+(2*m-i));
		}
	}//左下 
	return;
}

int main(){
	pic = (int**)malloc(MAX*sizeof(int*));
	for(int i=0;i<MAX;i++){
		pic[i] = (int*)malloc(MAX*sizeof(int));
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
	paint(n);
	int m = pow(2, n+1)-1;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(*((int*)pic+i*MAX+j)==1){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
