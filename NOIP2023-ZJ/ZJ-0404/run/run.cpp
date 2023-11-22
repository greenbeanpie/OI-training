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
int c,t,n,m,k,d;ll ans;
const int maxm=1e5+5;
struct Task{
	int x,y,z;
	int l,r;
}task[maxm];
void init()
{
	ans=0;
	return;
}
vector<int>num;

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	read(c),read(t);
	while(t--)
	{
		init();
		read(n),read(m),read(k),read(d);
		for(int i=1,x,y,z;i<=m;++i)
		{
			read(task[i].x),read(task[i].y),read(task[i].z);
			task[i].l=task[i].x-task[i].y+1;
			task[i].r=task[i].x;
		}
		if(c==17||c==18)//8pts
		{
			for(int i=1;i<=m;++i)
			{
				if(task[i].y<=k)
					ans+=max(0,task[i].z-d*task[i].y);
			}
			printf("%lld\n",ans);
		}
		else//0pt miracle bazooooooooooka!
		{
			num.resize(n+1);
			ans=0;
			for(int i=1;i<=m;++i)
				num[task[i].l]-=d,
				num[task[i].r+1]+=d,
				ans+=task[i].z;
			for(int i=1;i<=n;++i)
				num[i]+=num[i-1],
				ans+=num[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
//good luck to myself.thx ccf.
