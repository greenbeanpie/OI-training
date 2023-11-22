#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1000;
int n,m,ans,s[N][2],c,t;
pair<int,bool> ff[N];// 0=T -1=F -2=U
pair<int,bool> f(int x){
	if(x<=0) return make_pair(x,1);
	if(ff[x].first==x) return ff[x];
	bool p=ff[x].second;
	ff[x]=f(ff[x].first);
	if(p==0) ff[x].second=!ff[x].second;
	return ff[x];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++) s[i][0]=0,s[i][1]=0;
		for(int i=1;i<=n;i++) ff[i]=make_pair(i,1);
		for(int i=1;i<=m;i++){
			char c;
			int xi,xj;
			cin>>c>>xi;
			if(c=='+'){
				cin>>xj;
				int u=f(xj).first;
				bool v=(ff[xj].second);
				ff[xi]=make_pair(u,v);
			}
			if(c=='-'){
				cin>>xj;
				int u=f(xj).first;
				bool v=!(ff[xj].second);
				ff[xi]=make_pair(u,v);
			}
			if(c=='T') ff[xi]=make_pair(0,1);
			if(c=='F') ff[xi]=make_pair(-1,1);
			if(c=='U') ff[xi]=make_pair(-2,1);
		}
		for(int i=1;i<=n;i++) f(i);
		for(int i=1;i<=n;i++){
			if(ff[i].first<=0){
				if(ff[i].first==-2) ans++;
				continue;
			}
			s[ff[i].first][ff[i].second]++;
		}
		for(int i=1;i<=n;i++){
			if(s[i][1]+s[i][0]==0) continue;
			if(ff[i].first<=0){
				if(ff[i].first==-2) ans+=s[i][1]+s[i][0];
				continue;
			}
			if(ff[i].second==0) ans+=s[i][1]+s[i][0];
		}
		cout<<ans<<endl;		
	}

	return 0;
}
