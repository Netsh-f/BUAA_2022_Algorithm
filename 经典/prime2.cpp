#include<cstring>
#include<cstdio>
bool isPrime[100000010];
int Prime[6000010],cnt=0;
void getPrime(int n){
	isPrime[1]=1;//0是质数，1不是质数 
	for(int i=2;i<=n;i++){
		if(!isPrime[i])
			Prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*Prime[j]<=n;j++){
			isPrime[i*Prime[j]]=1;
			if(i%Prime[j]==0)
				break;
		}
	}
}
int main(){
	int n=10000;
	getPrime(n);
	for(int i=1;i<=100;i++){
		printf("%d\n",Prime[i]);
	}
	return 0;
}
