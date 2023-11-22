#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=200010;

struct node
{
	int l,r;
	long long add,mx;
	void plus(long long x)
	{
		add+=x;
		mx+=x;
	}
}t[maxn*2];

int cnt,l[maxn],r[maxn],v[maxn],rw[maxn];
vector<pair<int,int>>chl[maxn];

void vBuild(node &rt,int l,int r)
{
	rt.add=0;
	rt.mx=-1e18;
	if(l==r) return;
	int mid=(l+r)/2;
	vBuild(t[rt.l=++cnt],l,mid);
	vBuild(t[rt.r=++cnt],mid+1,r);
}

void vPushDown(node &rt)
{
	if(rt.add)
	{
		t[rt.l].plus(rt.add);
		t[rt.r].plus(rt.add);
		rt.add=0;
	}
}

void vAdd(node &rt,int l,int r,int R,int v)
{
	if(r==R)
	{
		rt.plus(v);
		return;
	}
	vPushDown(rt);
	int mid=(l+r)/2;
	if(R<=mid) vAdd(t[rt.l],l,mid,R,v);
	else t[rt.l].plus(v),vAdd(t[rt.r],mid+1,r,R,v);
	rt.mx=max(t[rt.l].mx,t[rt.r].mx);
}

long long nQuery(node &rt,int l,int r,int L)
{
	if(l==L) return rt.mx;
	vPushDown(rt);
	int mid=(l+r)/2;
	if(L>mid) return nQuery(t[rt.r],mid+1,r,L);
	else return max(t[rt.r].mx,nQuery(t[rt.l],l,mid,L));
}

void vInit(node &rt,int l,int r,int i,long long v)
{
	if(l==r)
	{
		rt.mx=v;
		return;
	}
	vPushDown(rt);
	int mid=(l+r)/2;
	if(i<=mid) vInit(t[rt.l],l,mid,i,v);
	else vInit(t[rt.r],mid+1,r,i,v);
	rt.mx=max(t[rt.l].mx,t[rt.r].mx);
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		int n,m,k,d,cur=0,i;
		cin>>n>>m>>k>>d;
		n=0;
		while(m--)
		{
			cur++;
			cin>>r[cur]>>l[cur]>>v[cur];
			if(l[cur]>k) cur--;
			else
			{
				l[cur]=r[cur]-l[cur]+1;
				rw[++n]=l[cur];
				rw[++n]=r[cur];
			}
		}
		if(!n)
		{
			cout<<0<<'\n';
			continue;
		}
		sort(rw+1,rw+n+1);
		n=unique(rw+1,rw+n+1)-rw-1;
		for(i=1;i<=n;i++) chl[i].clear();
		for(i=1;i<=cur;i++)
		{
			l[i]=lower_bound(rw+1,rw+n+1,l[i])-rw;
			r[i]=lower_bound(rw+1,rw+n+1,r[i])-rw;
			chl[r[i]].emplace_back(l[i],v[i]);
		}
		long long ans=0,lst=0;
		cnt=1;
		vBuild(t[1],1,n);
		for(i=cur=1;i<=n;i++)
		{
			if(rw[i]!=rw[i-1]+1) ans=max(ans,lst);
			vInit(t[1],1,n,i,ans+1LL*rw[i]*d);
			for(auto it:chl[i]) vAdd(t[1],1,n,it.first,it.second);
			while(rw[i]-rw[cur]>=k) cur++;
			ans=max(ans,lst);
			lst=nQuery(t[1],1,n,cur)-(rw[i]+1LL)*d;
		}
		cout<<max(ans,lst)<<'\n';
	}
	return 0;
}
