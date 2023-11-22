#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f * x;
}

int main()
{
	int t = 0;
	while(true)
	{
		printf("test #%d:",++t);
		system("make.exe > data.in");
		system("code.exe < data.in > data.out");
		system("std.exe < data.in > data.ans");
		if(system("fc data.ans data.out > data.log"))
		{
			puts("WA");return 0 ;
		}
		else	puts("AC");
	}


	return 0  ;
}

