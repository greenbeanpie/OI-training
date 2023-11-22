#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,t;
int n,m,ans;
char ch[4];
char x[100005];
char y[100005];
char s[100005][4];
void dfs(int num){
	if(num==n+1){
		int sum=0;
		for(int i=1;i<=m;i++){
			if(s[i][1]=='+') x[s[i][2]-'0']=x[s[i][3]-'0'];
			else if(s[i][1]=='-'){
				if(x[s[i][3]-'0']=='T') x[s[i][2]-'0']='F';
				else if(x[s[i][3]-'0']=='F') x[s[i][2]-'0']='T';
				else x[s[i][2]-'0']='U';
			}
			else x[s[i][2]-'0']=s[i][1];
		}
		for(int i=1;i<=n;i++){
			if(x[i]!=y[i]) return ;
			if(x[i]=='U') sum++;
		}
		ans=min(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		y[num]=x[num]=ch[i];
		dfs(num+1);
	}
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	ch[1]='T',ch[2]='U',ch[3]='F';
	while(t--){
		cin>>n>>m;
		ans=n;
		if(c==1||c==2){
			for(int i=1;i<=m;i++){
				cin>>s[i][1]>>s[i][2];
				if(s[i][1]=='+'||s[i][1]=='-') cin>>s[i][3];
			}
			dfs(1);
			cout<<ans<<'\n';
			continue;
		}
		
		if(c==3||c==4){
			for(int i=1;i<=m;i++){
				char a;cin>>a;int b;cin>>b;
				x[b]=a;
			}
			for(int i=1;i<=n;i++) if(x[i]=='U') ans++;
			cout<<ans;
			continue;
		}
	}
	return 0;
}

