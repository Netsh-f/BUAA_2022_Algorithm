#include<stdio.h>
#include<stdlib.h>
#define MAXN 1005

struct node{
	long long v;
	long long w;
	double val;
}a[MAXN];

int cmp(const void *p1, const void *p2){
	struct node *p3 = (struct node*)p1;
	struct node *p4 = (struct node*)p2;
	if(p3->val < p4->val){
		return 1;
	}else{
		return -1;
	}
}

long long n, k, v[MAXN], w[MAXN], ans = 0;
double val[MAXN];

int main(){
	scanf("%lld %lld", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%lld %lld", &a[i].v, &a[i].w);
		a[i].val = a[i].v*1.0/a[i].w;
	}
	qsort(a, n, sizeof(a[0]), cmp);
	for(int i=0;i<n;i++){
		if(k >= a[i].w){
			k -= a[i].w;
			ans += a[i].v;
		}
	}
	printf("%lld", ans);
	return 0;
}
