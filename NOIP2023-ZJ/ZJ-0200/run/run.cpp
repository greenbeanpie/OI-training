#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,cnt;
long long d;
long long ans;

struct Ch{
	int l,r;
	long long v;
}a[100005],b[100005];

bool bl[100005];

int bb[20];

bool cmp(Ch x,Ch y)
{
	if(x.l!=y.l)
		return x.l<y.l;
	if(x.r!=y.r)
		return x.r>y.r;
	return x.v<y.v;
}

long long dfs(int now,int en,long long s,int l)
{
	if(now>en)
		return s;
	long long t=0;
	if((l+b[now].r-b[now].l+1)<=k)
		t=max(t,dfs(now+1,en,s+b[now].v,l+b[now].r-b[now].l+1));
	t=max(t,dfs(now+1,en,s,0));
	return t;
}

void ch(int l,int r)
{
	if((b[r].r-b[l].l+1)<=k)
	{
		for(int i=l;i<=r;i++)
			ans+=b[i].v;
		return;
	}
	ans+=dfs(l,r,0,0);
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin>>c>>t;
	while(t--)
	{
		cnt=0;
		ans=0;
		memset(bl,false,sizeof(bl));
		cin>>n>>m>>k>>d;
		for(int i=1,x,y;i<=m;i++)
		{
			cin>>x>>y;
			if(y<=k)
			{
				a[++cnt].l=x-y+1;
				a[cnt].r=x;
				cin>>a[cnt].v;
			}
			else
				cin>>x;
		}
		m=cnt;
		sort(a+1,a+m+1,cmp);
		cnt=1;
		b[1]=a[1];
		for(int i=2;i<=m;i++)
			if((b[cnt].l==a[i].l)&&(b[cnt].r==a[i].r))
				b[cnt].v+=a[i].v;
			else
				b[++cnt]=a[i];
		m=cnt;
		if(c<=2)
		{
			for(int i=0,i_max=(1<<n)-1;i<=i_max;i++)
			{
				long long s=0;
				for(int j=1;j<=n;j++)
					bb[j]=((i>>(j-1))&1);
				bool fl=true;
				for(int j=1,j_max=n-k;fl&&(j<=j_max);j++)
				{
					int t=0;
					for(int i=0;i<=k;i++)
						t+=bb[j+i];
					if(t>k)
						fl=false;
				}
				if(!fl)
					continue;
				for(int i=1;i<=m;i++)
				{
					int t=0;
					for(int j=b[i].l;j<=b[i].r;j++)
						t+=bb[j];
					if(t==(b[i].r-b[i].l+1))
						s+=b[i].v;
				}
				for(int i=1;i<=n;i++)
					s-=bb[i]*d;
				ans=max(ans,s);
			}
		}
		if((c==17)||(c==18))
		{
			for(int i=1;i<=m;i++)
			{
				b[i].v-=d*(b[i].r-b[i].l+1);
				if(b[i].v>0)
					bl[i]=true;
			}
			for(int i=1;i<=m;i++)
				if(bl[i])
				{
					int l=i,r=i;
					while(bl[r+1]&&(b[r+1].l==(b[r].r+1)))
						r++;
					ch(l,r);
					i=r;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}