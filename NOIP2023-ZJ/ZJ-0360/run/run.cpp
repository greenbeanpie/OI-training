#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10,inf=1e15;
ll read(){
	ll x=0,sgn=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')sgn*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}
	return x*sgn;
}
ll n,m,c,t,x,y,v,k,d;
ll dp[1010][1010],mx[1010];
struct node{
	ll y,v;
};
ll cnt,pans[100];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	if(c<=9){
		while(t--){
			vector <node> a[1010];
			n=read();m=read();k=read();d=read();
			//cout<<n<<" "<<m<<" "<<k<<" "<<d<<endl;
			for(int i=1;i<=m;i++){
				x=read();y=read();v=read();
				a[x].push_back(node{y,v});
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n;j++)dp[i][j]=-inf,mx[i]=-inf;
			}
			dp[0][0]=0;
			mx[0]=0;
			for(int i=1;i<=n;i++){
				ll tmp=-inf;
				for(int j=1;j<=min(k,1ll*i);j++){
					ll val=0;
					for(int p=0;p<a[i].size();p++){
						if(a[i][p].y<=j)val+=a[i][p].v;
					}
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d+val);
					tmp=max(tmp,dp[i][j]);
					//cout<<dp[i][j]<<" ";
				}
				dp[i][0]=mx[i-1];
				//cout<<dp[i][0]<<endl;
				tmp=max(tmp,dp[i][0]);
				mx[i]=tmp;
			}
			cout<<mx[n]<<endl;
			//pans[++cnt]=mx[n];
		}	
//		for(int i=1;i<=cnt;i++){
//			cout<<pans[i]<<" ";
//		}
	}else if(c==17||c==18){
		while(t--){
			ll ans=0;
			n=read();m=read();k=read();d=read();
			for(int i=1;i<=m;i++){
				x=read();y=read();v=read();
				ll r=x,l=x-y+1;
				if(l>=1){
					if(y*d<v){
						ans+=v-y*d;
					}
				}
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
//T#YMS@4
//1 1
//10 10
//- 9 8
//- 8 6
//- 6 5
//- 5 4
//- 4 3
//+ 3 9
//- 1 2
//+ 2 7
//+ 7 10
//- 10 1
