#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,d;
namespace BF{
	ll sm[100050],F[100050];
	int ptr[100050],x[100050],y[100050],v[100050],R[100050],RR[100050],To[100050];
	vector<pair<int,int> > vec[100050];
	inline void solve(){
		map<int,int> mp;
		memset(F,0,sizeof(F));
		memset(R,0,sizeof(R));
		memset(RR,0,sizeof(RR));
		memset(To,0,sizeof(To));
		for(int i=1;i<=m;++i)
			cin>>x[i]>>y[i]>>v[i],mp[x[i]]=1;
		int sz1=0;
		for(auto &i:mp)
			R[++sz1]=i.first,i.second=sz1;
		map<int,int> g;
		for(int i=1;i<=m;++i)
			vec[mp[x[i]]].push_back(make_pair(y[i],v[i])),g[x[i]-y[i]+1]=1;
		for(int i=1;i<=sz1;++i){
			ptr[i]=vec[i].size();sm[i]=0;
			sort(vec[i].begin(),vec[i].end());
			for(auto j:vec[i])
				sm[i]+=j.second;
		}
		int sz2=0;
		for(auto &i:g)
			RR[++sz2]=i.first,i.second=sz2;
		for(int i=1,nw=1;i<=sz1;++i){
			while(nw<=sz2&&RR[nw]<=R[i]+1)nw++;
			To[i]=nw;
		}
		for(int i=1,nw=1;i<=sz2;++i){
			F[i]=max(F[i-1],F[i]);
			while(nw<=sz1&&R[nw]<RR[i])nw++;
			ll ans=0;
			for(int j=nw,dis;j<=sz1;++j){
				if((dis=R[j]-RR[i]+1)>k)break;
				while(ptr[j]&&vec[j][ptr[j]-1].first>dis)
					sm[j]-=vec[j][--ptr[j]].second;ans+=sm[j];
				F[To[j]]=max(F[To[j]],F[i]+ans-1ll*dis*d);
			}
		}
		for(int i=1;i<=sz1;++i)
			vec[i].clear();
		cout<<max(F[sz2],F[sz2+1])<<'\n';
	}
}
namespace SubB{
	ll S[102000],F[102000];
	int x[100050],y[100050],v[100050];
	inline void solve(){
		x[m+1]=y[m+1]=0;
		for(int i=1;i<=m;++i){
			cin>>x[i]>>y[i]>>v[i];
			if(k>=y[i]){
				S[i]=v[i]-1ll*y[i]*d;
			}else S[i]=-1e9;
		}
		memset(F,0,sizeof(F));
		for(int i=1;i<=m;++i){
			F[i]=max(F[i-1],F[i]);
			F[i+1]=max(F[i+1],F[i]+S[i]);
		}
		cout<<max(max(F[m],F[m+1]),F[m+2])<<'\n';
	}
}int c,t;
inline void solve(){
	cin>>n>>m>>k>>d;
	if(c==17||c==18)SubB::solve();
	else BF::solve();
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
}