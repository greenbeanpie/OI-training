#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=100005;
struct obj
{
	int l,r,z;
	bool operator < (const obj &o) const {return z<o.z;}
}ti[N];
bool v[N];
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C=read(),T=read();
	while(T--)
	{
		int n=read(),m=read(),k=read(),d=read();
		for(int i=1;i<=m;i++)
		{
			ti[i].l=read(),ti[i].r=read(),ti[i].z=read();
			if(ti[i].r-ti[i].l+1>k) i--,m--;
		}
		sort(ti+1,ti+m+1);
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int kkk=ti[i].z-(ti[i].r-ti[i].l+1)*d;
			if(kkk>0) ans+=kkk;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
