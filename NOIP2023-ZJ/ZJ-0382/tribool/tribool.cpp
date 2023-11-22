#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char opt;
int x,n,i,j,k,l,o,p,c,T,m,y,vis[N],ans,in[N],val[N],tt[N];
char op;
struct qs{
	char opt;
	int x,y;
}q[N];
map<char,int>mp;
vector<int>g[N];
inline int check(){
	int i,org[N];
	for(i=1;i<=n;i++)
	  org[i]=val[i];
	for(i=1;i<=m;i++){
		if(q[i].opt=='+')
			val[q[i].x]=val[q[i].y];
		else if(q[i].opt=='-'){
			if(val[q[i].y]==2)val[q[i].x]=2;
			else val[q[i].x]=val[q[i].y]^1;
		}
		else{
			val[q[i].x]=mp[q[i].opt];
		}
	}
	for(i=1;i<=n;i++)
	  if(val[i]!=org[i])return 0;
	return 1;
}
inline int dfs(int x){
	if(vis[x])return val[x];
	vis[x]=1;
	if(tt[x]==x){
	   val[x]=0;
	   return 0;	
	}
	if(tt[x]==0)return val[x];
	val[x]=dfs(tt[x]);
	return val[x];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	mp['T']=1;mp['F']=0;mp['U']=2;
	cin>>c>>T;
	if(c<=2){
		while(T--){
			cin>>n>>m;
			ans=0x3f3f3f3f;
			int maxx=1;
			for(i=1;i<=n;i++)
				maxx*=3;
			for(i=1;i<=m;i++){
			    cin>>q[i].opt;
			    cin>>q[i].x;
			    if(q[i].opt=='+'||q[i].opt=='-')
					cin>>q[i].y;
			}
		    for(i=0;i<=maxx;i++){
		    	int t=i,tmp=0;
		    	for(j=1;j<=n;j++){
		    		if(t==0)val[j]=0;
		    		val[j]=t%3;
		    		if(t%3==2)tmp++;
		    		t/=3;
				}
				if(check())ans=min(ans,tmp);
			}
		    cout<<ans<<'\n';
		}
		return 0;
	}
	if(c<=4){
		while(T--){
			cin>>n>>m;
			ans=0;
			for(i=1;i<=n;i++)
		  		val[i]=0;
			for(i=1;i<=m;i++){
				cin>>op>>x;
				val[x]=mp[op];
			}
			for(i=1;i<=n;i++){
				if(val[i]==2)ans++;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c<=6){
		while(T--){
			ans=0;
			cin>>n>>m;
			for(i=1;i<=n;i++)
			  in[i]=val[i]=vis[i]=tt[i]=0;
			for(i=1;i<=m;i++){
				cin>>op>>x;
				if(op=='U'){
					val[x]=2;
					tt[x]=x;
				}
				else{
					cin>>y;
				    tt[x]=tt[y];
				    val[x]=val[tt[x]];
				}
			}
			for(i=1;i<=n;i++)
				if(val[i]==2)ans++;
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
}
/*
1 3
3 3
- 2 1
‐ 3 2
+ 1 3
3 3
‐ 2 1
‐ 3 2
‐ 1 3
2 2
T 2
U 2
*/