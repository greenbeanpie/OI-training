#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5,INF = 0x3f3f3f3f;
typedef long long ll;
int n,m,k,d;
int pos[N],L[N],R[N],v[N];
ll f[N];
#define lc c<<1
#define rc c<<1|1
#define mid (l+r>>1)
ll tr[N<<2],lzy[N<<2];
void upd(int c,ll x){tr[c] += x,lzy[c] += x;}
void pd(int c){upd(lc,lzy[c]),upd(rc,lzy[c]),lzy[c] = 0;}
void Upd(int c,int l,int r,int ql,int qr,ll x)
{
	if(l == ql && r == qr) return upd(c,x),void();pd(c);
	if(ql > mid) Upd(rc,mid+1,r,ql,qr,x);
	else if(qr <= mid) Upd(lc,l,mid,ql,qr,x);
	else Upd(lc,l,mid,ql,mid,x),Upd(rc,mid+1,r,mid+1,qr,x);
	tr[c] = max(tr[lc],tr[rc]);
}
ll Qry(int c,int l,int r,int ql,int qr)
{
	if(l == ql && r == qr) return tr[c];pd(c);
	if(ql > mid) return Qry(rc,mid+1,r,ql,qr);
	if(qr <= mid) return Qry(lc,l,mid,ql,qr);
	return max(Qry(lc,l,mid,ql,mid),Qry(rc,mid+1,r,mid+1,qr));
}
vector<int>q[N];
void solve()
{
	memset(tr,0,sizeof(tr)),memset(lzy,0,sizeof(lzy));
	scanf("%d%d%d%d",&n,&m,&k,&d);n = 0;
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",R+i,L+i,v+i);
		L[i] = R[i] - L[i] + 1;
		pos[++n] = L[i],pos[++n] = R[i]+1;
	}
	sort(pos+1,pos+1+n);
	pos[n+1] = INF;
	for(int i = 1;i <= m;i++)
	{
		L[i] = lower_bound(pos+1,pos+1+n,L[i]) - pos;
		R[i] = lower_bound(pos+1,pos+1+n,R[i]+1) - pos;
		q[R[i]].push_back(i);
	}
	for(int i = 1;i <= n;i++)
	{
		int j = lower_bound(pos+1,pos+1+n,pos[i] - k) - pos - 1;
		for(auto nd:q[i]) Upd(1,0,n,0,L[nd]-1,v[nd]);
		q[i].clear();
		f[i] = Qry(1,0,n,j,i-1);
		Upd(1,0,n,i,i,f[i]);
		Upd(1,0,n,0,i-1,-(pos[i+1] - pos[i]) * d);
	}
	printf("%lld\n",f[n]);
}
int main()
{
	//system("fc run.out run6.ans");
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C,T;scanf("%d%d",&C,&T);
	while(T--) solve();
	return 0;
}