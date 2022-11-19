#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXN 500005
#define INF 0x7fffffff

struct point{
    double x,y;
}a[MAXN];

int N;
int t[MAXN];

//以x坐标大小为关键词
bool cmp1(point x,point y){
    return x.x<y.x;
}
//以y坐标大小为关键词
bool cmp2(int x,int y){
    return a[x].y<a[y].y;
}

//计算两点距离
double dis(point x,point y){
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}

//核心算法  分治思想
double F(int l,int r){
    if(r-l==0)
        return INF;
    if(r-l==1)  //如果递归完后直接输出距离
        return dis(a[l],a[r]);
    int mid=(l+r)>>1;
    double ans=min(F(l,mid),F(mid+1,r));
    int cnt=0;
    for(int i=l;i<=r;i++)
        //还有一种情况是距离最小的两点刚好分在mid两端ans距离内的点
        if(a[i].x>=a[mid].x-ans&&a[i].x<=a[mid].x+ans)
            t[++cnt]=i;
    sort(t+1,t+cnt+1,cmp2); //以y坐标大小排序
    for(int i=1;i<=cnt;i++)
        for(int j=i+1;j<=cnt;j++){
            if(a[t[j]].y>=a[t[i]].y+ans) break; //两个点的垂直距离超过ans就不必计算了，显然不可能会成为新的ans
            ans=min(ans,dis(a[t[i]],a[t[j]]));
        }
    return ans;
}

int main(){

    cin >> N;   //输入坐标数
    for(int i=1;i<=N;i++)
        cin >> a[i].x >> a[i].y;    //输入坐标
    sort(a+1,a+N+1,cmp1);   //以x坐标大小排序
    printf("%.4lf\n", F(1, N));
//    cout << F(1,N) << endl;     //输出最小点对距离
}
