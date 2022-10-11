#include<stdio.h>
#define MAXM 105

long long m, p[3][MAXM], t[3][3], dp[MAXM], line=1, Line[MAXM];

long long change(long long l){
	if(l==1)
		return 2;
	else
		return 1;
}

int main(){
	scanf("%lld", &m);
	for(int i=1;i<=m;i++){
		scanf("%lld", &p[1][i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld", &p[2][i]);
	}
	scanf("%lld %lld", &t[1][1], &t[1][2]);
	scanf("%lld %lld", &t[2][1], &t[2][2]);
	if(p[1][1]<p[2][1]){
		dp[1] = p[1][1];
		line = 1;
	}else{
		dp[1] = p[2][1];
		line = 2;
	}
	Line[1] = line;
	for(int i=2;i<=m;i++){
		if(t[line][line]+p[line][i] < t[line][change(line)]+p[change(line)][i]){
			dp[i] = dp[i-1] + t[line][line] + p[line][i];
		}else{
			dp[i] = dp[i-1] + t[line][change(line)] + p[change(line)][i];
			line = change(line);
		}
		Line[i] = line;
	}
	printf("%lld\n", dp[m]);
	for(int i=1;i<=m;i++){
		printf("Station%d, Line%lld\n", i, Line[i]);
	}
	return 0;
}
