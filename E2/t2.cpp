#include<stdio.h>
#define M 998244353
#define MAX 1000005
long long f[MAX];
long long a[MAX];

int main(){
	int t, n;
	scanf("%d", &t);
	
	f[0]=1, f[1]=1, f[2]=2, f[3]=9, f[4]=21;
	a[0]=f[0], a[1]=f[1], a[2]=a[0]+f[2], a[3]=a[1]+f[3], a[4]=a[2]+f[4];
	for(int i=5;i<MAX;i++){
		f[i] = (f[i-1]+f[i-2]+6*f[i-3]%M+4*f[i-4]%M+2*a[i-5]+2*a[i-6])%M;
		a[i] = a[i-2] + f[i];
	}
	
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", f[n]);
	}
	return 0;
}
