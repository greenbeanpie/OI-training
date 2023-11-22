#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define pb emplace_back
#define fi first
#define se second
typedef pair<ll,ll> P;
ll read(){
	ll x=0, f=1; char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0' && ch<='9') x=x*10+ch-'0', ch=getchar();
	return x*f;
}
ll maxx(ll a,ll b){return a>b?a:b;}
ll minn(ll a,ll b){return a<b?a:b;}
ll c,n,m,q,x[500005],y[500005],maxY[500005],minY[500005],maxX[500005],minX[500005];
ll N,M,X[500005],Y[500005],fd[1000005];
ll p[500005], v[500005], stx[500005], sty[500005], stt;

ll findupper(ll num){
	ll lft=1, rht=N, ans=0;
	while (lft <= rht){
		ll mid = lft + rht >> 1;
		if(minX[mid] >= num) ans = mid, lft = mid + 1;
		else rht = mid - 1;
	}
	return ans;
}

ll tmp[1500005], cnt;
ll get(ll x){
	ll lft=1, rht=cnt, ans=0;
	while (lft <= rht){
		ll mid = lft + rht >> 1;
		if(tmp[mid] <= x) ans = mid, lft = mid + 1;
		else rht = mid - 1;
	}
	return ans;
}
ll check(){
	memset(fd,0,sizeof(fd));
	minX[0] = 2e9; minY[0] = 2e9;
	for(ll i=1;i<=N;i++) minX[i] = minn(minX[i-1], X[i]), maxX[i] = maxx(maxX[i-1], X[i]);
	for(ll i=1;i<=M;i++) minY[i] = minn(minY[i-1], Y[i]), maxY[i] = maxx(maxY[i-1], Y[i]);
	// check x or y
	if(maxX[N] >= maxY[M] || minX[N] >= minY[M]) return 0;
	// check x & y
	ll pt = N;
	for(ll i=1;i<=cnt;i++){
		while(pt>=1 && minX[pt] < i) --pt;
		fd[i] = pt;
	}
	for(ll j=1;j<=M;j++){
		// maxY[j] <= X[i]
		// Y[j] <= minX[i] --> qz
		ll lst = fd[Y[j]];
		// is there X[i] >= maxY[j]?
		if(maxX[lst] >= maxY[j]) return 0;
	}
	
	// check2
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(), n=read(), m=read(), q=read();
	clock_t now = clock();
	for(ll i=1;i<=n;i++) x[i]=read(), tmp[++cnt]=x[i];
	for(ll i=1;i<=m;i++) y[i]=read(), tmp[++cnt]=y[i];
	
	for(ll i=1;i<=q;i++){
		ll kx=read(), ky=read();
		stx[i] = stt;
		while(kx--){ p[++stt]=read(), v[stt]=read(); tmp[++cnt]=v[stt];}
		sty[i] = stt;
		while(ky--){ p[++stt]=read(), v[stt]=read(); tmp[++cnt]=v[stt];}
	}
	stx[q+1]=stt;
//	cerr<<"time: "<<clock()-now<<endl;
	sort(tmp+1,tmp+cnt+1); cnt=unique(tmp+1,tmp+cnt+1)-(tmp+1);
	for(ll i=1;i<=n;i++) x[i]=get(x[i]);
	for(ll i=1;i<=m;i++) y[i]=get(y[i]);
//	cerr<<"time: "<<clock()-now<<endl;
	for(ll i=1;i<=stt;i++) v[i]=get(v[i]);
	
	
//	cerr<<"time: "<<clock()-now<<endl;
	N=n,M=m;
	for(ll i=1;i<=n;i++) X[i]=x[i];
	for(ll i=1;i<=m;i++) Y[i]=y[i];
	if(X[1] > Y[1]) {
		swap(X, Y);
		swap(N, M);
	}
	ll t1 = check();
	reverse(X+1, X+N+1);
	reverse(Y+1, Y+M+1);
	printf("%d",(t1 & check()));
	
	for(ll i=1;i<=q;i++){
		N=n,M=m;
		for(ll j=1;j<=n;j++) X[j]=x[j];
		for(ll j=1;j<=m;j++) Y[j]=y[j];
		for(ll j=stx[i]+1; j<=sty[i]; j++) X[p[j]] = v[j];
		for(ll j=sty[i]+1; j<=stx[i+1]; j++) Y[p[j]] = v[j];
		
		if(X[1] > Y[1]) {
			swap(X, Y);
			swap(N, M);
		}
		ll t1 = check();
		
		reverse(X+1, X+N+1);
		reverse(Y+1, Y+M+1);
		printf("%d", (t1 & check()));
	}
	
	return 0;
}