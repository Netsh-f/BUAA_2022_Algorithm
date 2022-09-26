#include<stdio.h>
int a[100005], b[100005], A[100005], B[100005];
int c[200005], C[200005];

int main(){
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		int n, m, cnt = 0;
		scanf("%d", &n);
		for(int j=1;j<=n;j++){
			scanf("%d", &a[j]);
		}
		for(int j=1;j<=n;j++){
			scanf("%d", &A[j]);
		}
		scanf("%d", &m);
		for(int j=1;j<=m;j++){
			scanf("%d", &b[j]);
		}
		for(int j=1;j<=m;j++){
			scanf("%d", &B[j]);
		}
		
		int pa = 1, pb = 1;
		while(pa<=n && pb<=m){
			if(A[pa] == B[pb]){
				if(a[pa] + b[pb] != 0){
					cnt++;
					c[cnt] = a[pa] + b[pb];
					C[cnt] = A[pa];
				}
				pa++; pb++;
			}else if(A[pa] < B[pb]){
				cnt++;
				c[cnt] = a[pa];
				C[cnt] = A[pa];
				pa++;
			}else{
				cnt++;
				c[cnt] = b[pb];
				C[cnt] = B[pb];
				pb++;
			}
		}
		while(pa <= n){
			cnt++;
			c[cnt] = a[pa];
			C[cnt] = A[pa];
			pa++;
		}
		while(pb <= m){
			cnt++;
			c[cnt] = b[pb];
			C[cnt] = B[pb];
			pb++;
		}
		
		printf("%d\n", cnt);
		for(int j=1;j<=cnt;j++){
			printf("%d ", c[j]);
		}
		printf("\n");
		for(int j=1;j<=cnt;j++){
			printf("%d ", C[j]);
		}
		printf("\n");
	}
} 
