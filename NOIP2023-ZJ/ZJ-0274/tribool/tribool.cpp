#include<bits/stdc++.h>
using namespace std;
const int o=1e5+5;
int n,m,t,T,l[o],r[o],v[o],w[o],ans;
char u[o];
void qwq(int x){
	if (x==n){
		int y=0;
		for (int i=1;i<=n;i++)
			r[i]=l[i];
		for (int i=1;i<=m;i++){
			if (u[i]=='+') r[v[i]]=r[w[i]];
			else if (u[i]=='-'){
				if (r[w[i]]==-1) r[v[i]]=-1;
										else r[v[i]]=1-r[w[i]];
			}
			else{
				if (u[i]=='T') r[v[i]]=1;
				if (u[i]=='F') r[v[i]]=0;
				if (u[i]=='U') r[v[i]]=-1;
			}
		}
		for (int i=1;i<=n;i++)
			if (l[i]!=r[i]) return;
			else if (l[i]==-1) y+=1;
		ans=min(ans,y);
		return;
	}
	for (int i=-1;i<=1;i++)
		l[x+1]=i,qwq(x+1);
	return;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T>>t;
	while (t--){
		cin>>n>>m;
		ans=n;
		if (T==1||T==2){
			for (int i=1;i<=m;i++){
				cin>>u[i]>>v[i];
				if (u[i]=='-'||u[i]=='+') cin>>w[i];
			}
			qwq(0);
			cout<<ans<<"\n";
		}
		if (T==3||T==4){
			int z=0;
			for (int i=1;i<=n;i++)
				l[i]=0;
			for (int i=1;i<=m;i++){
				char x;int y;
				cin>>x>>y;
				if (x=='T') l[y]=1;
				if (x=='F') l[y]=0;
				if (x=='U') l[y]=-1;
			}
			for (int i=1;i<=n;i++)
				if (l[i]==-1) z++;
			cout<<z<<"\n";
		}
	}	
	return 0;
}