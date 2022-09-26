#include<stdio.h>

int isRun(int x){
	int year = x / 10000;
	return (year%4==0 && year%100!=0) || year%400==0;
}

int isYear(int x){
	int m = x/100%100, d = x%100;
	if(d==0){
		return 0;
	}
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
		if(d<=31){
			return 1;
		}
	}else if(m==2){
		if(isRun(x)){
			if(d<=29){
				return 1;
			}
		}else{
			if(d<=28){
				return 1;
			}
		}
	}else if(m==4||m==6||m==9||m==11){
		if(d<=30){
			return 1;
		}
	}
	return 0;
}

int isGood(int x){
	int a[8], t = x;
	for(int i=0;i<8;i++){
		a[7-i] = t%10;
		t = t/10;
	}
	for(int i=0;i<8;i++){
		int f1 = 1, f2 = 1;
		for(int j=0;j<i;j++){
			if(!(a[j]<=a[j+1])){
				f1 = 0;
			}
			if(!(a[j]>=a[j+1])){
				f2 = 0;
			}
		}
		for(int j=i+1;j<8;j++){
			if(!(a[j]<=a[j-1])){
				f1 = 0;
			}
			if(!(a[j]>=a[j-1])){
				f2 = 0;
			}
		}
		if(f1 || f2){
			return 1;
		}
	}
	return 0;
}

int main(){
	int ya, yb, cnt = 0;
	scanf("%d %d", &ya, &yb);
	for(int i=ya;i<=yb;i++){
		if(isYear(i) && isGood(i)){
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
