#include<cstdio>
#include<cmath>

int main(){
	int t;
	double x[4], y[4], ans;
	scanf("%d", &t);
	while(t--){
		for(int i=1;i<=3;i++){
			scanf("%lf %lf", &x[i], &y[i]);
		}
		long long a1 = x[2]-x[1], a2 = y[2]-y[1], b1 = x[3]-x[1], b2 = y[3]-y[1];
		long long s = a1*b2 - b1*a2;
		if(s<0) s = -s;
		if(s%2 != 0){
			printf("%lld.5\n", s/2);
		}else{
			printf("%lld.0\n", s/2);
		}
//		ans = fabs(x[1]*y[2] - x[1]*y[3] + x[2]*y[3] - x[2]*y[1] +x[3]*y[1] - x[3]*y[2]) / 2;
//		printf("%.1lf\n", ans);
	}
	return 0;
}
