#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int a[101][101];
	memset(a,0x7f,sizeof(a));  //��ʼ���
	//tips��Ҳ����0x3f ��0x7fffffff
	cout<<a[1][1]<<endl;  
	memset(a,0,sizeof(a));  //��ʼ��Ϊ0 
	cout<<a[1][1]<<endl;
	memset(a,0xaf,sizeof(a));  //��ʼ��С��
	cout<<a[1][1]<<endl;
   
   cout<<endl;
   
   long long b[101][101];
   memset(b,127,sizeof(b));  //��ʼ���
   cout<<b[1][1]<<endl;
   memset(b,0,sizeof(b)); //��ʼ��Ϊ0  
   cout<<b[1][1]<<endl;
   
	return 0;
}
