#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mk make_pair
#define debug cout<<"------------------------\n";
#define fi first
#define se second
#define ls s*2
#define rs s*2+1
#define mid (l+r)/2
#define tol ls,l,mid
#define tor rs,mid+1,r
using namespace std;
const int M=100010;
int id,T;
int n,m;
char c[M];
int a[M],b[M];
int x[M],y[M];
int ans1=0;
bool ed=0;
bool check(){
	for(int i=1;i<=n;++i) y[i]=x[i];
	for(int i=1;i<=m;++i){
		if(c[i]=='T') y[a[i]]=1;
		else if(c[i]=='U') y[a[i]]=0;
		else if(c[i]=='F') y[a[i]]=-1;
		else if(c[i]=='+') y[a[i]]=y[b[i]];
		else if(c[i]=='-') y[a[i]]=-y[b[i]];
	}
	for(int i=1;i<=n;++i)
		if(x[i]!=y[i]) return 0;
	return 1;
}
void dfs(int s,int sum){
	if(ed) return ;
	if(s==n+1){
		if(check()) ans1=sum,ed=1;
		return ;
	}
	x[s]=1;
	dfs(s+1,sum);
	x[s]=-1;
	dfs(s+1,sum);
	x[s]=0;
	dfs(s+1,sum+1);
}
void solve1(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>c[i];
		if(c[i]=='+'||c[i]=='-') scanf("%d%d",&a[i],&b[i]);
		else scanf("%d",&a[i]);
	}
	ed=0;
	ans1=0;
	dfs(1,0);
	cout<<ans1<<endl;
}
void solve2(){
	cin>>n>>m;
	int ans2=0;
	for(int i=1;i<=n;++i) x[i]=1;
	for(int i=1;i<=m;++i){
		cin>>c[i];
		scanf("%d",&a[i]);
		if(c[i]=='U') x[a[i]]=0;
		else x[a[i]]=1;
	}
	for(int i=1;i<=n;++i)
		if(x[i]==0) ++ans2;
	cout<<ans2<<endl;
}
int f[M];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void solve3(){
	cin>>n>>m;
	int ans3=0;
	for(int i=1;i<=n;++i) x[i]=1;
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i){
		cin>>c[i];
		if(c[i]=='U') {
			scanf("%d",&a[i]);
			
		} else {
			scanf("%d%d",&a[i],&b[i]);
			
		}
	}
	cout<<ans3<<endl;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>id>>T;
	while(T--){
		if(id<=2) solve1();
		else if(id<=4) solve2();
		else if(id<=10) solve3();
	}
	return 0;
}
