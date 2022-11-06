#include<stdio.h>

int read(){
	int n=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		n=n*10+c-'0';
		c=getchar();
	}
	return n;
}

int main(){
	int n,aa=0,bb=0,cc=0,sco;
	double sum[4]={0};
	int max[4]={0},min[4]={0},f[4]={0};
	char cla;
	n=read();
	for(int i=0;i<n;i++){
		cla=getchar();
		sco=read();
		if(cla=='A'){
			if(f[1]==0){
				max[1]=sco;
				min[1]=sco;
				f[1]=1;
			}
			sum[1]+=sco;
			if(sco>max[1])
				max[1]=sco;
			if(sco<min[1])
				min[1]=sco;
			aa++;
		}else if(cla=='B'){
			if(f[2]==0){
				max[2]=sco;
				min[2]=sco;
				f[2]=1;
			}
			sum[2]+=sco;
			if(sco>max[2])
				max[2]=sco;
			if(sco<min[2])
				min[2]=sco;
			bb++;
		}else if(cla=='C'){
			if(f[3]==0){
				max[3]=sco;
				min[3]=sco;
				f[3]=1;
			}
			sum[3]+=sco;
			if(sco>max[3])
				max[3]=sco;
			if(sco<min[3])
				min[3]=sco;
			cc++;
		}
	}
	sum[1]/=aa;
	sum[2]/=bb;
	sum[3]/=cc;
	if(sum[1]>=sum[2]&&sum[1]>=sum[3])
		printf("A\n");
	else if(sum[2]>=sum[1]&&sum[2]>=sum[3])
		printf("B\n");
	else printf("C\n");
	printf("%d %d\n%d %d\n%d %d\n",max[1],min[1],max[2],min[2],max[3],min[3]);
	return 0;
}
