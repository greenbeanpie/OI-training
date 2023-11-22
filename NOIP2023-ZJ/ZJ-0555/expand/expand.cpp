#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,x,y) for(int i=x;i<=y;i++)
#define FOR(i,x,y) for(int i=x;i>=y;i--)
#define elif else if
//#define int long long

const int N=5e5+4;
int c,n,m,q,a[N],b[N];
namespace Subtask1
{
	const int N1=1e3+4,INF=2e9;
	int aa[N1],bb[N1],Minal,Minanl,Minar,Minanr,Minbl,Minbnl,Minbr,Minbnr,Maxa,Maxan,Maxb,Maxnb;
	int bgsl(int x,int y){if(x>y)return 1;elif(x<y)return -1;else return 0;}
	inline bool check(int la,int ra,int lb,int rb,int x)
	{
		if(bgsl(a[la],b[lb])+bgsl(a[ra],b[rb])==0)return 0;
		if(la==ra){For(i,lb,rb)if(bgsl(a[1],b[1])+bgsl(a[la],b[i])==0)return 0;return 1;}
		if(lb==rb){For(i,la,ra)if(bgsl(a[1],b[1])+bgsl(a[i],b[lb])==0)return 0;return 1;}
		if(x>=log2(min(n,m))-1)return 1;
		int Maxa=0,Maxan=0;
		For(i,la,ra)if(a[i]>Maxa)Maxa=a[i],Maxan=i;
		int Maxb=0,Maxbn=0;
		For(i,lb,rb)if(b[i]>Maxb)Maxb=b[i],Maxbn=i;
		if(bgsl(a[1],b[1])+bgsl(Maxa,Maxb)==0)return 0;
		int Minal=INF,Minaln=0;
		For(i,la,Maxan-1)if(a[i]<Minal)Minal=a[i],Minaln=i;
		int Minar=INF,Minarn=0;
		For(i,Maxan+1,ra)if(a[i]<Minar)Minar=a[i],Minarn=i;
		int Minbl=INF,Minbln=0;
		For(i,lb,Maxbn-1)if(b[i]<Minbl)Minbl=b[i],Minbln=i;
		int Minbr=INF,Minbrn=0;
		For(i,Maxbn+1,rb)if(b[i]<Minbr)Minbr=b[i],Minbrn=i;
		if(bgsl(a[1],b[1])+bgsl(Minal,Minbl)==0)return 0;
		if(bgsl(a[1],b[1])+bgsl(Minar,Minbr)==0)return 0;
		return check(la,Minaln-1,lb,Minbln-1,x+1) && check(Minarn+1,ra,Minbrn+1,rb,x+1);
	}
	void solve()
	{
		For(i,1,n)aa[i]=a[i];
		For(i,1,m)bb[i]=b[i];
		cout<<check(1,n,1,m,1);
		while(q--)
		{
			int k1,k2;cin>>k1>>k2;
			For(i,1,n)a[i]=aa[i];
			For(i,1,m)b[i]=bb[i];
			For(i,1,k1)
			{
				int p,v;cin>>p>>v;
				a[p]=v;
			}
			For(i,1,k2)
			{
				int p,v;cin>>p>>v;
				b[p]=v;
			}
			cout<<check(1,n,1,m,1);
		}
	}
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	IOS;
	cin>>c>>n>>m>>q;
	For(i,1,n)cin>>a[i];
	For(i,1,m)cin>>b[i];
	Subtask1::solve();

	return 0;
}
