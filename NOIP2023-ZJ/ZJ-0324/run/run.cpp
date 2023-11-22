#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x7fffffff
const int N(2e5+5);
int n,m,k,d;
int C;
struct node{
	int l,r,v;
}a[N];
bool cmp(const node&a,const node&b){
//	return a.l==b.l?a.r<b.r:a.l<b.l;
	return a.r==b.r?a.l>b.l:a.r<b.r;
}
ll ans;	
int b[N],bn;
ll f[N],cnt[N];
ll get(int L,int R){
	ll res=0;
	for(int i=L;i<=R;++i) {
		res+=cnt[i];
	}
	return res;
}
void dfs(int now,int lian,ll res,int G){
	if(now==n){
		ans=max(ans,res);
		return ;
	}
	while(a[G].r<now) ++G;
	for(int i=G;i<=m;++i) {
		if(a[i].r!=now) break;
		if(now-lian+1<=a[i].l) res+=a[i].v;
	}
	dfs(now+1,0,res,G);
	if(lian<k)dfs(now+1,lian+1,res-d,G);
}
void solve(){
	cin>>n>>m>>k>>d;
	int xx,yy,zz;
	bn=0;
	for(int i=1;i<=m;++i){
		cin>>xx>>yy>>zz;
		if(yy>k||xx-yy+1<1) {i-=1,m-=1;continue;}
		b[++bn]=a[i].l=xx-yy+1;
		b[++bn]=a[i].r=xx;
		a[i].v=zz;
	}
	if(C>=17&&C<=18){//B
		ans=0;
		for(int i=1;i<=m;++i) 
		ans+=max(1ll*a[i].v-1ll*(a[i].r-a[i].l+1)*d,0ll);
		cout<<ans<<endl;
		return ;
	}
	else if(n<=20){
		ans=0;
		dfs(1,1,-d,1);
		dfs(1,0,0,1);
		cout<<ans<<endl;
		return ;
	}
	sort(b+1,b+1+bn);
	bn=unique(b+1,b+1+bn)-b-1;
	sort(a+1,a+1+m,cmp);
	int L,M,R;
	memset(f,0,sizeof f);
	memset(cnt,0,sizeof cnt);
	ans=0;ll res,ttt,G;
	for(int i=1;i<=m;++i){
		res=0;
		M=lower_bound(b+1,b+1+bn,a[i].r-k+1)-b;
		R=lower_bound(b+1,b+1+bn,a[i].r)-b;
		L=lower_bound(b+1,b+1+bn,a[i].l)-b;
		ttt=get(L+1,R);
		for(int j=L;j>=M;--j){
			ttt+=cnt[j];
			G=a[i].v-1ll*d*(b[R]-b[j]+1)+ttt;
			if(b[j]!=b[j-1]+1) G+=f[j-1];
			else if(j!=1)G+=f[j-2];
			res=max(res,G);
		}
		
		ans=max(res,ans);
		for(int j=1;j<=L;++j) cnt[j]+=a[i].v;
		for(int j=R;j<=bn;++j) f[j]=max(f[j],res);
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;cin>>C>>T;
	while(T--) solve();
}