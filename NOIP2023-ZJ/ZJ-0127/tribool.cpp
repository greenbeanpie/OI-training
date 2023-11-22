#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define MP make_pair
#define pii pair<int,int>
#define pil pair<int,ll>
using namespace std;
typedef long long ll;
constexpr int N=100005;

struct node{
	int op,x,y;
}b[N];
int Cas,T,n,m,ans,a[N<<1],aa[N],fa[N<<1];
pii q[N];
int trans(char ch){
	if(ch=='T')return 1;
	if(ch=='F')return 0;
	if(ch=='U')return 2;
}
void solve2(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++)a[i]=0;
	for(int i=1;i<=m;i++){
		char op[3];
		cin>>op;
		if(op[0]=='U'){
			int x;cin>>x;
			a[x]=-1;q[i]=MP(x,0);
		}
		else{
			int x,y;cin>>x>>y;
			a[x]=a[y];q[i]=MP(x,y);
		}
	}
	while(1){
		int pre=0;
		for(int i=1;i<=n;i++)pre+=(a[i]==-1);
		for(int i=1;i<=m;i++){
			int x=q[i].fi,y=q[i].se;
			if(!y)a[x]=-1;
			else a[x]=a[y];
		}
		ans=0;
		for(int i=1;i<=n;i++)ans+=(a[i]==-1);
		if(ans==pre)break;
	}
	cout<<ans<<'\n';
}
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++)aa[i]=a[i];
		for(int i=1;i<=m;i++){
			int x=b[i].x,y=b[i].y;
			if(b[i].op==0)aa[x]=y;
			else if(b[i].op==1)aa[x]=aa[y];
			else aa[x]=(aa[y]==2?2:(aa[y]^1));
		}
		bool flg=1;int cnt=0;
		for(int i=1;i<=n&&flg;i++)flg&=(aa[i]==a[i]),cnt+=(a[i]==2);
		if(flg)ans=min(ans,cnt);
		return;
	}
	for(int i=0;i<3;i++){a[x]=i;dfs(x+1);a[x]=0;}
}
void solve0(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		char op[3];cin>>op;
		if(op[0]=='+'){
			int x,y;cin>>x>>y;
			b[i]=(node){1,x,y};
		}
		else if(op[0]=='-'){
			int x,y;cin>>x>>y;
			b[i]=(node){2,x,y};
		}
		else{
			int x;cin>>x;
			b[i]=(node){0,x,trans(op[0])};
		}
	}
	ans=n;
	dfs(1);
	cout<<ans<<'\n';
}
void solve1(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++)a[i]=0;
	for(int i=1;i<=m;i++){
		char op[3];cin>>op;
		int x;cin>>x;
		a[x]=trans(op[0]);
	}
	for(int i=1;i<=n;i++)ans+=(a[i]==2);
	cout<<ans<<'\n';
}
int find(int x){return (x==fa[x]?x:fa[x]=find(fa[x]));}
void merge(int x,int y){fa[find(x)]=find(y);}
void solve3(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		char op[3];cin>>op;
		if(op[0]=='+'){
			int x,y;cin>>x>>y;
			b[i]=(node){1,x,y};
		}
		else if(op[0]=='-'){
			int x,y;cin>>x>>y;
			b[i]=(node){2,x,y};
		}
	}
	for(int i=1;i<=n+n;i++)a[i]=i;
	while(1){
		int pre=0;
		iota(fa+1,fa+n*2+1,1);
		for(int i=1;i<=n;i++)pre+=(a[i]==-1);
		for(int i=1;i<=m;i++){
			int x=b[i].x,y=b[i].y;
			if(b[i].op==1)a[x]=a[y];
			else a[x]=(a[y]==-1?-1:(a[y]>n?a[y]-n:a[y]+n));
		}
		for(int i=1;i<=n;i++){
			if(a[i]==-1)continue;
			if(a[i]<=n)merge(i,a[i]),merge(i+n,a[i]+n);
			else merge(i,a[i]),merge(i+n,a[i]-n);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=-1&&find(i)==find(i+n))a[i]=a[i+n]=-1;
			ans+=(a[i]==-1);
		}
		if(ans==pre)break;
	}
	cout<<ans<<'\n';
}
void solve4(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		char op[3];cin>>op;
		if(op[0]=='+'){
			int x,y;cin>>x>>y;
			b[i]=(node){1,x,y};
		}
		else if(op[0]=='-'){
			int x,y;cin>>x>>y;
			b[i]=(node){2,x,y};
		}
		else{
			int x;cin>>x;
			b[i]=(node){0,x,trans(op[0])};
		}
	}
	for(int i=1;i<=n+n;i++)a[i]=i;
	while(1){
		int pre=0;
		iota(fa+1,fa+n*2+1,1);
		for(int i=1;i<=n;i++)pre+=(a[i]==-1);
		for(int i=1;i<=m;i++){
			int x=b[i].x,y=b[i].y;
			if(b[i].op==0){
				if(y==2)a[x]=a[x+n]=-1;
			}
			else if(b[i].op==1)a[x]=a[y];
			else a[x]=(a[y]==-1?-1:(a[y]>n?a[y]-n:a[y]+n));
		}
		for(int i=1;i<=n;i++){
			if(a[i]==-1)continue;
			if(a[i]<=n)merge(i,a[i]),merge(i+n,a[i]+n);
			else merge(i,a[i]),merge(i+n,a[i]-n);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=-1&&find(i)==find(i+n))a[i]=a[i+n]=-1;
			ans+=(a[i]==-1);
		}
		if(ans==pre)break;
	}
	cout<<ans<<'\n';
}
void solve(){
	if(Cas==1||Cas==2)solve0();
	else if(Cas==3||Cas==4)solve1();
	else if(Cas==5||Cas==6)solve2();
	else if(Cas==7||Cas==8)solve3();
	else solve4();
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>Cas>>T;
	while(T--)solve();
	return 0;
}