#include<stdio.h>
char f[5005][2000];
int len[5005];

int add(char *a,int lena,char *b,int lenb,char *c){
	for(int i=0;i<lena||i<lenb;i++){
		c[i]+=a[i]+b[i];
		c[i+1] = c[i]/10;
		c[i]%=10;
	}
	lena=lena>lenb?lena:lenb;
	if(c[lena]>0)
		lena++;
	return lena;
}

int main(){
	int n;
	f[0][0]=0; len[0]=1;
	f[1][0]=1; len[1]=1;
	f[2][0]=2; len[2]=1;
	scanf("%d",&n);
	for(int i=3;i<=n;i++){
		len[i]= add(f[i-1],len[i-1],f[i-2],len[i-2],f[i]);
	}
	for(int i=len[n]-1;i>=0;i--){
		printf("%d",f[n][i]);
	}
	return 0;
}
