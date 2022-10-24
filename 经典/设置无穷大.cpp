#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int a[101][101];
	memset(a,0x7f,sizeof(a));  //初始最大化
	//tips：也常用0x3f 或0x7fffffff
	cout<<a[1][1]<<endl;  
	memset(a,0,sizeof(a));  //初始化为0 
	cout<<a[1][1]<<endl;
	memset(a,0xaf,sizeof(a));  //初始最小化
	cout<<a[1][1]<<endl;
   
   cout<<endl;
   
   long long b[101][101];
   memset(b,127,sizeof(b));  //初始最大化
   cout<<b[1][1]<<endl;
   memset(b,0,sizeof(b)); //初始化为0  
   cout<<b[1][1]<<endl;
   
	return 0;
}
