#include<algorithm>
#include<cstdio>
#include<cstring>
const int N = 100010;
int c,T,M,n,m,k,d,j,x[N],y[N],t[N*3],head[N*3],next[N],l;
long long v[N],max[N*12],tag[N*12],dp[N*3];
void push_down(int rt)
{
	max[rt<<1] += tag[rt],max[rt<<1|1] += tag[rt];
	tag[rt<<1] += tag[rt],tag[rt<<1|1] += tag[rt];
	tag[rt] = 0;
}
long long querymax(int rt,int l,int r,int ql,int qr)
{
	if (l > qr || r < ql)
		return 0;
	if (ql <= l && qr >= r)
		return max[rt];
	int mid = (l+r)>>1;
	push_down(rt);
	return std::max(querymax(rt<<1,l,mid,ql,qr),querymax(rt<<1|1,mid+1,r,ql,qr));
}
void add(int rt,int l,int r,int ql,int qr,long long val)
{
	if (l > qr || r < ql)
		return;
	if (ql <= l && qr >= r)
	{
		max[rt] += val,tag[rt] += val;
		return;
	}
	int mid = (l+r)>>1;
	push_down(rt);
	add(rt<<1,l,mid,ql,qr,val);
	add(rt<<1|1,mid+1,r,ql,qr,val);
	max[rt] = std::max(max[rt<<1],max[rt<<1|1]);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while (T--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for (int i = 1;i <= m;++i)
		{
			scanf("%d%d%lld",&x[i],&y[i],&v[i]),j = 3*i-1;
			t[j] = x[i]-y[i]+1,t[j+1] = x[i],t[j+2] = x[i]+1;
		}
		
		std::sort(t+1,t+m*3+2),M = std::unique(t+1,t+m*3+2)-t-1;
		memset(head,0,sizeof(int)*(M+10));
		memset(max,0,sizeof(long long)*(M*4));
		memset(tag,0,sizeof(long long)*(M*4));
		for (int i = 1;i <= m;++i)
			y[i] = x[i]-y[i]+1,
			x[i] = std::lower_bound(t+1,t+M+1,x[i])-t,
			y[i] = std::lower_bound(t+1,t+M+1,y[i])-t,
			next[i] = head[x[i]],head[x[i]] = i;
		
		dp[l = 1] = 0,add(1,1,M,1,1,d*t[2]);
		dp[2] = 0,add(1,1,M,2,2,d*t[3]);
		for (int i = 3;i <= M;++i)
		{
			
			for (int p = head[i-1];p;p = next[p])
				add(1,1,M,1,y[p]-1,v[p]);
			while (t[i-1]-t[l+1] >= k)
				++l;
			dp[i] = std::max(dp[i-1],querymax(1,1,M,l,i-2)-d*(t[i-1]+1));
			add(1,1,M,i,i,dp[i]+d*t[i+1]);
		}
		printf("%lld\n",dp[M]);
	}
	return 0;
}