#include<bits/stdc++.h>
#define int long long
#define lb (i&(-i))
using namespace std;
const int N=2e5+10,M=998244353;
int n,ans,dp[N],t[N];
struct node{
	int a,b,id;
	bool operator<(const node&c)const{
		return a<c.a;
	}
}a[N],b[N];
void add(int x,int d){
	for(int i=x;i<=n;i+=lb)
		t[i]=max(t[i],d);
	return;
}
void del(int x){
	for(int i=x;i<=n;i+=lb)
		t[i]=0;
	return;
}
int query(int x){
	int s=0;
	for(int i=x;i;i-=lb)
		s=max(s,t[i]);
	return s;
}
void solve(int l,int r){
	if(l==r){
		dp[l]++;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	for(int i=l;i<=r;i++)
		b[i]=a[i];
	sort(b+l,b+1+r);
	for(int i=l;i<=r;i++)
		if(b[i].id<=mid)
			add(b[i].b,dp[b[i].id]);
		else
			dp[b[i].id]=max(dp[b[i].id],query(b[i].b));
	for(int i=l;i<=r;i++)
		if(b[i].id<=mid)
			del(b[i].b);
	solve(mid+1,r);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].a;
	for(int i=1;i<=n;i++)
		cin>>a[i].b,
		a[i].id=i;
	solve(1,n);
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}

