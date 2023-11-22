#include<bits/stdc++.h>
#define MAXN 100010
#define int long long
using namespace std;
int read()
{
	int f=1,s=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c-'0');c=getchar();}
	return s*f;
}
int n,m,k,d;
int qian[MAXN];
struct node
{
	int s,e,val,len;
}tiao[MAXN];
bool cmp(node x,node y)
{
	
	int sum1=x.val-x.len*d;
	int sum2=y.val-y.len*d;
	if(sum1/x.len!=sum2/y.len)return sum1/x.len>sum2/y.len;
	else if(sum1!=sum2)return sum1>sum2;
	else if(x.len!=y.len) return x.len<y.len;
	else return x.s<y.s;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int l,t;cin>>l>>t;
	for(int pos=1;pos<=t;pos++)
	{
		n=read();m=read();k=read();d=read();
		for(int i=0;i<=n+2;i++)qian[i]=0;
		int x,y,v;
		int cnt=0;
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			v=read();
			if(y-x+1<=k)
			{
				tiao[++cnt].s=x-y+1;
				tiao[cnt].e=x;
				tiao[cnt].val=v;
				tiao[cnt].len=y;
			}
		}
		sort(tiao+1,tiao+1+cnt,cmp);
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			if(qian[tiao[i].s-1]+tiao[i].len<=k)
			{
			//	cout<<tiao[i].s<<endl;
				ans+=tiao[i].val;
				for(int j=1;j<=tiao[i].len;j++)
				{
					int p=tiao[i].s-1+j;
					if(!qian[p])ans-=d;
					qian[p]=qian[p-1]+1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
3 2 2 1
2 2 4
3 2 3
*/
