#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
void read(T &x)
{
	x=0;
	bool sgn=0;
	char c=getchar();
	while(!isdigit(c))
		sgn|=c=='-',c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x=sgn?-x:x;
}
int c,t, n,m, x,y, ans;
const int maxn=1e5+5;
bitset<maxn>bs;
char ch;
void init()
{
	bs&=0;
	ans=0;
	return;
}
int main()
{
//	freopen("E:\\down\\tribool\\tribool3.in","r",stdin);
//	freopen("E:\\down\\tribool\\tribool3.out","w",stdout);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	read(c),read(t);
	while(t--)
	{
		init();
		read(n),read(m);
		//if(c==3||c==4)
		{//TFU 20pts..?
			for(int i=1;i<=m;++i)
			{
				cin>>ch;
				read(x);
				if(ch=='U')
				{
					if(bs[x]==0)
					{
						bs[x]=1;
						++ans;
					}
				}
			}
			printf("%d\n",ans);
		}
		//if(c==5||c==6)
		if(0)//0pt nolonger used.
		{
			for(int i=1;i<=m;++i)
			{
				cin>>ch;
				if(ch=='U')
				{
					read(x);
					if(bs[x]==0)
						bs[x]=1,++ans;
				}
				if(ch=='+')
				{
					read(x),read(y);
					int tmp=bs[x]+bs[y];
					bs[x]=bs[y];
					ans+=bs[x]+bs[y]-tmp;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

