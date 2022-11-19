#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1005;
struct Point
{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator - (const Point&a)const{return Point(x-a.x,y-a.y);}
    double operator ^ (const Point&a)const{return x*a.y-y*a.x;}
    bool operator < (const Point&a)const{return x!=a.x?x<a.x:y<a.y;}
};
typedef Point Vector;
Point p[N],s[N];

int build(int n)
{
    sort(p+1,p+1+n);
    int tl = 0;
    for(int i=1;i<=n;i++)
    {
        while(tl>1&&((s[tl]-s[tl-1])^(p[i]-s[tl-1]))<=0)tl--;
        s[++tl] = p[i];
    }
    int k = tl;
    for(int i=n-1;i>=1;i--)
    {
        while(tl>k&&((s[tl]-s[tl-1])^(p[i]-s[tl-1]))<=0)tl--;
        s[++tl] = p[i];
    }
    if(tl>1)tl--;
    return tl;
}

int main(){
	int t, n, m;
	double ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
	    for(int i=1;i<=n;i++)
	        scanf("%lf%lf",&p[i].x,&p[i].y);
	    m = build(n);
	    ans = 0.000000;
	    for(int i=2;i<=m;i++){
			ans += sqrt((s[i-1].x - s[i].x)*(s[i-1].x - s[i].x) + (s[i-1].y - s[i].y)*(s[i-1].y - s[i].y));
		}
		ans += sqrt((s[1].x - s[m].x)*(s[1].x - s[m].x) + (s[1].y - s[m].y)*(s[1].y - s[m].y));
		printf("%.10lf\n", ans);
	}
	return 0;
}
