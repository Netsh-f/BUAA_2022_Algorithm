#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 500005;
const int MAXDIS = 2000005;
int inde[MAXDIS];

struct Point
{
    double x,y;
};
Point point[N];

bool cmp_x(Point a, Point b){
	return a.x < b.x;
}
bool cmp_y(int a, int b){
	return point[a].y < point[b].y;
}

double disMax(Point a, Point b){
	return fabs(a.x -b.x) > fabs(a.y-b.y)?fabs(a.x -b.x):fabs(a.y-b.y);
}

double minDis(int p, int q){
	if(p-q==0){
		return 10000000;
	}else if(q-p == 1){
		return disMax(point[p], point[q]);
	}else{
		double disMin = 0;
		int m = (p+q)/2;
		disMin = min(minDis(p, m-1), minDis(m+1, q));
		int tmp_p;
		for(int i=p;i<=q;i++){
            if (point[i].x >= (point[m].x - disMin) && point[i].x <= (point[m].x + disMin)){
                inde[tmp_p] = i;
                tmp_p++;
            }
		}
		sort(inde, inde+tmp_p, cmp_y);
        for (int i = 0; i < tmp_p; i++){
            for (int j = i + 1; j < tmp_p; j++){
                if (point[inde[j]].y - point[inde[i]].y >= disMin) {
                    break;
                }
                disMin = min(disMin, disMax(point[inde[i]], point[inde[j]]));
            }
        }
        return disMin;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf", &point[i].x, &point[i].y);
	}
	sort(point+1, point+n+1, cmp_x);
	printf("%.4lf\n", minDis(1, n));
	return 0;
}
