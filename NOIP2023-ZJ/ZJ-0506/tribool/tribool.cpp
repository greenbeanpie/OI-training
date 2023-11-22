#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int i,C,T,ans,n,m,a[100010],b[100010];
char st[100010],sf[100010],df[100010];
char qf(char ch){
	if(ch=='T') return 'F';
	if(ch=='F') return 'T';
	return 'U';
}
bool work(){
	int i;
	for(i=1;i<=n;i++) df[i]=sf[i];
	for(i=1;i<=m;i++)
	    if(st[i]=='+') df[a[i]]=df[b[i]];
	    else if(st[i]=='-') df[a[i]]=qf(df[b[i]]);
	    else df[a[i]]=st[i];
	for(i=1;i<=n;i++)
	    if(df[i]!=sf[i]) return 0;
	return 1;
}
inline void dfs(int t,int ox){
	if(ox>=ans) return;
	if(t>n){
		if(work()) ans=ox; return;
	}
	sf[t]='T'; dfs(t+1,ox);
	sf[t]='F'; dfs(t+1,ox);
	sf[t]='U'; dfs(t+1,ox+1);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>C>>T;
	if(C<3){
		while(T--){
			cin>>n>>m; ans=n;
			for(i=1;i<=m;i++){
				cin>>st[i];
				if(st[i]=='+' || st[i]=='-') cin>>a[i]>>b[i];
				else cin>>a[i];
			}
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	if(2<C && C<5){
		while(T--){
			cin>>n>>m; ans=0;
			for(i=1;i<=n;i++) sf[i]='T';
			for(i=1;i<=m;i++){
				cin>>st[i]>>a[i];
				sf[a[i]]=st[i];
			}
			for(i=1;i<=n;i++) ans+=(sf[i]=='U');
			cout<<ans<<"\n";
		}
	}
	if(4<C && C<7){
		while(T--){
			cin>>n>>m;
			for(i=1;i<=n;i++) sf[i]='T';
			for(i=1;i<=m;i++){
				cin>>st[i];
				if(st[i]=='+') cin>>a[i]>>b[i];
				else cin>>a[i];
			}
			while(1){
				for(i=1;i<=n;i++) df[i]=sf[i];
				for(i=1;i<=m;i++){
					if(st[i]=='+') sf[a[i]]=sf[b[i]];
					else sf[a[i]]='U';
				}
				int fl=0;
				for(i=1;i<=n;i++)
				    if(df[i]!=sf[i]){fl=1; break;}
				if(!fl) break;
			}
			for(i=1;i<=n;i++) ans+=(sf[i]=='U');
			cout<<ans<<"\n";
		}
	}
	return 0;
}