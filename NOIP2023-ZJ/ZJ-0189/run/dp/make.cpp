#include<bits/stdc++.h>
using namespace std;
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f * x;
}

int main()
{
	int T = 10;
	printf("%d\n",T);
	while(T--)
	{
		int n = gen() % 50 + 1,m = gen() % 10 + 1,k = gen() % n + 1,d = gen() % 10 + 1;
		printf("%d %d %d %d\n",n,m,k,d);
		for(int i = 1;i <= m;i++)
		{
			int l = gen() % n + 1,r = gen() % n + 1;
			if(l > r)	swap(l,r);
			printf("%d %d %d\n",r,r - l + 1,gen() % 50 + 1);
		}
	}
	return 0  ;
}

