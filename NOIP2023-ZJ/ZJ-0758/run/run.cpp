#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int i,j,m,n,t,x,y,v,d,k,c;
map<int,int>mp;
long long ans;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		mp.clear();ans=0;
		cin>>n>>m>>k>>d;
		for(i=1;i<=m;i++){
			cin>>x>>y>>v;
			if(y>k or x-y+1<1) continue;
			ans+=v;
			for(j=x-y+1;j<=x;j++){
				if(!mp[j]) ans--;
				mp[j]=1;
			}
		}
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
