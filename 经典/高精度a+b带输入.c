#include<stdio.h>
#include<string.h>
char a[510],b[510],c[510];

void str(char a[],int len){
	int sta=0,end=len-1;
	char t;
	while(sta<end){
		t=a[sta];
		a[sta]=a[end];
		a[end]=t;
		sta++;
		end--;
	}
	return;
}

int main(){
	int lena,lenb;
	scanf("%s",a);
	scanf("%s",b);
	lena=strlen(a);
	lenb=strlen(b);
	str(a,lena);
	str(b,lenb);
	for(int i=0;i<lena;i++){
		a[i]= a[i]-'0';
	}
	for(int i=0;i<lenb;i++){
		b[i]= b[i]-'0';
	}
	for(int i=0;i<lena||i<lenb;i++){
		c[i]+=a[i]+b[i];
		c[i+1] = c[i]/10;
		c[i]%=10;
	}
	lena=lena>lenb?lena:lenb;
	if(c[lena]>0)
		lena++;
	for(int i=lena-1;i>=0;i--){
		printf("%c",c[i]+'0');
	}
	return 0;
}
