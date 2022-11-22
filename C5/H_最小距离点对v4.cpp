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

//��x�����СΪ�ؼ���
bool cmp1(point x,point y){
    return x.x<y.x;
}
//��y�����СΪ�ؼ���
bool cmp2(int x,int y){
    return a[x].y<a[y].y;
}

//�����������
double dis(point x,point y){
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}

//�����㷨  ����˼��
double F(int l,int r){
    if(r-l==0)
        return INF;
    if(r-l==1)  //����ݹ����ֱ���������
        return dis(a[l],a[r]);
    int mid=(l+r)>>1;
    double ans=min(F(l,mid),F(mid+1,r));
    int cnt=0;
    for(int i=l;i<=r;i++)
        //����һ������Ǿ�����С������պ÷���mid����ans�����ڵĵ�
        if(a[i].x>=a[mid].x-ans&&a[i].x<=a[mid].x+ans)
            t[++cnt]=i;
    sort(t+1,t+cnt+1,cmp2); //��y�����С����
    for(int i=1;i<=cnt;i++)
        for(int j=i+1;j<=cnt;j++){
            if(a[t[j]].y>=a[t[i]].y+ans) break; //������Ĵ�ֱ���볬��ans�Ͳ��ؼ����ˣ���Ȼ�����ܻ��Ϊ�µ�ans
            ans=min(ans,dis(a[t[i]],a[t[j]]));
        }
    return ans;
}

int main(){

    cin >> N;   //����������
    for(int i=1;i<=N;i++)
        cin >> a[i].x >> a[i].y;    //��������
    sort(a+1,a+N+1,cmp1);   //��x�����С����
    printf("%.4lf\n", F(1, N));
//    cout << F(1,N) << endl;     //�����С��Ծ���
}
