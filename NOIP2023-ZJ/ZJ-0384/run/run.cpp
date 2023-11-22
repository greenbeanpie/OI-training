#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
int T,n,m,k,d,c;
int dp[N][N];
int sum[N][N],s[N][N];
int maxn[N*4];
void pushup(int o){
	maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
}
void upd(int o,int l,int r,int pos,int k){
	if(l==r){
		maxn[o]=max(maxn[o],k);
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid)	upd(o<<1,l,mid,pos,k);
	else	upd(o<<1|1,mid+1,r,pos,k);
	pushup(o);
}
int check(int o,int l,int r,int x,int y){
	if(x>y)	return 0;
	if(x<=l&&r<=y){
		return maxn[o];
	}
	int ans=0,mid=l+r>>1;
	if(x<=mid)	ans=max(ans,check(o<<1,l,mid,x,y));
	if(y>mid)	ans=max(ans,check(o<<1|1,mid+1,r,x,y));
	return ans;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		memset(maxn,0,sizeof(maxn));
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)	sum[i][j]=s[i][j]=0;
		}
		while(m--){
			int x,y,d;
			scanf("%lld%lld%lld",&x,&y,&d);
			if(x-y+1>0)	sum[x][x-y+1]+=d;
		} 
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				sum[i][j]+=sum[i][j+1];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				s[i][j]=s[i-1][j]+sum[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				if(j+k-1<i)	break;
				int tot=s[i][j]-s[j-1][j];
				dp[i][j]=-d*(i-j+1)+tot;
				int Ma=check(1,1,n,1,j-2); 
				dp[i][j]+=Ma;
				upd(1,1,n,i,dp[i][j]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,maxn[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
1 1
3 2 2 1
2 2 4
3 2 3
*/
