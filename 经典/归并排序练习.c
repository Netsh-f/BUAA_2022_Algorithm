#include<stdio.h>
#define N 100005
int a[N],b[N];

void mergeSort(int l,int r){
	if(l==r)
		return;
	int mid=(l+r)>>1;
	mergeSort(l,mid); mergeSort(mid+1,r);
	int L=l,R=mid+1,p=L;
	while(L<=mid&&R<=r){
		if(a[L]<a[R])
			b[p++]=a[L++];
		else
			b[p++]=a[R++];
	}
	while(L<=mid)
		b[p++]=a[L++];
	while(R<=r)
		b[p++]=a[R++];
	for(int i=l;i<=r;i++)
		a[i]=b[i];
}
 
int main(){
	for(int i=1;i<=10;i++)
		scanf("%d",a+i);
	mergeSort(1,10);
	for(int i=1;i<=10;i++)
		printf("%d ",a[i]);
	return 0;
}
