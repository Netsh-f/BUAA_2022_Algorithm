#include<cstdio>
#include<queue>
using namespace std;
#define MAXN 10005

int main(){
	long long n, t, ans = 0;
	priority_queue<long long, vector<long long>, greater<>> q;
	scanf("%lld", &n);
	for(int i=1;i<=n;i++){
		scanf("%lld", &t);
		q.push(t);
	}
	for(int i=1;i<=n-1;i++){
		t = q.top();
		q.pop();
		t += q.top();
		q.pop();
		q.push(t);
		ans += t;
	}
	printf("%lld\n", 2*ans);
	return 0;
}
