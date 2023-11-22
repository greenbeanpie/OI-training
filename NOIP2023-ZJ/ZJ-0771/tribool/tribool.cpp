#include<bits/stdc++.h>
#define ll long long
#define rr register
#define N 500004
using namespace std;

inline int read()
{
	int num=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') num=(num<<1)+(num<<3)+(ch^48),ch=getchar();
	return num;
}
int n,m,c;
struct node
{
	int zj;
	int val;
	int fh;
	int pt;
}dade[N];
char emm;
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int T;
	scanf("%d%d",&c,&T);
	
	while(T--)
	{
		n=read(),m=read();
		//cout<<n<<m<<endl;
		for(rr int i=1;i<=n;i++)
		{
			dade[i].val=dade[i].zj=dade[i].fh=dade[i].pt=0;
			dade[i].zj=1,dade[i].pt=i;
		}
		for(rr int i=1;i<=m;i++)
		{
			rr int x=0,y=0;
			emm=getchar();x=read();
			if(emm=='+'||emm=='-') y=read();
			//printf("%c %d %d\n",emm,x,y);
			if(emm=='+')
			{
				if(dade[y].pt);
			}
		}
		
	}
	
	
	return 0;
}
