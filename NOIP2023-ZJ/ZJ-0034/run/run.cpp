//freopen
/*
Nobody can hear
I'm barely breathing
All of my dreamings
no longer be in my story
Nobody can see
Where now i am standing
All the way you lead
try everying but fading
Between me and me
If it wasn't reality
It won't becomes new memory

You used to be
You used to be
How could you leave

You used to be
You used to be
How could you leave
How could you leave

Now I can see
You used to be me
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,t,k,d;
int mx[400010],tag[400010];
struct event
{
	int l,r,val;
};
void build(int x,int l,int r)
{
	tag[x]=0;
	if(l==r)
	{
		mx[x]=l==0?0:-1e18;
		return ;
	}
	int mid=(l+r)/2;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
void pushdown(int x)
{
	if(tag[x])
	{
		mx[x<<1]+=tag[x];
		mx[x<<1|1]+=tag[x];
		tag[x<<1]+=tag[x];
		tag[x<<1|1]+=tag[x];
		tag[x]=0;
	}
}
void setval(int x,int l,int r,int p,int v)
{
	if(l==r)
	{
		mx[x]=v;
		return ;
	}
	int mid=(l+r)/2;
	pushdown(x);
	if(p<=mid)
		setval(x<<1,l,mid,p,v);
	else
		setval(x<<1|1,mid+1,r,p,v);
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
void update(int x,int l,int r,int ll,int rr,int v)
{
	if(r<ll||rr<l||ll>rr)
		return ;
	if(ll<=l&&r<=rr)
	{
		mx[x]+=v;
		tag[x]+=v;
		return ;
	}
	pushdown(x);
	int mid=(l+r)/2;
	update(x<<1,l,mid,ll,rr,v);
	update(x<<1|1,mid+1,r,ll,rr,v);
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
int query(int x,int l,int r,int ll,int rr)
{
	if(r<ll||rr<l||ll>rr)
		return -1e18;
	if(ll<=l&&r<=rr)
		return mx[x];
	pushdown(x);
	int mid=(l+r)/2;
	return max(query(x<<1,l,mid,ll,rr),query(x<<1|1,mid+1,r,ll,rr));
}
event a[400010];
int p[400010],cnt=0,tot=0;
bool cmp(event x,event y)
{
	if(x.r!=y.r)
		return x.r<y.r;
	return x.val<y.val;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		cnt=tot=0;
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		{
			int x,y,val;
			scanf("%lld%lld%lld",&x,&y,&val);
			int l=x-y+1,r=x;
			a[++tot]=(event){l,r,val};
			p[++cnt]=l;
		}
		sort(p+1,p+cnt+1);cnt=unique(p+1,p+cnt+1)-p-1;
		build(1,0,cnt);
		for(int i=1;i<=cnt;i++)
			a[++tot]=(event){p[i],p[i],0};
		sort(a+1,a+tot+1,cmp);
		queue<event> q;
		for(int i=1;i<=tot;i++)
		{
			while(q.size())
			{
				if(a[i].val==0&&q.front().r<a[i].l-1)
				{
					event x=q.front();q.pop();
					setval(1,0,cnt,0,max(query(1,0,cnt,0,0),x.val));
				}	
				else
					break;
			}
			if(a[i].val==0)
			{
				int pp=lower_bound(p+1,p+cnt+1,a[i].l)-p;
				setval(1,0,cnt,pp,(a[i].l-1)*d+query(1,0,cnt,0,0));
			}
			else
			{
				int pp=lower_bound(p+1,p+cnt+1,a[i].l)-p;
				int ppp=lower_bound(p+1,p+cnt+1,a[i].r-k+1)-p;
				update(1,0,cnt,1,pp,a[i].val);
				q.push((event){a[i].l,a[i].r,query(1,0,cnt,ppp,pp)-a[i].r*d});
			}	
		}
		while(q.size())
		{
			event x=q.front();q.pop();
			setval(1,0,cnt,0,max(query(1,0,cnt,0,0),x.val));
		}
		printf("%lld\n",query(1,0,cnt,0,0));
	}
}
