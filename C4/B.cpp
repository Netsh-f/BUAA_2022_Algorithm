#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MAXN 1000005
struct Sport{
	int x;
	int y;
}a[MAXN];

bool cmp(const void *p1, const void *p2){
	Sport *p3 = (Sport*)p1;
	Sport *p4 = (Sport*)p2;
	return p3->y > p4->y;
}

int n;

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a, a+n, cmp);
	
}
