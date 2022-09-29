#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t,n,a[N],l[N],r[N],top;
__int128 ans; 
struct node{
	int id,val;
}st[N];
int read(){
	int s=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+c-'0',c=getchar();
	return s;
}
void print(__int128 x){
	if(x<10){
		printf("%d",(int)x);
		return;
	}
	print(x/10);
	printf("%d",(int)(x%10));
}
int main(){
	//freopen("rand.in","r",stdin);
    //freopen("a.out","w",stdout);
	t=read();
	while(t--){
		n=read();ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			while(top&&a[i]>=st[top].val) r[st[top--].id]=i-1;
			if(top) l[i]=st[top].id+1;
			else l[i]=1;
			st[++top].id=i;st[top].val=a[i];
		}
		while(top) r[st[top--].id]=n;
		for(int i=1;i<=n;i++) ans+=(__int128)(r[i]-i+1)*(i-l[i]+1)*a[i];
		for(int i=1;i<=n;i++){
			while(top&&a[i]<st[top].val) r[st[top--].id]=i-1;
			if(top) l[i]=st[top].id+1;
			else l[i]=1;
			st[++top].id=i;st[top].val=a[i];
		}
		while(top) r[st[top--].id]=n;
		for(int i=1;i<=n;i++) ans-=(__int128)(r[i]-i+1)*(i-l[i]+1)*a[i];
		print(ans);puts("");
	}
	return 0;
}
