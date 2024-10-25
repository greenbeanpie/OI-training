#include<bits/stdc++.h>
using namespace std;
int n,a[105],c[105],b[105],f[1005],hh[105],ans;
bool vis[105];
vector<int>gg;
inline void g(int x){
	memset(vis,0,sizeof vis);
	memset(c,0,sizeof c);int res=0;
	for(int i=1;i<=x;i++)b[i]=a[i];
	for(int i=1;i<=x;i++){
		if(vis[f[i]])continue;
		int y=b[f[i]]-c[f[i]];
		res+=y;//cout<<"debug::"<<y<<'\n';
		vis[f[i]]=true;int r=b[f[i]]/2;
		for(int j=f[i]+1;j<=x;j++){
//			cout<<"fd:: "<<j<<' '<<r<<'\n';
			if(r<b[j]-c[j]&&!vis[j]){
				c[j]+=r;break;
			}
			if(!vis[j])r/=2,vis[j]=true;
		}
	}hh[x]=min(hh[x],res);
}
signed main(){
	freopen("qigong.in","r",stdin);
	freopen("qigong.out","w",stdout);
	cin>>n;int p=1;
	memset(hh,0x3f,sizeof hh);
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	if(n<=10){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)f[j]=j;
			do{
				g(i);
			}while(next_permutation(f+1,f+i+1));
			cout<<hh[i]<<' ';
		}return 0;
	}int ans=0;
	for(int x=1;x<=n;x++){
		if(c[x]>=a[x]){
			cout<<ans<<' ';
			continue;
		}ans+=a[x]-c[x];
		if(a[x]==2)c[x+1]++;cout<<ans<<' ';
	}
}
