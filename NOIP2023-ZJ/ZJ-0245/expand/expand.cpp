//I would appreciate it if CCF cound give me 1=
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0),cout.tie(0)
#define pb push_back
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
//#define int long long
using namespace std;
int owo,n,m,q;
int A[500005],B[500005],a[500005],b[500005],c[500005];
int f[2005][2005];
vector<int> ans;
int _nx,_ny,_idx,_vx,_idy,_vy,Q;

struct SGT{
	struct node{
		int l,r,mn,mx;
	}tr[2000005];
	void build(int i,int l,int r){
		tr[i].l=l,tr[i].r=r;
		if(l==r){
			tr[i].mn=tr[i].mx=b[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(ls(i),l,mid),build(rs(i),mid+1,r);
		tr[i].mn=min(tr[ls(i)].mn,tr[rs(i)].mn);
		tr[i].mx=max(tr[ls(i)].mx,tr[rs(i)].mx);
	}
	int query_mn(int i,int l,int r){
		if(tr[i].l>=l&&tr[i].r<=r) return tr[i].mn;
		int mid=(tr[i].l+tr[i].r)>>1,ans=2000000005;
		if(l<=mid) ans=min(ans,query_mn(ls(i),l,r));
		if(mid<r) ans=min(ans,query_mn(rs(i),l,r));
		return ans;
	}
	int query_mx(int i,int l,int r){
		if(tr[i].l>=l&&tr[i].r<=r) return tr[i].mx;
		int mid=(tr[i].l+tr[i].r)>>1,ans=-1;
		if(l<=mid) ans=max(ans,query_mx(ls(i),l,r));
		if(mid<r) ans=max(ans,query_mx(rs(i),l,r));
		return ans;
	}
}sgt;

int solve1(){
	if(a[1]==b[1]) return 0;
	if(a[1]<b[1]){
		for(int i=1;i<=n;i++) c[i]=a[i];
		for(int i=1;i<=m;i++) a[i]=b[i];
		for(int i=1;i<=n;i++) b[i]=c[i];
		swap(n,m);
	}
	
	sgt.build(1,1,m);
	
	int nowr=1;
	for(int i=1;i<=n;i++){
		if(i==1){
			int L=nowr,R=m,res=-1;
			while(L<=R){
				int mid=(L+R)>>1;
				if(sgt.query_mx(1,nowr,mid)<a[i]) res=mid,L=mid+1;
				else R=mid-1;
			}
			nowr=res;
		}
		else{
			int L=1,R=min(nowr+1,m),res=-1;
			int stR=R;
			while(L<=R){
				int mid=(L+R)>>1;
				if(sgt.query_mn(1,mid,stR)<a[i]) res=mid,L=mid+1;
				else R=mid-1;
			}
			if(res==-1) return 0;
			if(res>nowr){
				int st=res;
				L=res,R=m;
				while(L<=R){
					int mid=(L+R)>>1;
					if(sgt.query_mx(1,st,mid)<a[i]) res=mid,L=mid+1;
					else R=mid-1;
				}
			}
			nowr=res;
		}
	}
	
	if(nowr==m) return 1;
	else return 0;
}


int solve(){
	if(a[1]==b[1]) return 0;
	if(a[1]<b[1]){
		for(int i=1;i<=n;i++) c[i]=a[i];
		for(int i=1;i<=m;i++) a[i]=b[i];
		for(int i=1;i<=n;i++) b[i]=c[i];
		swap(n,m);
	}
	memset(f,0,sizeof(f));
	f[1][1]=1;
	for(int i=2;i<=m;i++){
		if(a[1]>b[i]) f[1][i]=1;
		else break;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i-1][j]&&(a[i]>b[j])) f[i][j]=1;
			if(f[i][j-1]&&(a[i]>b[j])) f[i][j]=1;
		}
	}
	return f[n][m];
}

signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	IOS;TIE;
	cin>>owo>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>A[i],a[i]=A[i];
	for(int i=1;i<=m;i++) cin>>B[i],b[i]=B[i];
	if(n<=2000) ans.pb(solve());
	else ans.pb(solve1());
	while(q--){
		cin>>_nx>>_ny;
		for(int i=1;i<=n;i++) a[i]=A[i];
		for(int i=1;i<=m;i++) b[i]=B[i];
		for(int i=1;i<=_nx;i++){
			cin>>_idx>>_vx;
			a[_idx]=_vx;
		}
		for(int i=1;i<=_ny;i++){
			cin>>_idy>>_vy;
			b[_idy]=_vy;
		}
		if(n<=2000) ans.pb(solve());
		else ans.pb(solve1());
	}
	for(auto i:ans) cout<<i;
	cout<<endl;
	return 0;
}

/*
3 1 1 1
9 
8

1 0
1 8
*/
