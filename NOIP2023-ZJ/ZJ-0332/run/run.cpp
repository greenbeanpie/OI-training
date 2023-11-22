//10:00 shang ge ce suo
#include<bits/stdc++.h>
using namespace std;

int c,t;

int rd()
{
	int f=1,k=0;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}

namespace baoli
{
	const int M=1e5+10;
	
	int n,m,k,d;
	struct rec
	{
		int l,r,len,v;
	}tz[M];
	
	bool cmp(rec a,rec b)
	{
		if(a.l==b.l) return a.r<b.r;
		return a.l<b.l;
	}
	
	void solve()
	{
		n=rd(),m=rd(),k=rd(),d=rd();
		for(int i=1;i<=m;i++)
		{
			tz[i].r=rd();
			tz[i].len=rd();
			tz[i].v=rd();
			tz[i].l=tz[i].r-tz[i].len+1;
			if(tz[i].len<k) i--,m--;
		}
		sort(tz+1,tz+m+1,cmp);
		int ans=0;
//		for(int i=1;i<=m;i++)
//		{
//			cout<<tz[i].l<<" "<<tz[i].r<<endl;
//		}
		for(int i=1;i<=m;i++)
		{
			int now=tz[i].v-tz[i].len*d;
			int f=0,ff=0;f=max(f,now);
			//cout<<now<<"\n";
			if(now>0)
			{
				int st=tz[i].l;
				int ed=tz[i].r;
				for(i++;i<=m;i++)
				{
					if(tz[i].l>ed) break;
					if(tz[i].r-st+1<=k)
					{
						int nn=tz[i].v-(tz[i].r-ed+1)*d;
						ed=tz[i].r;
						now+=nn;
						f=max(f,now);
					}
					else
					{
						int nn=tz[i].v-tz[i].len*d;
						//cout<<nn<<"\n";
						if(now<0)
						{
							now=nn;
							f=nn;
							st=tz[i].l;
							ff=max(ff,f);
						}
					}
				}
			}
			ans+=f;
		}
		cout<<ans<<"\n";
	}
	
	void work()
	{
		c=rd(),t=rd();
		while(t--)
		{
			solve();
		}
	}
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	baoli::work();
	return 0;
}