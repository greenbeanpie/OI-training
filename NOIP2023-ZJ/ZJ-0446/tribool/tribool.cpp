#include<bits/stdc++.h>
using namespace std;
int t;
char op[500100];
int u[2][500100];
int final[500100];
int ch[500100];
int cc,n,m;
int ans;
bool flag=false;
int cnt=0;
bool mask[500100];
void dfs(int x){
	if(x==n+1){
		int res=0;
		for(int i=1;i<=n;i++) ch[i]=final[i];
		for(int i=1;i<=m;i++){
			if(op[i]=='+'){
				ch[u[0][i]]=ch[u[1][i]];
			}
			else if(op[i]=='-'){
				if(ch[u[1][i]]==3) ch[u[0][i]]=3;
				if(ch[u[1][i]]==2) ch[u[0][i]]=1;
				if(ch[u[1][i]]==1) ch[u[0][i]]=2;
			}
			else{
				if(op[i]=='T') ch[u[1][i]]=1;
				else if(op[i]=='F') ch[u[1][i]]=2;
				else ch[u[1][i]]=3;
			}
		}
		for(int i=1;i<=n;i++){
			if(ch[i]!=final[i]) return;
			if(final[i]==3) res++;
		}
		if(ans>res) ans=res;
		return ;
	}
	for(int i=1;i<=3;i++){
		final[x]=i;
		dfs(x+1);
	}
	
}
int main(){
	cin.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>cc>>t;
	while(t--){
		cnt=0;
		cin>>n>>m;
		ans=n;
		for(int i=1;i<=m;i++){
			cin>>op[i];
			if(op[i]=='+'||op[i]=='-') cin>>u[0][i],flag=false;
			cin>>u[1][i];
			if(op[i]=='U'){
				if(!mask[u[1][i]])cnt++;
				mask[u[1][i]]=true;
			}
		}
		if(flag){
			cout<<cnt<<"\n";
			continue;
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}