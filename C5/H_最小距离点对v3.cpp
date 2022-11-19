#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 500005;
const double INF = 1e10;
int t[N];

struct Point{
	double x, y;
}p[N], temp[N];

bool cmp_y(Point a, Point b){
	return a.y < b.y;
}
bool cmp_x(Point a, Point b){
	return a.x<b.x;
}
bool cmp_y2(int a, int b){
	return p[a].y < p[b].y;
}
inline double dis(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

//double divide(int l, int r){
//	if(r-l == 1){//Ê£Á½¸öµã 
//		return dis(p[l], p[r]);
//	}
//	if(r-l == 2){
//		return min(dis(p[l], p[l+1]), min(dis(p[r], p[r-1]), dis(p[l], p[r])));
//	}
//	int mid = (l+r)>>1;
//	double d = min(divide(l, mid), divide(mid+1, r));
//	
//	int cnt = 0;
//	
//	for(int i=l;i<=r;i++){
//		if(fabs(p[i].x - p[mid].x) < d){
//			temp[++cnt] = p[i];
//		}
//	}
//	sort(temp+1, temp+1+cnt, cmp_y);
//	for(int i=1;i<=cnt;i++){
//		for(int j=i+1;j<=cnt;j++){
//			if(p[j].y-p[i].y >= d){
//				break;
//			}
//			d = min(d, dis(p[i], p[j]));
//		}
//	}
//	return d;
//}

double divide(int l, int r){
	if(r-l == 0){
		return INF;
	}
	if(r-l == 1){
		return dis(p[l], p[r]);
	}
	if(r-l==2){
		return min(dis(p[l], p[l+1]), min(dis(p[r], p[r-1]), dis(p[l], p[r])));
	}
	int mid = (r+l)>>1;
	double d = min(divide(l, mid), divide(mid+1, r));
	int cnt = 0;
	for(int i=l;i<=r;i++){
		if(fabs(p[i].x-p[mid].x) < d){
			t[++cnt] = i;
		}
	}
	sort(t+1, t+1+cnt, cmp_y2);
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(p[t[j]].y >= p[t[i]].y + d){
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
	sort(p+1, p+1+n, cmp_x);
	printf("%.4lf\n", divide(1, n));
	return 0;
}
