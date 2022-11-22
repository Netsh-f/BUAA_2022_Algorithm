#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 500005;
const double INF = 1e10;

struct Point{
	double x, y;
}p[N];

bool cmp_y(Point a, Point b){
	return a.y < b.y;
}
bool cmp(Point a, Point b){
	return a.x==b.x ? a.y<b.y : a.x<b.x;
}
inline double dis(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double divide(int l, int r, Point p[]){
	if(r-l == 1){//Ê£Á½¸öµã 
		return dis(p[l], p[r]);
	}
	if(r-l == 2){
		return min(dis(p[l], p[l+1]), min(dis(p[r], p[r-1]), dis(p[l], p[r])));
	}
	int mid = (l+r)>>1;
	double d = min(divide(l, mid, p), divide(mid+1, r, p));
	
	Point temp[r-l+1];
	int cnt = 0;
	
	for(int i=l;i<=r;i++){
		if(fabs(p[i].x - p[mid].x) < d){
			temp[++cnt] = p[i];
		}
	}
	sort(temp+1, temp+1+cnt, cmp_y);
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(p[j].y-p[i].y >= d){
				break;
			}
			d = min(d, dis(p[i], p[j]));
		}
	}
	return d;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
	sort(p+1, p+1+n, cmp);
	printf("%.4lf\n", divide(1, n, p));
	return 0;
}
