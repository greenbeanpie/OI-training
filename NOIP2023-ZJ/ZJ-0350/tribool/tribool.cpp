#include<bits/stdc++.h>
using namespace std;
const int TT=1e6,FF=-1e6,UU=1e7;
int id,T,n,m,ans,x,y,a[100005],b[100005];
vector<int>son[100005];
vector<int>fan[100005];
int q[100005],f[100005],len,st;
bool v[100005],fl,g;
char c;
void dfs(int now,int is){
	if(b[now])return;
	b[now]=is;
	for(int i:son[now])
		dfs(i,a[i]/abs(a[i])*is);
}
bool get(int now){
	if(f[now]){
		st=now;
		for(int i=f[now];i<=len;i++)fl^=(a[q[i]]<0);
		return 1;
	}
	q[++len]=now,f[now]=len;
	for(int i:fan[now])
		if(get(i))return 1;
	return 0;
}
void solve(){
	cin>>n>>m,ans=0;
	for(int i=1;i<=n;i++)a[i]=i,f[i]=b[i]=0,son[i].clear(),fan[i].clear();
	for(int i=1;i<=m;i++){
		cin>>c>>x;
		if(c=='+')cin>>y,a[x]=a[y];
		else if(c=='-')cin>>y,a[x]=-a[y];
		else{
			if(c=='T')a[x]=TT;
			else if(c=='F')a[x]=FF;
			else a[x]=UU;
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=TT&&a[i]!=FF&&a[i]!=UU&&a[i]!=-UU)
			son[abs(a[i])].push_back(i),fan[i].push_back(abs(a[i]));
	for(int i=1;i<=n;i++)
		if(!b[i]){if(a[i]==TT||a[i]==FF||a[i]==UU||a[i]==-UU)dfs(i,a[i]);}
	for(int i=1;i<=n;i++)
		if(!b[i]){
			fl=0,len=0,g=get(i);
			if(fl)dfs(st,UU);
			else dfs(st,TT);
		}
	for(int i=1;i<=n;i++)
		if(b[i]==UU||b[i]+UU==0)ans++;
	cout<<ans<<'\n';
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>id>>T;
	while(T--)solve();
}
