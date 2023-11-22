#include<bits/stdc++.h>
using namespace std;
const long long Inf=1e18;
int C,T;
int n,m;
long long k,d;
//struct acti{long long l,r,v;};
//bool operator < (acti x,acti y){return x.r<y.r;}
//vector<acti> a;
//struct node{long long minl,maxv;};
//node operator + (node p,node q){return (node){min(p.minl,q.minl),max(p.maxv,q.maxv)};}
//struct SGT
//{
//	int rn;
//	node tr[262144];
//	int occupy(int x){int y=1;for(x--;x;x>>=1)y<<=1;return y;}
//	void init()
//	{
//		rn=occupy(n);
//		fill(tr,tr+2*rn+2,(node){Inf,-Inf});
//	}
//	void delold(int l,int r,int le,int rt)
//	{
//		if(tr[rt].minl>le)return;
//		if(l==r)
//		{
//			tr[rt].minl=Inf;
//			tr[rt].maxv=-Inf;
//			return;
//		}
//		int mid=(l+r)/2;
//		delold(l,mid,le,rt*2);
//		delold(mid+1,r,le,rt*2+1);
//		tr[rt]=tr[rt*2]+tr[rt*2+1];
//	}
//	void modiv(int x,node up,int rt,int l,int r)
//	{
//		//printf("modiv %d, (%lld,%lld), rt=%d [%d,%d]\n",x,up.minl,up.maxv,rt,l,r);
//		if(l==r)
//		{
//			tr[rt]=up;
//			return;
//		}
//		int mid=(l+r)/2;
//		if(x<=mid)modiv(x,up,rt*2,l,mid);
//		else modiv(x,up,rt*2+1,mid+1,r);
//		tr[rt]=tr[rt*2]+tr[rt*2+1];
//	}
//	long long rgmaxv(int x,int y,int rt,int l,int r)
//	{
//		if(x==l && y==r)return tr[rt].maxv;
//		int mid=(l+r)/2;long long res=-Inf;
//		if(x<=mid)
//			res=rgmaxv(x,min(y,mid),rt*2,l,mid);
//		if(y>mid)
//			res=max(res,rgmaxv(max(x,mid+1),y,rt*2+1,mid+1,r));
//		return res;
//	}
//};
//int miann()
//{
//	freopen("run.in","r",stdin);
//	freopen("run.out","w",stdout);
//	for(scanf("%d%d",&C,&T);T;T--)
//	{
//		scanf("%d%d%lld%lld",&n,&m,&k,&d);
//		fs.init();
//		a={(acti){0,0,0},(acti){Inf,Inf,0}};
//		for(int i=1;i<=m;i++)
//		{
//			long long x,y,v;
//			scanf("%lld%lld%lld",&x,&y,&v);
//			if(y<=k)
//				a.emplace_back((acti){x-y+1,x,v});
//		}
//		sort(a.begin(),a.end());
//		vector<
//		for(acti ac:a)
//		{
//			//benefits to l-s
//			
//			//delete the olds
//			fs.delold(1,n,ac.r-k,1);
//			
//			//calc the f
//			
//	}
//	return 0;
//}
//}
//int mian()
//{
//	cin>>n;
//	fs.init();
//	while(true)
//	{
//		string s;
//		int l,r,t;
//		cin>>s;
//		if(s=="d")
//		{
//			cin>>l;
//			fs.delold(1,fs.rn,l,1);
//		}
//		if(s=="m")
//		{
//			cin>>l>>t>>r;
//			fs.modiv(l,(node){t,r},1,1,fs.rn);
//		}
//		if(s=="q")
//		{
//			cin>>l>>r;
//			cout<<fs.rgmaxv(l,r,1,1,fs.rn)<<endl;
//		}
//		cout<<fs.rgmaxv(1,n,1,1,fs.rn)<<endl;
//	}
//}
long long f[1005][1005],b[1005][1005];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	for(scanf("%d%d",&C,&T);T;T--)
	{
		scanf("%d%d%lld%lld",&n,&m,&k,&d);
		memset(f,0,sizeof f);
		memset(b,0,sizeof b);
		for(int i=1;i<=m;i++)
		{
			long long x,y,v;
			scanf("%lld%lld%lld",&x,&y,&v);
			b[x][y]+=v;
		}
		for(int i=1;i<=n+1;i++)
		{
			f[i][0]=f[i-1][0];
			for(int j=1;j<=k;j++)
				f[i][0]=max(f[i][0],f[i-1][j]);
			long long bonus=0;
			for(int j=1;j<=k;j++)
			{
				bonus+=b[i][j];
				f[i][j]=f[i-1][j-1]-d+bonus;
			}
		}
		printf("%lld\n",f[n+1][0]);
	}
	return 0;
}