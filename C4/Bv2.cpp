#include<stdio.h>
#include<stdlib.h>
#define MAXN 1000005

struct Sport{
	int x;
	int y;
}a[MAXN];

int cmp(const void *p1, const void *p2){
	struct Sport *p3 = (struct Sport*)p1;
	struct Sport *p4 = (struct Sport*)p2;
	return p3->y - p4->y;
}

int n;

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	qsort(a, n, sizeof(a[0]), cmp);
	int time = 0, cnt = 0;
	for(int i=0;i<n;i++){
		if(a[i].x >= time){
			cnt++;
			time = a[i].y;
		} 
	}
	printf("%d", cnt);
	return 0;
}
