#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010,inf=1e15;int dp2[N],mxx[N],id[N];
int c,T,n,k,m,d,dp[N][N],cl[N][N],xx[N],yy[N],vv[N];
bool cmp(int x,int y){
	if(yy[x]!=yy[y])return yy[x]<yy[y];
	return xx[x]<xx[y];
}int ip[N],tot;
void add(int x){
	int ps=0;
	for(int i=1;i<=tot;i++)
		if(xx[ip[i]]<xx[x])ps=i;
	for(int i=tot+1;i>=ps+1;i--)
		ip[i]=ip[i-1];
	ip[ps+1]=x;tot++;
	return;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cin>>c>>T;
	if(c<=9){
		while(T--){
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++){
				int x,y,v;
				cin>>x>>y>>v;
				if(y<=k){
					cl[x][y]+=v;
				}
			}
			for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				cl[i][j]+=cl[i][j-1];
			int ans=0;
			for(int i=0;i<=n;i++)
				for(int j=0;j<=k;j++)
					dp[i][j]=-inf;
			dp[0][0]=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<=min(k,i);j++){
					if(j<k){
						int yu=dp[i][j]+cl[i+1][j+1]-d;
						dp[i+1][j+1]=max(dp[i+1][j+1],yu);
						ans=max(ans,yu);
					}dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
					ans=max(ans,dp[i+1][0]);
				}
			cout<<ans<<"\n";
			for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				cl[i][j]=0;
		}
		return 0;
	}if(10<=c&&c<=11){
		while(T--){
			cin>>n>>m>>k>>d;tot=0;
			for(int i=1;i<=m;i++){
				cin>>xx[i]>>yy[i]>>vv[i];
				int c=xx[i]-yy[i]+1,d=xx[i];
				xx[i]=c;yy[i]=d;
				id[i]=i;
			}
			sort(id+1,id+m+1,cmp);
			for(int i=1;i<=m;i++)
				dp2[i]=-inf;
			yy[0]=-100;
			int ans=0;
			for(int i=1;i<=m;i++){
				add(id[i]);
				int nw=0,cn=i;
				for(int j=tot;j;j--){
					int len=yy[id[i]]-xx[ip[j]]+1;
					if(len>k)break;
					nw+=vv[ip[j]];
					while(yy[id[cn]]>xx[ip[j]]-2)
						cn--;
					dp2[i]=max(dp2[i],mxx[cn]-len*d+nw);
				}
				mxx[i]=max(mxx[i-1],dp2[i]);
				ans=max(ans,dp2[i]);
			}cout<<ans<<"\n";
		}return 0;
	}return 0;
}